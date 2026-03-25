#include "xparameters.h"
#include "xiic.h"         // Changed from xiicps.h to xiic.h
#include "xil_printf.h"
#include "sleep.h"
 
// Update these names based on your specific xparameters.h
#define IIC_DEVICE_ID      XPAR_AXI_IIC_0_BASEADDR
 
#define LCD_SLAVE_ADDR     0x27
 
// PCF8574 to LCD Pin Mapping (Remains Untouched)
#define LCD_BIT_RS         0x01
#define LCD_BIT_RW         0x02
#define LCD_BIT_EN         0x04
#define LCD_BIT_BACKLIGHT  0x08
 
XIic IicInstance; // Changed from XIicPs to XIic
 
// Sends a nibble and toggles the Enable pin
void LCD_WriteNibble(uint8_t nibble, uint8_t flags) {
    uint8_t data = nibble | flags | LCD_BIT_BACKLIGHT;
    uint8_t buf[1];
   
    // Pulse Enable High
    buf[0] = data | LCD_BIT_EN;
    // Changed to XIic_Send using the instance base address
    XIic_Send(IicInstance.BaseAddress, LCD_SLAVE_ADDR, buf, 1, XIIC_STOP);
    usleep(1);
   
    // Pulse Enable Low
    buf[0] = data;
    XIic_Send(IicInstance.BaseAddress, LCD_SLAVE_ADDR, buf, 1, XIIC_STOP);
    usleep(50);
}
 
// Sends a full byte (2 nibbles) - Untouched
void LCD_SendByte(uint8_t val, uint8_t flags) {
    LCD_WriteNibble(val & 0xF0, flags);
    LCD_WriteNibble((val << 4) & 0xF0, flags);
}
 
void LCD_SendCommand(uint8_t cmd) {
    LCD_SendByte(cmd, 0);
}
 
void LCD_SendData(uint8_t data) {
    LCD_SendByte(data, LCD_BIT_RS);
}
 
void LCD_Init() {
    usleep(50000);
   
    LCD_WriteNibble(0x30, 0);
    usleep(5000);
    LCD_WriteNibble(0x30, 0);
    usleep(200);
    LCD_WriteNibble(0x30, 0);
    LCD_WriteNibble(0x20, 0);
 
    LCD_SendCommand(0x28);
    LCD_SendCommand(0x0C);
    LCD_SendCommand(0x06);
    LCD_SendCommand(0x01);
    usleep(2000);
}
 
void LCD_Print(char *str) {
    while (*str) {
        LCD_SendData((uint8_t)(*str++));
    }
}
 
int main() {
    int Status;
 
    xil_printf("Starting AXI IIC LCD Hello World...\r\n");
 
    // 1. Initialize AXI IIC Driver
    Status = XIic_Initialize(&IicInstance, IIC_DEVICE_ID);
    if (Status != XST_SUCCESS) return XST_FAILURE;
 
    // 2. Start the IIC Device (Necessary for AXI IP to enable the bus logic)
    Status = XIic_Start(&IicInstance);
    if (Status != XST_SUCCESS) return XST_FAILURE;
 
    // 3. Initialize LCD
    LCD_Init();
 
    // 4. Print Hello World
    LCD_SendCommand(0x80);
    LCD_Print("Hello World!");
   
    LCD_SendCommand(0xC0);
    LCD_Print("AXI IP OK");
 
    xil_printf("Done!\r\n");
 
    while(1);
    return 0;
}
 