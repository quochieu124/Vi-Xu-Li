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
#define _XTAL_FREQ 20e6

void main(void) {
    TRISB = 0x00;   // Set PORTB as output
    PORTB = 0x00;   // Initialize PORTB to 0
    TRISC = 0x01;   // Set RC0 as input
    PORTC = 0x00;   // Initialize PORTC to 0
    
    while(1) {
        // LED3 cycle
        PORTBbits.RB2 = 1;
        __delay_ms(500);
        PORTBbits.RB2 = 0;
        __delay_ms(500);
        PORTBbits.RB2 = 1;
        __delay_ms(300);
        PORTBbits.RB2 = 0;
        __delay_ms(300);

        if (PORTCbits.RC0 == 0) {  // Button pressed
            PORTBbits.RB1 = 1;  // Turn off LED2
            PORTBbits.RB0 = 0;  // Turn on LED1
            __delay_ms(500);
            PORTBbits.RB0 = 1;
            __delay_ms(500);
        } else {  // Button released
            PORTBbits.RB0 = 1;  // Turn off LED1
            PORTBbits.RB1 = 0;  // Turn on LED2
            __delay_ms(200);
            PORTBbits.RB1 = 1;
            __delay_ms(800);
        }
    }
}
