/******************************************************************************
* Copyright (C) 2023 Advanced Micro Devices, Inc. All Rights Reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/
/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

// #include <stdio.h>
// #include "platform.h"
// #include "xil_printf.h"


// int main()
// {
//     init_platform();

//     printf("RUN1");
//     xil_printf("Hello World\n\r");
//     printf("RUN2");
//     xil_printf("Successfully ran Hello World application");
//     printf("RUN3");
//     cleanup_platform();
//     return 0;
// }


// #include <stdio.h>
// #include "xparameters.h"
// #include "xuartlite.h"
// #include "xil_printf.h"
// #include "sleep.h"

// // 1. New SDT Naming: This is generated in your xparameters.h
// #define UART_BASEADDR XPAR_XUARTLITE_0_BASEADDR 

// XUartLite UartInstance;

// int main() {
//     XUartLite_Config *ConfigPtr;
//     int Status;

//     // 2. Lookup the configuration using the Base Address 
//     ConfigPtr = XUartLite_LookupConfig(UART_BASEADDR);
//     if (ConfigPtr == NULL) {
//         return XST_FAILURE;
//     }

//     // 3. 2025.1 CfgInitialize
//     // In the latest drivers, we pass the Instance and the ConfigPtr.
//     // The third parameter is the Base Address itself.
//     Status = XUartLite_CfgInitialize(&UartInstance, ConfigPtr, UART_BASEADDR);
//     if (Status != XST_SUCCESS) {
//         return XST_FAILURE;
//     }

//     // 4. Verification Loop
//     while(1) {
//         // This relies on the BSP STDOUT being set to axi_uartlite_0
//         xil_printf("Success! AXI UARTLite is talking at 0x%08X\r\n", UART_BASEADDR);
        
//         // Manual Send: This proves the hardware is working even if xil_printf fails
//         u8 TestStr[] = "Hardware fine!\r\n";
//         XUartLite_Send(&UartInstance, TestStr, sizeof(TestStr)-1);

//         sleep(1);
//     }

//     return 0;
// }


#include <stdio.h>
#include "xparameters.h"
#include "xuartps.h"     // Driver for the PS7 UART
#include "xil_printf.h"
#include "sleep.h"

// In 2025.1 SDT, this is the standard naming for the PS7 UART base address
// Use XPAR_XUARTPS_0_BASEADDR or XPAR_XUARTPS_1_BASEADDR depending on your Vivado config
#define UART_BASEADDR XPAR_XUARTPS_0_BASEADDR 

XUartPs Uart_PS;		/* The instance of the UART Driver */

int main() {
    XUartPs_Config *Config;
    int Status;
    u32 counter = 0;

    // 1. Initialize the UART driver
    Config = XUartPs_LookupConfig(UART_BASEADDR);
    if (NULL == Config) {
        return XST_FAILURE;
    }

    Status = XUartPs_CfgInitialize(&Uart_PS, Config, Config->BaseAddress);
    if (Status != XST_SUCCESS) {
        return XST_FAILURE;
    }

    // 2. Set the Baud Rate (Standard is 115200)
    XUartPs_SetBaudRate(&Uart_PS, 115200);

    // 3. The Loop
    while(1) {
        // xil_printf is the most reliable way to check the BSP routing
        xil_printf("Hello World from PS7 MIO UART! Count: %d\r\n", counter);
        
        // Manual Send (Backup check to bypass xil_printf logic)
        u8 TestMsg[] = "PS7_HARDWARE_ALIVE\r\n";
        XUartPs_Send(&Uart_PS, TestMsg, sizeof(TestMsg)-1);

        counter++;
        sleep(1);
    }

    return 0;
}