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

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 20000000  
unsigned char segments_code[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

void display_number(unsigned char number) {
    unsigned char chuc = number % 10;
    unsigned char donvi = number / 10;
    
        
    PORTC = 0x02;  
    PORTB = segments_code[donvi]; 
    __delay_ms(5); 
    
    PORTC = 0x01;  
    PORTB = segments_code[chuc]; 
    __delay_ms(5); 
}
int main(void) {
    TRISB = 0x00;
    PORTB = 0x00; 
    TRISC = 0x00; 
    PORTC = 0x00; 
    
    while(1) {
        for (unsigned char i = 0; i <= 60; i++) {
            for (unsigned char j = 0; j < 100; j++) {
                display_number(i);
            }
        }
    }
}
