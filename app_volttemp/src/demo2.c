#include <stdio.h>
#include "xparameters.h"
#include "xcanps.h"
#include "xiic.h"
#include "xuartps.h"
#include "xadcps.h" 
#include "xil_printf.h"
#include "sleep.h"

// Hardware Definitions
#define CAN_BASEADDR      XPAR_XCANPS_0_BASEADDR
#define IIC_BASEADDR      XPAR_XIIC_0_BASEADDR
#define XADC_DEVICE_ID    XPAR_XXADCPS_0_BASEADDR
#define IIC_SLAVE_ADDR    0x27

XCanPs CanInst;
XIic IicInst;
XAdcPs XAdcInst;

// --- LCD Helpers ---
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
    char msg[17];
    u32 RawData;
    float Temp, Vcc;
    int display_state = 0;

    xil_printf("\r\n--- System Booting... ---\r\n");

    // 1. Initialize XADC
    XAdcCfg = XAdcPs_LookupConfig(XADC_DEVICE_ID);
    if (XAdcCfg == NULL) { xil_printf("XADC Lookup Failed!\r\n"); return 1; }
    XAdcPs_CfgInitialize(&XAdcInst, XAdcCfg, XAdcCfg->BaseAddress);
    xil_printf("XADC Initialized.\r\n");

    // 2. Initialize I2C LCD
    IicCfg = XIic_LookupConfig(IIC_BASEADDR);
    if (IicCfg == NULL) { xil_printf("IIC Lookup Failed!\r\n"); return 1; }
    XIic_CfgInitialize(&IicInst, IicCfg, IicCfg->BaseAddress);
    lcd_init();
    xil_printf("LCD Initialized.\r\n");

    // 3. Initialize CAN
    CanCfg = XCanPs_LookupConfig(CAN_BASEADDR);
    if (CanCfg == NULL) { xil_printf("CAN Lookup Failed!\r\n"); return 1; }
    XCanPs_CfgInitialize(&CanInst, CanCfg, CanCfg->BaseAddr);
    XCanPs_EnterMode(&CanInst, XCANPS_MODE_CONFIG);
    XCanPs_SetBaudRatePrescaler(&CanInst, 9);
    XCanPs_SetBitTiming(&CanInst, 0, 3, 14);
    XCanPs_EnterMode(&CanInst, XCANPS_MODE_NORMAL);
    xil_printf("CAN Initialized. Starting Loop...\r\n");

    while(1) {
        if (display_state == 0) {
            // Read and Show Temp
            RawData = XAdcPs_GetAdcData(&XAdcInst, XADCPS_CH_TEMP);
            Temp = XAdcPs_RawToTemperature(RawData);
            
            TxFrame[0] = XCanPs_CreateIdValue(0x123, 0, 0, 0, 0);
            TxFrame[1] = XCanPs_CreateDlcValue(4);
            TxFrame[2] = __builtin_bswap32((int32_t)(Temp * 100));
            XCanPs_Send(&CanInst, TxFrame);

            lcd_send_internal(0x80, 0); lcd_putstr("MODE: TEMP      ");
            lcd_send_internal(0xC0, 0); 
            sprintf(msg, "VALUE: %d.%d C   ", (int)Temp, (int)(Temp * 10) % 10);
            lcd_putstr(msg);
            
            xil_printf("TX: Temp (0x123)\r\n");
            display_state = 1;
        } 
        else {
            // Read and Show VCCINT
            RawData = XAdcPs_GetAdcData(&XAdcInst, XADCPS_CH_VCCAUX);
            Vcc = XAdcPs_RawToVoltage(RawData);

            TxFrame[0] = XCanPs_CreateIdValue(0x124, 0, 0, 0, 0);
            TxFrame[1] = XCanPs_CreateDlcValue(4);
            TxFrame[2] = __builtin_bswap32((int32_t)(Vcc * 1000));
            XCanPs_Send(&CanInst, TxFrame);

            lcd_send_internal(0x80, 0); lcd_putstr("MODE: VOLTAGE   ");
            lcd_send_internal(0xC0, 0); 
            sprintf(msg, "VCCINT: %d.%03d V ", (int)Vcc, (int)(Vcc * 1000) % 1000);
            lcd_putstr(msg);

            xil_printf("TX: VCCINT (0x124)\r\n");
            
            display_state = 0;
        }

        sleep(2);
    }
    return 0;
}