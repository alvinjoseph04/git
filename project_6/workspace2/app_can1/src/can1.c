#include <stdio.h>
#include "xparameters.h"
#include "xcanps.h"
#include "xil_printf.h"

// 1. Hardware Definitions from your xparameters.h
#define CAN_BASEADDR     XPAR_XCANPS_0_BASEADDR
// If XPAR_XCANPS_0_DEVICE_ID is missing in your Vitis version, use 0
#ifndef XPAR_XCANPS_0_DEVICE_ID
    #define CAN_DEVICE_ID 0 
#else
    #define CAN_DEVICE_ID XPAR_XCANPS_0_DEVICE_ID
#endif

// 2. Corrected Timing for 100 MHz Clock -> 500 kbps
// Total Quanta = 20 (1 Sync + 15 TSEG1 + 4 TSEG2)
// Logic: We pass (Value - 1) to the functions.
#define CONF_BRP      9   // (100MHz / 10) = 10MHz Time Quanta
#define CONF_SJW      0   // 0 results in SJW of 1
#define CONF_TSEG2    3   // 3 results in TSEG2 of 4
#define CONF_TSEG1    14  // 14 results in TSEG1 of 15

XCanPs CanInstance;

int main() {
    XCanPs_Config *ConfigPtr;
    int Status;
    u32 TxFrame[8];

    xil_printf("\r\n--- Zynq CAN EMIO 500kbps Test ---\r\n");

    // 1. Initialize Configuration
    ConfigPtr = XCanPs_LookupConfig(CAN_DEVICE_ID);
    if (ConfigPtr == NULL) {
        // Fallback for SDT/Newer Vitis versions
        extern XCanPs_Config XCanPs_ConfigTable[];
        ConfigPtr = &XCanPs_ConfigTable[0];
    }

    Status = XCanPs_CfgInitialize(&CanInstance, ConfigPtr, CAN_BASEADDR);
    if (Status != XST_SUCCESS) {
        xil_printf("Error: CAN Initialization failed\r\n");
        return XST_FAILURE;
    }

    // 2. Self-Test (Logic Check)
    if (XCanPs_SelfTest(&CanInstance) != XST_SUCCESS) {
        xil_printf("Error: CAN Internal Self-test failed\r\n");
        return XST_FAILURE;
    }

    // 3. Set Baud Rate (Must be in Configuration Mode)
    XCanPs_EnterMode(&CanInstance, XCANPS_MODE_CONFIG);
    
    XCanPs_SetBaudRatePrescaler(&CanInstance, CONF_BRP);
    // CRITICAL ORDER: SJW, TSEG2, TSEG1
    XCanPs_SetBitTiming(&CanInstance, CONF_SJW, CONF_TSEG2, CONF_TSEG1);

    // 4. Enter Normal Mode (Start Bus Communication)
    XCanPs_EnterMode(&CanInstance, XCANPS_MODE_NORMAL);
    xil_printf("CAN Online at 500 kbps. Sending ID 0x123...\r\n");

    // 5. Prepare a Standard Data Frame
    // ID: 0x123, Standard, DLC: 8 bytes
    TxFrame[0] = (u32)XCanPs_CreateIdValue(0x123, 0, 0, 0, 0);
    TxFrame[1] = (u32)XCanPs_CreateDlcValue(8);
    TxFrame[2] = __builtin_bswap32(0xDEADBEEF); // Data Bytes 0-3
    TxFrame[3] = __builtin_bswap32(0xCAFEBABE); // Data Bytes 4-7

    // 6. Main Transmission Loop
    while(1) {
        Status = XCanPs_Send(&CanInstance, TxFrame);
        
        if (Status == XST_SUCCESS) {
            xil_printf("Message Sent Successfully!\r\n");
        } else {
            xil_printf("Send Failed! (Check wires/termination/laptop)\r\n");
            // Check if bus is in 'Bus Off' or 'Error Passive'
            u32 ErrorStatus = XCanPs_GetStatus(&CanInstance);
            xil_printf("Status Register: 0x%08X\r\n", ErrorStatus);
        }

        // Simple Busy-Wait Delay (~1 second)
        for (volatile int i = 0; i < 20000000; i++);
    }

    return 0;
}