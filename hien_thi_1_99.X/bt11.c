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
#define _XTAL_FREQ 20000000  // ??nh ngh?a t?n s? th?ch anh

unsigned char seg7[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void main(void) {
    int dem = 1; 
    int hangchuc;
    int hangdonvi;
    int direction = 1; 

    TRISB = 0x00;  
    TRISC = 0x00; 
    PORTB = 0x00;  
    PORTC = 0x00;  

    while(1) {
        
        hangdonvi = dem % 10; 
        hangchuc = dem / 10;  

        for (int i = 0; i < 100; i++) { 

            PORTC = 0x02;
            PORTB = seg7[hangchuc];
            __delay_ms(5);  

            PORTC = 0x01;
            PORTB = seg7[hangdonvi];
            __delay_ms(5);  
        }

        dem += direction; 
        if(dem > 99) {
            dem = 99;
            direction = -1; 
        } else if(dem < 1) {
            dem = 1;
            direction = 1; 
        }
    }
}
