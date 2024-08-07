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

#define _XTAL_FREQ 20000000  // 20 MHz

void delay_ms(unsigned int milliseconds) {
    while(milliseconds > 0) {
        __delay_ms(1);
        milliseconds--;
    }
}

int main(void)
{
    TRISB = 0x00; // C?u hình PORTB là output
    PORTB = 0x00; // Xóa PORTB
    TRISC = 0x00; // C?u hình PORTC là output
    PORTC = 0x00; // Xóa PORTC
    
    while(1)
    {
        PORTC = 0xFB; // B?t chân RC2
        delay_ms(10000); // Delay 10000 ms (10 giây)
        PORTC = 0x00; // T?t chân RC2
        
        PORTC = 0xF7; // B?t chân RC3
        delay_ms(15000); // Delay 15000 ms (15 giây)
        PORTC = 0x00; // T?t chân RC3
    }
}
