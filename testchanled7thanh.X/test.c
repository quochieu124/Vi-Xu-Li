// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 20000000  

unsigned char seg7[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void main(void) {
    TRISB = 0x00;  
    TRISC = 0x00;  
    PORTB = 0x00;  
    PORTC = 0x00;  

    while(1) 
    {
        PORTC = 0x01;   
        PORTB = seg7[1]; 
        __delay_ms(5);  
        
        PORTC = 0x02;   
        PORTB = seg7[2]; 
        __delay_ms(5);  
        
        // ?i?u khi?n LED 7 ?o?n th? ba hi?n th? s? 3
        PORTC = 0x04;   // Ch?n LED th? ba
        PORTB = seg7[3]; // Hi?n th? s? 3
        __delay_ms(5);  // Trì hoãn ng?n cho ghép kênh
        
        // ?i?u khi?n LED 7 ?o?n th? t? hi?n th? s? 4
        PORTC = 0x08;   // Ch?n LED th? t?
        PORTB = seg7[4]; // Hi?n th? s? 4
        __delay_ms(5);  // Trì hoãn ng?n cho ghép kênh
    }
}
