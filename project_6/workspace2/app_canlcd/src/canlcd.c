#include <stdio.h>
#include "xparameters.h"
#include "xcanps.h"      // PS CAN Driver
#include "xiic.h"        // AXI IIC Driver
#include "xil_printf.h"
#include "sleep.h"

// Hardware Definitions - Using BASEADDR to avoid "Undeclared ID" errors
#define CAN_BASEADDR      XPAR_XCANPS_0_BASEADDR
#define IIC_BASEADDR      XPAR_XIIC_0_BASEADDR
#define IIC_SLAVE_ADDR    0x27  

XCanPs CanInstance;
XIic IicInstance;

// --- LCD DRIVER FUNCTIONS ---

void lcd_send_internal(uint8_t data, uint8_t flags) {
    uint8_t up = (data & 0xF0) | flags | 0x08; // 0x08 is Backlight ON
    uint8_t lo = ((data << 4) & 0xF0) | flags | 0x08;
    uint8_t buf[4] = { (up | 0x04), up, (lo | 0x04), lo }; // 0x04 is EN Pulse

    for(int i = 0; i < 4; i++) {
        XIic_Send(IIC_BASEADDR, IIC_SLAVE_ADDR, &buf[i], 1, XIIC_STOP);
    }
}

void lcd_command(uint8_t cmd) { lcd_send_internal(cmd, 0); }
void lcd_data(uint8_t data)    { lcd_send_internal(data, 0x01); } // 0x01 is RS

void lcd_init() {
    usleep(50000);
    lcd_command(0x33);
    lcd_command(0x32);
    lcd_command(0x28);
    lcd_command(0x0C);
    lcd_command(0x01);
    usleep(5000);
}

void lcd_putstr(char *str) {
    while (*str) lcd_data(*str++);
}

// --- MAIN APPLICATION ---

int main() {
    XCanPs_Config *CanConfig;
    XIic_Config *IicConfig;
    int Status;
    u32 TxFrame[8];
    char lcd_msg[16];

    xil_printf("--- System Starting ---\r\n");

    // 1. Initialize AXI IIC using Base Address
    IicConfig = XIic_LookupConfig(IIC_BASEADDR);
    if (IicConfig == NULL) return XST_FAILURE;
    
    Status = XIic_CfgInitialize(&IicInstance, IicConfig, IicConfig->BaseAddress);
    if (Status != XST_SUCCESS) return XST_FAILURE;

    // 2. Initialize LCD
    lcd_init();
    lcd_putstr("CAN Terminal");

    // 3. Initialize PS CAN using Base Address (FIXES THE ERROR)
    CanConfig = XCanPs_LookupConfig(CAN_BASEADDR);
    if (CanConfig == NULL) return XST_FAILURE;

    Status = XCanPs_CfgInitialize(&CanInstance, CanConfig, CanConfig->BaseAddr);
    if (Status != XST_SUCCESS) return XST_FAILURE;

    // 4. CAN Setup (500kbps)
    XCanPs_EnterMode(&CanInstance, XCANPS_MODE_CONFIG);
    XCanPs_SetBaudRatePrescaler(&CanInstance, 9);
    XCanPs_SetBitTiming(&CanInstance, 0, 3, 14);
    XCanPs_EnterMode(&CanInstance, XCANPS_MODE_NORMAL);

    // Prepare Frame (ID 0x123)
    TxFrame[0] = (u32)XCanPs_CreateIdValue(0x123, 0, 0, 0, 0);
    TxFrame[1] = (u32)XCanPs_CreateDlcValue(8);
    TxFrame[2] = 0xDEADBEEF;

    while(1) {
        Status = XCanPs_Send(&CanInstance, TxFrame);
        
        lcd_command(0x01); // Clear Screen
        usleep(2000);

        if (Status == XST_SUCCESS) {
            static int count = 0;
sprintf(lcd_msg, "ID:123 Val:%d", count++);
lcd_putstr(lcd_msg);
            xil_printf("CAN Sent\r\n");
        } else {
            lcd_putstr("CAN Error");
            xil_printf("CAN Fail\r\n");
        }

        sleep(1);
    }
    return 0;
}