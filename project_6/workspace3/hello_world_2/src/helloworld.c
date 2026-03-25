// #include <stdio.h>
// #include "xparameters.h"
// #include "xuartps.h"
// #include "xstatus.h"

// /* Directly using the Base Address from your xparameters.h */
// #define UART_BASEADDR      XPAR_XUARTPS_0_BASEADDR
// #define UART_CLOCK_HZ      XPAR_XUARTPS_0_CLOCK_FREQ

// XUartPs UartInst; // Instance of the UART Device

// int main() {
//     XUartPs_Config *Config;
//     int Status;

//     /* 1. Lookup configuration using the Base Address */
//     Config = XUartPs_LookupConfig(UART_BASEADDR);
//     if (NULL == Config) {
//         return XST_FAILURE;
//     }

//     /* 2. Initialize the driver */
//     Status = XUartPs_CfgInitialize(&UartInst, Config, Config->BaseAddress);
//     if (Status != XST_SUCCESS) {
//         return XST_FAILURE;
//     }

//     /* 3. Self-test to verify hardware integrity */
//     Status = XUartPs_SelfTest(&UartInst);
//     if (Status != XST_SUCCESS) {
//         return XST_FAILURE;
//     }

//     /* 4. Configure the UART settings */
//     XUartPs_SetBaudRate(&UartInst, 115200);
//     XUartPs_SetOperMode(&UartInst, XUARTPS_OPER_MODE_NORMAL);

//     /* 5. Simple Output Test */
//     printf("UART0 Initialized at BaseAddress: 0x%08X\n\r", (unsigned int)UART_BASEADDR);
    
//     char Hello[] = "Hello from Zynq UART0!\n\r";
//     XUartPs_Send(&UartInst, (u8*)Hello, sizeof(Hello));

//     while(1) {
//         // Main loop
//     }

//     return XST_SUCCESS;
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