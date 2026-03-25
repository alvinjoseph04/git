#include <stdio.h>
#include "xparameters.h"
#include "xcanps.h"
#include "xiic.h"
#include "xuartps.h"
#include "xil_printf.h"
#include "sleep.h"

// Hardware Addresses from 2025.1 xparameters.h
#define CAN_DEVICE_ID    XPAR_XCANPS_0_BASEADDR
#define IIC_DEVICE_ID    XPAR_XIIC_0_BASEADDR
#define UART_DEVICE_ID   XPAR_XUARTPS_0_BASEADDR
#define IIC_SLAVE_ADDR   0x27

XCanPs CanInst;
XIic IicInst;

// --- I2C LCD HELPER FUNCTIONS ---
void lcd_send(uint8_t data, uint8_t flags) {
    uint8_t up = (data & 0xF0) | flags | 0x08; // 0x08 = Backlight ON
    uint8_t lo = ((data << 4) & 0xF0) | flags | 0x08;
    uint8_t buf[4] = { (up | 0x04), up, (lo | 0x04), lo }; // 0x04 = Enable Pulse
    for(int i=0; i<4; i++) {
        XIic_Send(IIC_DEVICE_ID, IIC_SLAVE_ADDR, &buf[i], 1, XIIC_STOP);
    }
}

void lcd_init() {
    usleep(50000);
    lcd_send(0x33, 0); lcd_send(0x32, 0); // 4-bit mode
    lcd_send(0x28, 0); lcd_send(0x0C, 0); // 2 line, display on
    lcd_send(0x01, 0); usleep(5000);     // Clear display
}

void lcd_print(char *str) {
    while(*str) lcd_send(*str++, 1);
}

// --- MAIN APPLICATION ---
int main() {
    XCanPs_Config *CanConfig;
    XIic_Config *IicConfig;
    u32 RxFrame[8];
    int Status;

    // 1. Initialize I2C LCD
    IicConfig = XIic_LookupConfig(IIC_DEVICE_ID);
    XIic_CfgInitialize(&IicInst, IicConfig, IicConfig->BaseAddress);
    lcd_init();

    // 2. Initialize PS CAN
    CanConfig = XCanPs_LookupConfig(CAN_DEVICE_ID);
    XCanPs_CfgInitialize(&CanInst, CanConfig, CanConfig->BaseAddr);
    
    // Set CAN Timing (Assuming 100MHz clock for 500Kbps)
    XCanPs_EnterMode(&CanInst, XCANPS_MODE_CONFIG);
    XCanPs_SetBaudRatePrescaler(&CanInst, 9);
    XCanPs_SetBitTiming(&CanInst, 0, 3, 14);
    XCanPs_EnterMode(&CanInst, XCANPS_MODE_NORMAL);

    xil_printf("\r\n--- PYNQ-Z2 CAN GATEWAY READY ---\r\n");
    xil_printf("Waiting for WaveShare data...\r\n");
    lcd_print("CAN Waiting...");

    while(1) {
        // Check if a message has arrived in the CAN RX FIFO
        if (XCanPs_IsRxEmpty(&CanInst) == FALSE) {
            Status = XCanPs_Recv(&CanInst, RxFrame);
            
            if (Status == XST_SUCCESS) {
                // CAN Frame format: 
                // RxFrame[0] = ID, [1] = DLC, [2] = Data1 (4 bytes), [3] = Data2 (4 bytes)
                u32 can_id = (RxFrame[0] >> 21); // Standard ID shift
                u32 data_low = RxFrame[2];

                // 3. Display on Serial Terminal (MIO UART)
                xil_printf("CAN Received! ID: 0x%X | Data: 0x%08X\r\n", can_id, data_low);

                // 4. Update I2C LCD
                lcd_send(0x01, 0); // Clear LCD
                usleep(2000);
                char msg[16];
                sprintf(msg, "ID:0x%X", (unsigned int)can_id);
                lcd_print(msg);
                
                // Move to second line for data
                lcd_send(0xC0, 0); 
                sprintf(msg, "D:0x%08X", (unsigned int)data_low);
                lcd_print(msg);
            }
        }
        usleep(1000); // Poll every 1ms
    }

    return 0;
}