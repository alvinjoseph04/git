#include <stdio.h>
#include "xparameters.h"
#include "xcanps.h"
#include "xiic.h"
#include "xuartps.h"
#include "xadcps.h" 
#include "xil_printf.h"
#include "sleep.h"

#define CAN_BASEADDR      XPAR_XCANPS_0_BASEADDR
#define IIC_BASEADDR      XPAR_XIIC_0_BASEADDR
#define XADC_DEVICE_ID    XPAR_XXADCPS_0_BASEADDR
#define IIC_SLAVE_ADDR    0x27

XCanPs CanInst;
XIic IicInst;
XAdcPs XAdcInst;

// --- LCD Functions ---
void lcd_send_internal(uint8_t data, uint8_t flags) {
    uint8_t up = (data & 0xF0) | flags | 0x08; 
    uint8_t lo = ((data << 4) & 0xF0) | flags | 0x08;
    uint8_t buf[4] = { (up | 0x04), up, (lo | 0x04), lo }; 
    for(int i = 0; i < 4; i++) {
        XIic_Send(IIC_BASEADDR, IIC_SLAVE_ADDR, &buf[i], 1, XIIC_STOP);
    }
}

void lcd_init() {
    usleep(50000);
    lcd_send_internal(0x33, 0); lcd_send_internal(0x32, 0);
    lcd_send_internal(0x28, 0); lcd_send_internal(0x0C, 0);
    lcd_send_internal(0x01, 0);
    usleep(5000);
}

void lcd_putstr(char *str) {
    while (*str) lcd_send_internal(*str++, 0x01);
}

int main() {
    XCanPs_Config *CanCfg;
    XIic_Config *IicCfg;
    XAdcPs_Config *XAdcCfg;
    u32 TxFrame[8];
    u32 RxFrame[8]; // ADDED: Buffer for received data
    char msg[17];
    u32 RawData;
    float Temp;
    int Status;

    // 1. Initialize PS-XADC
    XAdcCfg = XAdcPs_LookupConfig(XADC_DEVICE_ID);
    if (XAdcCfg == NULL) return XST_FAILURE;
    Status = XAdcPs_CfgInitialize(&XAdcInst, XAdcCfg, XAdcCfg->BaseAddress);
    if (Status != XST_SUCCESS) return XST_FAILURE;

    // 2. Initialize I2C LCD
    IicCfg = XIic_LookupConfig(IIC_BASEADDR);
    XIic_CfgInitialize(&IicInst, IicCfg, IicCfg->BaseAddress);
    lcd_init();

    // 3. Initialize PS CAN
    CanCfg = XCanPs_LookupConfig(CAN_BASEADDR);
    XCanPs_CfgInitialize(&CanInst, CanCfg, CanCfg->BaseAddr);
    XCanPs_EnterMode(&CanInst, XCANPS_MODE_CONFIG);
    XCanPs_SetBaudRatePrescaler(&CanInst, 9);
    XCanPs_SetBitTiming(&CanInst, 0, 3, 14);
    XCanPs_EnterMode(&CanInst, XCANPS_MODE_NORMAL);

    xil_printf("--- System Sync: XADC TX/RX Active ---\r\n");

    while(1) {
        // --- SECTION 1: TRANSMIT TEMPERATURE ---
        RawData = XAdcPs_GetAdcData(&XAdcInst, XADCPS_CH_TEMP);
        Temp = XAdcPs_RawToTemperature(RawData);

        TxFrame[0] = (u32)XCanPs_CreateIdValue(0x123, 0, 0, 0, 0);
        TxFrame[1] = (u32)XCanPs_CreateDlcValue(4);
        TxFrame[2] = __builtin_bswap32((int32_t)(Temp * 100));
        XCanPs_Send(&CanInst, TxFrame);

        // Update UART (Transmit Info)
        xil_printf("TX Temp: %d.%d C\r\n", (int)Temp, (int)(Temp * 10) % 10);

        // --- SECTION 2: RECEIVE FROM WAVESHARE (NEW) ---
        // Check if a message has arrived in the RX FIFO
        if (!XCanPs_IsRxEmpty(&CanInst)) {
            Status = XCanPs_Recv(&CanInst, RxFrame);
            if (Status == XST_SUCCESS) {
                // RxFrame[2] usually contains the first 4 bytes of data
                u32 receivedData = RxFrame[2]; 
                
                // Display on UART
                xil_printf("RX From Waveshare: 0x%08X\r\n", receivedData);

                // Display on LCD (Line 1)
                lcd_send_internal(0x80, 0); 
                sprintf(msg, "RX: 0x%04X      ", (unsigned int)(receivedData & 0xFFFF));
                lcd_putstr(msg);
            }
        } else {
            // If no data received, show standard status
            lcd_send_internal(0x80, 0);
            lcd_putstr("CAN STATUS: OK  ");
        }

        // --- SECTION 3: UPDATE LCD TEMPERATURE ---
        lcd_send_internal(0xC0, 0); // Line 2
        sprintf(msg, "TEMP: %d.%01d C    ", (int)Temp, (int)(Temp * 10) % 10);
        lcd_putstr(msg);

        sleep(2);
    }
    return 0;
}