// #include "xparameters.h"
// #include "netif/xadapter.h"
// #include "ff.h" 
// #include "xil_printf.h"
// #include "lwip/udp.h"
// #include "sleep.h"
// #include "lwip/inet.h"
// #include "lwip/ip_addr.h"

// // --- CUSTOMIZE THESE SETTINGS ---
// #define SRC_IP_ADDR      "192.168.1.10"  // Zynq IP
// #define DST_IP_ADDR      "192.168.1.5"  // Your Laptop IP
// #define UDP_PORT         7               // Port for Hercules/Netcat
// #define SD_FILENAME      "DATA.txt"      // File on your SD card

// static FATFS fatfs;
// static FIL fil;
// static char file_buffer[1024];

// void send_udp_message(char *payload) {
//     struct udp_pcb *pcb;
//     struct pbuf *p;
//     ip_addr_t dst_ip;

// ipaddr_aton(DST_IP_ADDR, &dst_ip);
//     pcb = udp_new();
    
//     p = pbuf_alloc(PBUF_TRANSPORT, strlen(payload), PBUF_REF);
//     p->payload = payload;

//     udp_sendto(pcb, p, &dst_ip, UDP_PORT);
    
//     pbuf_free(p);
//     udp_remove(pcb);
// }

// int main() {
//  unsigned int br;  
//    FRESULT res;

//     xil_printf("--- PYNQ-Z2 SD to Ethernet Start ---\r\n");

//     // 1. Mount SD Card
//     res = f_mount(&fatfs, "0:/", 1); 
//     if (res != FR_OK) {
//         xil_printf("SD Mount Failed! Error: %d\r\n", res);
//         return -1;
//     }

//     // 2. Read File from SD
//     res = f_open(&fil, SD_FILENAME, FA_READ);
//     if (res != FR_OK) {
//         xil_printf("Could not open %s\r\n", SD_FILENAME);
//     } else {
//         f_read(&fil, file_buffer, sizeof(file_buffer)-1, &br);
//         file_buffer[br] = '\0';
//         f_close(&fil);
//         xil_printf("Read from SD: %s\r\n", file_buffer);
//     }

//     // 3. Start Ethernet (lwIP initialization would go here)
//     // Note: Use the 'lwIP Echo Server' template main() structure 
//     // to handle the complex network stack initialization.
    
//     while(1) {
//         send_udp_message(file_buffer);
//         xil_printf("Packet Sent to %s\r\n", DST_IP_ADDR);
//         sleep(5);
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #include "xparameters.h"
// #include "netif/xadapter.h"
// #include "lwip/udp.h"
// #include "xil_printf.h"
// #include "xil_cache.h"

// // --- SETTINGS ---
// #define SRC_IP_ADDR "192.168.1.10"
// #define DST_IP_ADDR "192.168.1.5"
// #define UDP_PORT 7

// static struct netif server_netif;

// void send_hello_packet() {
//     struct udp_pcb *pcb;
//     struct pbuf *p;
//     ip_addr_t dst_ip;
//     char *msg = "Hello from Zynq Ethernet!";

//     ipaddr_aton(DST_IP_ADDR, &dst_ip);
//     pcb = udp_new();

//     // Allocate packet buffer
//     p = pbuf_alloc(PBUF_TRANSPORT, strlen(msg), PBUF_REF);
//     p->payload = msg;

//     // Send to Windows PC
//     udp_sendto(pcb, p, &dst_ip, UDP_PORT);

//     pbuf_free(p);
//     udp_remove(pcb);
//     xil_printf("Packet Sent!\r\n");
// }

// int main() {
//     ip_addr_t ipaddr, netmask, gw;
//     unsigned char mac_ethernet_address[] = { 0x00, 0x0a, 0x35, 0x00, 0x01, 0x02 };

//     Xil_ICacheEnable();
//     Xil_DCacheEnable();

//     xil_printf("--- Starting Hello World Ethernet ---\r\n");

//     // Initialize lwIP
//     lwip_init();

//     // Set static IPs
//     ipaddr_aton(SRC_IP_ADDR, &ipaddr);
//     ipaddr_aton("255.255.255.0", &netmask);
//     ipaddr_aton("192.168.1.1", &gw);

//     // Add network interface
//     if (!xemac_add(&server_netif, &ipaddr, &netmask, &gw, mac_ethernet_address, XPAR_XEMACPS_0_BASEADDR)) {
//         xil_printf("Error adding interface\r\n");
//         return -1;
//     }
//     netif_set_default(&server_netif);
//     netif_set_up(&server_netif);

//     int counter = 0;
//     while (1) {
//         // CRITICAL: This processes the incoming network traffic (ARP, etc.)
//         xemacif_input(&server_netif);

//         // Send a message every ~2 seconds (rough software delay)
//         if (counter++ > 2000000) {
//             send_hello_packet();
//             counter = 0;
//         }
//     }
//     return 0;
// }












////////////////////////////////////////////////////////////////////////////////

// // CODE 3
// #include <stdio.h>
// #include <string.h>
// #include "xparameters.h"
// #include "netif/xadapter.h"
// #include "lwip/udp.h"
// #include "xil_printf.h"
// #include "ff.h" // FATFS Header
// #include "xil_cache.h"

// // --- SETTINGS ---
// #define SRC_IP_ADDR "192.168.1.10"
// #define DST_IP_ADDR "192.168.1.5"
// #define UDP_PORT 7

// static struct netif server_netif;
// static FATFS fatfs; // File system object
// static FIL fil;     // File object

// void send_sd_data() {
//     FRESULT res;
//     unsigned int br; // Bytes read
//     char file_buffer[512];
//     struct udp_pcb *pcb;
//     struct pbuf *p;
//     ip_addr_t dst_ip;

//     // 1. Open the file
//     res = f_open(&fil, "DATA.txt", FA_READ);
//     if (res != FR_OK) {
//         xil_printf("Failed to open DATA.txt! Error: %d\r\n", res);
//         return;
//     }

//     // 2. Read the data
//     res = f_read(&fil, file_buffer, sizeof(file_buffer) - 1, &br);
//     if (res == FR_OK && br > 0) {
//         file_buffer[br] = '\0'; // Null-terminate the string
//         xil_printf("SD Content: %s\r\n", file_buffer);

//         // 3. Prepare UDP Packet
//         ipaddr_aton(DST_IP_ADDR, &dst_ip);
//         pcb = udp_new();
        
//         p = pbuf_alloc(PBUF_TRANSPORT, br, PBUF_REF);
//         p->payload = file_buffer;

//         // 4. Send to Windows
//         udp_sendto(pcb, p, &dst_ip, UDP_PORT);
        
//         pbuf_free(p);
//         udp_remove(pcb);
//         xil_printf("SD Data Sent via Ethernet!\r\n");
//     }

//     f_close(&fil);
// }

// int main() {
//     ip_addr_t ipaddr, netmask, gw;
//     unsigned char mac_ethernet_address[] = { 0x00, 0x0a, 0x35, 0x00, 0x01, 0x02 };

//     Xil_ICacheEnable();
//     Xil_DCacheEnable();

//     xil_printf("--- SD to Ethernet Bridge Starting ---\r\n");

//     // Initialize SD Card
//     if (f_mount(&fatfs, "0:/", 1) != FR_OK) {
//         xil_printf("ERROR: SD Card not found or FAT32 format missing.\r\n");
//         return -1;
//     }
//     xil_printf("SD Card Mounted Successfully.\r\n");

//     // Initialize lwIP
//     lwip_init();
//     ipaddr_aton(SRC_IP_ADDR, &ipaddr);
//     ipaddr_aton("255.255.255.0", &netmask);
//     ipaddr_aton("192.168.1.1", &gw);

//     if (!xemac_add(&server_netif, &ipaddr, &netmask, &gw, mac_ethernet_address, XPAR_XEMACPS_0_BASEADDR)) {
//         xil_printf("Error adding interface\r\n");
//         return -1;
//     }
//     netif_set_default(&server_netif);
//     netif_set_up(&server_netif);

//     int counter = 0;
//     while (1) {
//         xemacif_input(&server_netif);

//         // Send SD data every ~5 seconds
//         if (counter++ > 5000000) {
//             send_sd_data();
//             counter = 0;
//         }
//     }
//     return 0;
// }












////////////////////////////////////////////////////////////////////////////////

// coDE 4 
// Send data through UART --> Save in SDCARD --> REad from SD --> Sned through ETH


#include <stdio.h>
#include <string.h>
#include "xparameters.h"
#include "netif/xadapter.h"
#include "lwip/udp.h"
#include "xil_printf.h"
#include "ff.h" 
#include "xil_cache.h"
#include "xuartps.h" // For MIO UART

// --- CONFIGURATION ---
#define SRC_IP_ADDR "192.168.1.10"
#define DST_IP_ADDR "192.168.1.5"
#define UDP_PORT 7
#define UART_DEVICE_ID XPAR_XUARTPS_0_BASEADDR // Usually UART1 on PYNQ-Z2

// --- GLOBALS ---
static struct netif server_netif;
static FATFS fatfs;
static FIL fil;
char uart_rx_buffer[1024];
int rx_ptr = 0;
int file_counter = 0;

// --- ETHERNET SEND FUNCTION ---
void broadcast_ethernet(char* data, int len) {
    struct udp_pcb *pcb;
    struct pbuf *p;
    ip_addr_t dst_ip;

    ipaddr_aton(DST_IP_ADDR, &dst_ip);
    pcb = udp_new();
    
    p = pbuf_alloc(PBUF_TRANSPORT, len, PBUF_REF);
    p->payload = data;

    udp_sendto(pcb, p, &dst_ip, UDP_PORT);
    
    pbuf_free(p);
    udp_remove(pcb);
    xil_printf("[ETH] Sent to PC: %s\r\n", data);
}

// --- SD SAVE FUNCTION ---
void save_to_new_file(char* data) {
    FRESULT res;
    unsigned int bw;
    char filename[20];

    // Create a unique filename: LOG0.TXT, LOG1.TXT, etc.
    sprintf(filename, "LOG%d.TXT", file_counter++);

    res = f_open(&fil, filename, FA_WRITE | FA_CREATE_ALWAYS);
    if (res == FR_OK) {
        f_write(&fil, data, strlen(data), &bw);
        f_close(&fil);
        xil_printf("[SD] Saved to %s\r\n", filename);
    } else {
        xil_printf("[SD] Error creating file: %d\r\n", res);
    }
}

int main() {
    ip_addr_t ipaddr, netmask, gw;
    unsigned char mac_ethernet_address[] = { 0x00, 0x0a, 0x35, 0x00, 0x01, 0x02 };
    XUartPs Uart_Ps;
    XUartPs_Config *Config;

    Xil_ICacheEnable();
    Xil_DCacheEnable();

    // 1. Initialize MIO UART
    Config = XUartPs_LookupConfig(UART_DEVICE_ID);
    XUartPs_CfgInitialize(&Uart_Ps, Config, Config->BaseAddress);
    XUartPs_SetBaudRate(&Uart_Ps, 115200);

    xil_printf("\r\n--- PYNQ-Z2 UART -> SD -> ETH GATEWAY ---\r\n");
    xil_printf("Instructions: Type data in this terminal and press ENTER.\r\n");

    // 2. Initialize SD
    if (f_mount(&fatfs, "0:/", 1) != FR_OK) {
        xil_printf("SD Mount Failed!\r\n");
        return -1;
    }

    // 3. Initialize lwIP
    lwip_init();
    ipaddr_aton(SRC_IP_ADDR, &ipaddr);
    ipaddr_aton("255.255.255.0", &netmask);
    ipaddr_aton("192.168.1.1", &gw);

    if (!xemac_add(&server_netif, &ipaddr, &netmask, &gw, mac_ethernet_address, XPAR_XEMACPS_0_BASEADDR)) {
        return -1;
    }
    netif_set_default(&server_netif);
    netif_set_up(&server_netif);

    // 4. MAIN LOOP
    while (1) {
        // Keep Ethernet Stack Alive
        xemacif_input(&server_netif);

        // Check MIO UART for data
        if (XUartPs_IsReceiveData(Config->BaseAddress)) {
            char c = XUartPs_ReadReg(Config->BaseAddress, XUARTPS_FIFO_OFFSET);
            
            // If user types, show it in the terminal (Echo)
            XUartPs_SendByte(Config->BaseAddress, c);

            // Check for Enter Key (Trigger)
            if (c == '\r' || c == '\n') {
                if (rx_ptr > 0) {
                    uart_rx_buffer[rx_ptr] = '\0'; // Null terminate
                    
                    xil_printf("\r\n[SYS] Trigger Detected! Processing...\r\n");

                    // Step A: Save to SD
                    save_to_new_file(uart_rx_buffer);

                    // Step B: Send via Ethernet
                    broadcast_ethernet(uart_rx_buffer, rx_ptr);

                    xil_printf("[SYS] Done. Type next message:\r\n");
                    rx_ptr = 0; // Reset buffer pointer
                }
            } else if (rx_ptr < 1023) {
                uart_rx_buffer[rx_ptr++] = c;
            }
        }
    }
    return 0;
}