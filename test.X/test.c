#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 20000000

#include <xc.h>

unsigned char led7seg[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void main(void)
{
    int dem = 0;
    TRISB = 0x03;
    PORTB = 0x00;
    TRISD = 0x00;
    PORTD = 0x00;
    PORTD = led7seg[dem];
    while (1)
    {
        if (PORTBbits.RB0==0)
        {
            __delay_ms(200);
            if (PORTBbits.RB0 == 0)
            {
                dem++;
                if (dem > 9)
                {
                    dem = 0;
                }
                PORTD=led7seg[dem];
            }
        }

        if (PORTBbits.RB1 == 1)
        {
            __delay_ms(200);
            if (PORTBbits.RB1 == 1)
            {
                dem--;
                if (dem < 0)
                {
                    dem = 9;
                }
                PORTD=led7seg[dem];
            }
        }
        
        if (dem < 3)
        {
            RB2 = 0; 
            RB3 = 1;
            RB4 = 1;
        } 
        else if (dem >= 3 && dem <= 6)
        {
            RB2 = 1;
            RB3 = 0;
            RB4 = 1;
        } 
        else
        {
            RB2 = 1;
            RB3 = 1;
            RB4 = 0;
        }
    }
}