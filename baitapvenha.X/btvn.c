
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

unsigned char segments_code[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void main(void) {
    TRISB = 0x00;  
    TRISC = 0x06;  
    PORTB = 0x00;  
    PORTC = 0x00;  
    int dem = 0;   
    PORTB = segments_code[dem]; 
    
    while(1) {
        if (PORTCbits.RC1 == 0) {  
            __delay_ms(200);       
            if (PORTCbits.RC1 == 0) {
                dem++;
                if (dem > 9) dem = 0;  
                PORTB = segments_code[dem]; 
            }
        }
        if (PORTCbits.RC2 == 1) {  
            __delay_ms(200);       
            if (PORTCbits.RC2 == 1) {
                dem--;
                if (dem < 0) dem = 9;  
                PORTB = segments_code[dem]; 
            }
        }
        if (dem == 0) {
            PORTCbits.RC3 = 1;  
            PORTCbits.RC4 = 1;  
            PORTCbits.RC5 = 1;  
        } else if (dem < 3) {
            PORTCbits.RC3 = 0;  
            PORTCbits.RC4 = 1;  
            PORTCbits.RC5 = 1;  
        } else if (dem >= 3 && dem <= 6) {
            PORTCbits.RC3 = 1;  
            PORTCbits.RC4 = 0;  
            PORTCbits.RC5 = 1;  
        } else if (dem > 6) {
            PORTCbits.RC3 = 1;  
            PORTCbits.RC4 = 1;  
            PORTCbits.RC5 = 0; 
        }
    }
}
