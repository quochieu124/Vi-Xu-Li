// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 20000000
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
#include <xc.h>

void setUpTimer0()
{
    INTCONbits.GIE  = 1;
    INTCONbits.T0IE = 1;
    // global interrupt enable.
    OPTION_REGbits.PS0 = 1;
    OPTION_REGbits.PS1 = 1;
    OPTION_REGbits.PS2 = 1;
    OPTION_REGbits.PSA = 0;
    // prescaler
    OPTION_REGbits.T0CS = 0;
    TMR0 = 60;
}
void main(void) {
    TRISB = 0x00;
    PORTB = 0x00;
    setUpTimer0();
    while(1)
    {
        RB2 = 0;
        __delay_ms(3000);
        RB2 = 1;
        __delay_ms(3000);
    }
}
void __interrupt() isr(void)
{
    if(INTCONbits.TMR0IF == 1)
    {
        INTCONbits.TMR0IF = 0; // xoa co ngat
        TMR0   = 60;
        RB1    ^= 1;
    }
}