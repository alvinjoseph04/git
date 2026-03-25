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

#include <stdio.h>
// #include "platform.h"
#include "xil_printf.h"


// int main()
// {
//     init_platform();

//     print("Hello World\n\r");
//     print("Successfully ran Hello World application");
//     cleanup_platform();
//     return 0;
// }

#include <stdio.h>
#include "xparameters.h"
#include "xil_printf.h"
#include "sleep.h"

int main() {
    int count = 0;

    // A small initial delay helps the Serial Monitor "catch up" 
    // after the FPGA is programmed.
    sleep(2);

    xil_printf("--- PYNQ-Z2 UART COUNTER TEST ---\r\n");
    xil_printf("Starting Plain Counter...\r\n\n");

    while(1) {
        // %d is the placeholder for the integer 'count'
        xil_printf("Counter Value: %d\r\n", count);
        
        count++;      // Increment the number
        sleep(1);     // Wait for 1 second (1000ms)
    }

    return 0; // Should never reach here
}
