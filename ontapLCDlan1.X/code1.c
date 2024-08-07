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
#define RS RD2
#define EN RD3
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7
#include "Lcd.h"

void main(void) {
    TRISB = 0x03;  // RB0 và RB1 là ??u vào
    TRISD = 0x00;  // PORTD là ??u ra
    Lcd_Init();

    unsigned char prevStateRB0 = PORTBbits.RB0;
    unsigned char prevStateRB1 = PORTBbits.RB1;

    while(1) {
        // Ki?m tra tr?ng thái nút b?m RB0
        if(PORTBbits.RB0 != prevStateRB0) {
            prevStateRB0 = PORTBbits.RB0;
            Lcd_Set_Cursor(1,1);
            if(PORTBbits.RB0 == 0) { 
                Lcd_Write_String("A    ");
            } 
            else 
            {
                Lcd_Write_String("B   ");
            }
        }

        // Ki?m tra tr?ng thái nút b?m RB1
        if(PORTBbits.RB1 != prevStateRB1) {
            prevStateRB1 = PORTBbits.RB1;
            Lcd_Set_Cursor(2,1);
            if(PORTBbits.RB1 == 0) { 
                Lcd_Write_String("C  ");
            } 
            else
            {
                Lcd_Write_String("D");
            }
        }
    }
}
