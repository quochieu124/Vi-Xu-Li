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

void main(void) {
    TRISB=0x00;
    PORTB=0x00;
    while(1)
    {
        //chay theo chieu trai qua phai:
        PORTB=0xFC;
        __delay_ms(1000);
        PORTB=0XF9;
        __delay_ms(1000);
        PORTB=0xF3;
        __delay_ms(1000);
        PORTB=0xE7;
        __delay_ms(1000);
        PORTB=0xCF;
        __delay_ms(1000);
        PORTB=0x9F;
        __delay_ms(1000);
        PORTB=0x3F;
        __delay_ms(1000);
        
        //chay theo chieu  nguoc lai tu phai sang trai:
        PORTB=0x3F;
        __delay_ms(1000);
        PORTB=0x9F;
        __delay_ms(1000);
        PORTB=0xCF;
        __delay_ms(1000);
        PORTB=0xE7;
        __delay_ms(1000);
        PORTB=0xF3;
        __delay_ms(1000);
        PORTB=0XF9;
        __delay_ms(1000);
        PORTB=0xFC;
        __delay_ms(1000);
    }
}
