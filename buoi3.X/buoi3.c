

#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)

#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)

#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)

#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)

#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)

#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)

#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)

#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 20000000

// #pragma config statements should precede project file includes.

// Use project enums instead of #define for ON and OFF.

//macro
#define LED1     RC0
#define LED2     RC1
#include <xc.h>

unsigned char segments_code[10] = {0xC0,0xF9,0xA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};

int data = 69;
int count = 0;
void display(int numberIn);
void main(void) {

    TRISB  = 0x00;

    TRISC0 = 0;

    TRISC1 = 0;

    

    while(1)

    {

       // A time 00.00

        display(count);

       // B time 03.00

        count++;
        if(count>=99)
        {
            count=0;
        }

       // C time 03.00

    }

}

// 1, 45

void display(int numberIn){

    int chuc  = numberIn / 10; // 78 /10 = 7.8 

    int donvi = numberIn % 10;

    // delay 10ms cho ham display nhung chung ta se lap lai 300 lan de cho tron 3s

    for(int i = 0; i < 300; i++)

    {

        // Gian du lieu sang la so hang chuc

        PORTB = segments_code[chuc];

        // cho led hang chuc

        LED1  = 1;

        // delay sang 5ms

        __delay_ms(5);

        // tat led 1

        LED1 = 0;

        

        // Gian du lieu sang cho led don vi

        PORTB = segments_code[donvi];

        LED2 = 1;

        __delay_ms(5);

        LED2 = 0;

    }

    



}
