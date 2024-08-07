// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)
#define _XTAL_FREQ 20000000
#include <xc.h>

void setUpTimer1(int preScale, int tmrValue) {
    TMR1ON = 1;
    // cho phep timer 1 hoat dong.
    TMR1CS = 0;
    // chon che do timer
    T1SYNC = 1;
    GIE = 1;
    // cho phep ngat toan cuc
    PEIE = 1;
    // cho phep ngat ngoai vi
    TMR1IE = 1;
    // Cho phep ngat timer hoat dong
    /*=================================*/
    if (preScale == 1) {
        T1CKPS0 = 0;
        T1CKPS1 = 0;
    }
    if (preScale == 2) {
        T1CKPS0 = 1;
        T1CKPS1 = 0;
    }
    if (preScale == 4) {
        T1CKPS0 = 0;
        T1CKPS1 = 1;
    }
    if (preScale == 8) {
        T1CKPS0 = 1;
        T1CKPS1 = 1;
    }
    TMR1 = tmrValue;
    // << OR hoac la AND | &

}
void main(void) {
    setUpTimer1(8, 3035);
    TRISB = 0x00;
    PORTB = 0x00;
    while (1) {
        RB1 = 0;
        __delay_ms(3000);
        RB1 = 1;
        __delay_ms(3000);
    }
}
void __interrupt() timer1() {
    if (PIR1bits.TMR1IF == 1) {
        PIR1bits.TMR1IF = 0;
        TMR1 = 3035;
        RB2 ^= 1;



    }
}