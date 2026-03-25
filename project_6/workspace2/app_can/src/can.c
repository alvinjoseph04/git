#include <stdio.h>
#include "xparameters.h"
#include "xcanps.h"
#include "xil_printf.h"

// Using the Base Address from your xparameters.h
#define CAN_BASEADDR     XPAR_XCANPS_0_BASEADDR

// Timing for 100 MHz Clock -> 500 kbps Baud Rate
// 100MHz / (9+1) / (1 + 15 + 4) = 500,000 bps
#define TEST_BRP      9
#define TEST_TSEG1    14  
#define TEST_TSEG2    3   
#define TEST_SJW      3

XCanPs CanInstance;

int main() {
    XCanPs_Config *ConfigPtr;
    int Status;
    u32 TxFrame[8];

    xil_printf("--- CAN EMIO Test (BaseAddr Lookup) ---\r\n");

    // 1. Find Configuration using Base Address instead of Device ID
    // Note: XCanPs_LookupConfig is overloaded in many versions to take 
    // the base address if the ID is not present.
    ConfigPtr = XCanPs_LookupConfig(CAN_BASEADDR);
    
    // Fallback: If LookupConfig returns NULL, manually point to the config table
    if (ConfigPtr == NULL) {
        xil_printf("Lookup failed. Manually linking config table...\r\n");
        extern XCanPs_Config XCanPs_ConfigTable[];
        ConfigPtr = &XCanPs_ConfigTable[0];
    }

    // 2. Initialize the driver
    Status = XCanPs_CfgInitialize(&CanInstance, ConfigPtr, CAN_BASEADDR);
    if (Status != XST_SUCCESS) {
        xil_printf("Initialization Failed!\r\n");
        return XST_FAILURE;
    }

    // 3. Enter Configuration Mode to set timings
    XCanPs_EnterMode(&CanInstance, XCANPS_MODE_CONFIG);
    XCanPs_SetBaudRatePrescaler(&CanInstance, TEST_BRP);
    XCanPs_SetBitTiming(&CanInstance, TEST_SJW, TEST_TSEG2, TEST_TSEG1);

    // 4. Enter Normal Mode to enable transmission
    XCanPs_EnterMode(&CanInstance, XCANPS_MODE_NORMAL);
    xil_printf("Normal Mode Entered. Sending CAN ID 0x123...\r\n");

    // 5. Create a Standard CAN Frame
    TxFrame[0] = (u32)XCanPs_CreateIdValue(0x123, 0, 0, 0, 0);
    TxFrame[1] = (u32)XCanPs_CreateDlcValue(8);
    TxFrame[2] = 0xAA55AA55; // Data Word 1
    TxFrame[3] = 0x12345678; // Data Word 2

    // 6. Infinite Send Loop
    while(1) {
        Status = XCanPs_Send(&CanInstance, TxFrame);
        
        if (Status == XST_SUCCESS) {
            xil_printf("Frame Sent Successfully!\r\n");
        } else {
            // If it fails, the bus might be in 'Error Passive' or disconnected
            xil_printf("Send Failed. Check Transceiver/Cables.\r\n");
        }

        // Delay for roughly 1 second
        for (volatile int i = 0; i < 20000000; i++);
    }

    return 0;
}