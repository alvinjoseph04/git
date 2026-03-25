#include <stdio.h>
#include "xparameters.h"
#include "xcanps.h"      // PS CAN Driver
#include "xiic.h"        // AXI IIC Driver
#include "xil_printf.h"  // For Serial Monitor (UART)
#include "sleep.h"

// Hardware Definitions
#define CAN_BASEADDR      XPAR_XCANPS_0_BASEADDR
#define IIC_BASEADDR      XPAR_XIIC_0_BASEADDR
#define IIC_SLAVE_ADDR    0x27  // Common LCD address (or 0x3F)
#define UART_BASEADDR      XPAR_UART_0_BASEADDR

// LCD Control Bits
#define LCD_RS 0x01
#define LCD_EN 0x04
#define LCD_BL 0x08

XCanPs CanInstance;
XIic IicInstance;

// --- LCD DRIVER LOGIC ---
void lcd_send_internal(uint8_t data, uint8_t flags) {
    uint8_t up = (data & 0xF0) | flags | LCD_BL;
    uint8_t lo = ((data << 4) & 0xF0) | flags | LCD_BL;
    uint8_t buf[4] = { (up | LCD_EN), up, (lo | LCD_EN), lo };

    for(int i = 0; i < 4; i++) {
        XIic_Send(IIC_BASEADDR, IIC_SLAVE_ADDR, &buf[i], 1, XIIC_STOP);
    }
}

void lcd_command(uint8_t cmd) { lcd_send_internal(cmd, 0); }
void lcd_data(uint8_t data)    { lcd_send_internal(data, LCD_RS); }

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
    char display_msg[20];
    int tx_count = 0;

    // 1. Initial Serial Monitor Message
    xil_printf("\r\n***************************************\r\n");
    xil_printf("   Zynq CAN + LCD + UART Initializing  \r\n");
    xil_printf("***************************************\r\n");

    // 2. Initialize AXI IIC
    IicConfig = XIic_LookupConfig(IIC_BASEADDR);
    if (IicConfig == NULL) {
        xil_printf("Error: IIC Config Lookup Failed!\r\n");
        return XST_FAILURE;
    }
    Status = XIic_CfgInitialize(&IicInstance, IicConfig, IicConfig->BaseAddress);
    if (Status != XST_SUCCESS) {
        xil_printf("Error: IIC Initialization Failed!\r\n");
        return XST_FAILURE;
    }

    // 3. Initialize LCD
    lcd_init();
    lcd_putstr("System Ready");
    xil_printf("LCD Initialization Complete.\r\n");

    // 4. Initialize PS CAN
    CanConfig = XCanPs_LookupConfig(CAN_BASEADDR);
    if (CanConfig == NULL) {
        xil_printf("Error: CAN Config Lookup Failed!\r\n");
        return XST_FAILURE;
    }
    Status = XCanPs_CfgInitialize(&CanInstance, CanConfig, CanConfig->BaseAddr);
    if (Status != XST_SUCCESS) {
        xil_printf("Error: CAN Initialization Failed!\r\n");
        return XST_FAILURE;
    }

    // 5. CAN Configuration (500 kbps)
    XCanPs_EnterMode(&CanInstance, XCANPS_MODE_CONFIG);
    XCanPs_SetBaudRatePrescaler(&CanInstance, 9);
    XCanPs_SetBitTiming(&CanInstance, 0, 3, 14);
    XCanPs_EnterMode(&CanInstance, XCANPS_MODE_NORMAL);
    xil_printf("CAN Bus Online at 500kbps.\r\n");

    // 6. Main Loop
    while(1) {
        // Prepare Message: ID 0x123, 8 Bytes
        TxFrame[0] = (u32)XCanPs_CreateIdValue(0x123, 0, 0, 0, 0);
        TxFrame[1] = (u32)XCanPs_CreateDlcValue(8);
        TxFrame[2] = __builtin_bswap32(0xDEADBEEF); // Data Word 1
        TxFrame[3] = tx_count;   // Data Word 2 (Moving counter)

        Status = XCanPs_Send(&CanInstance, TxFrame);

        // Clear LCD for new update
        lcd_command(0x01);
        usleep(2000);

        if (Status == XST_SUCCESS) {
            // Update LCD
            sprintf(display_msg, "Sent #%d", tx_count);
            lcd_putstr(display_msg);
            
            // Update Serial Monitor (UART)
            xil_printf("[UART] Success: Transmitted Frame #%d (ID: 0x123)\r\n", tx_count);
        } else {
            // Update LCD
            lcd_putstr("TX FAILED!");
            
            // Update Serial Monitor (UART)
            xil_printf("[UART] ERROR: CAN Send Failed. Check wiring/termination.\r\n");
        }

        tx_count++;
        sleep(1); // Wait 1 second
    }
    return 0;
}