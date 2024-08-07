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
#define _XTAL_FREQ 20000000  // Define crystal frequency

void main(void) {
    TRISB = 0x00;  // Set PORTB as output
    PORTB = 0x00;  // Clear PORTB

    while(1) {
        // Light up LEDs in sequence
        PORTB = 0x01;  // Turn on LED at RB0
        __delay_ms(1000);

        PORTB = 0x03;  // Turn on LEDs at RB0 and RB1
        __delay_ms(1000);

        PORTB = 0x07;  // Turn on LEDs at RB0, RB1, and RB2
        __delay_ms(1000);

        PORTB = 0x0F;  // Turn on LEDs at RB0, RB1, RB2, and RB3
        __delay_ms(1000);

        // Light up LEDs in reverse sequence
        PORTB = 0x0E;  // Turn on LEDs at RB1, RB2, and RB3
        __delay_ms(1000);

        PORTB = 0x0C;  // Turn on LEDs at RB2 and RB3
        __delay_ms(1000);

        PORTB = 0x08;  // Turn on LED at RB3
        __delay_ms(1000);

        PORTB = 0x00;  // Turn off all LEDs
        __delay_ms(1000);
    }
}
