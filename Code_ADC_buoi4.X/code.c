// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 20000000
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define RS RD2
#define EN RD3
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7

#include "lcd.h"
#include <stdio.h>
char buff[10];

char buffNhietDo[10];

void ADC_Init() {
    ADCON0 = 0X01;
    
    // 0B 0000 0001 
    ADCON1 = 0x80;
}

unsigned int ADC_Read(int channel) {
    if (channel > 7)
        return 0;
    ADCON0 |= channel << 3;
    GO_nDONE = 1;
    while (GO_nDONE);
    //GO_nDONE = 0;
    return ((ADRESH << 8) + ADRESL);
}

void main(void) {
    TRISD = 0x00;
    Lcd_Init();
    ADC_Init();
    int value_adc = 0;
    int nhietdo = 0;
    while (1) {

        value_adc = ADC_Read(4) * 3.33;
        
        nhietdo = (value_adc * 150.f / 1023);
        Lcd_Set_Cursor(1, 1);

        Lcd_Write_String("ADC : ");
        Lcd_Set_Cursor(9, 1);
        sprintf(buff, "%d", value_adc);
        Lcd_Write_String(buff);
        
        
        Lcd_Set_Cursor(2,2);
        Lcd_Write_String("Nhiet Do : ");
        Lcd_Set_Cursor(10, 2);
        sprintf(buffNhietDo, "%d", nhietdo);
        Lcd_Write_String(buffNhietDo);
    }

}