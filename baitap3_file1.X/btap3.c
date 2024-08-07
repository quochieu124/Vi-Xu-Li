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
#define _XTAL_FREQ 20000000  // ??nh ngh?a t?n s? dao ??ng là 20MHz

void main(void) {
    TRISE = 0x00;  // C?u hình các chân RE là ??u ra
    PORTE = 0x00;  // Xóa d? li?u trên c?ng E

    while(1) {
        // Sáng l?n l??t LED1, LED2, LED3 v?i chu k? 0.1s
        PORTEbits.RE0 = 1;  // B?t LED1
        __delay_ms(100);    // ??i 0.1 giây
        PORTEbits.RE0 = 0;  // T?t LED1
        __delay_ms(100);    // ??i 0.1 giây
        
        PORTEbits.RE1 = 1;  // B?t LED2
        __delay_ms(100);    // ??i 0.1 giây
        PORTEbits.RE1 = 0;  // T?t LED2
        __delay_ms(100);    // ??i 0.1 giây
        
        PORTEbits.RE2 = 1;  // B?t LED3
        __delay_ms(100);    // ??i 0.1 giây
        PORTEbits.RE2 = 0;  // T?t LED3
        __delay_ms(100);    // ??i 0.1 giây

        // Nh?p nháy c? 3 LED 2 l?n v?i chu k? 1s
        for (int i = 0; i < 2; i++) {
            PORTEbits.RE0 = 1;  // B?t LED1
            PORTEbits.RE1 = 1;  // B?t LED2
            PORTEbits.RE2 = 1;  // B?t LED3
            __delay_ms(1000);   // ??i 1 giây

            PORTEbits.RE0 = 0;  // T?t LED1
            PORTEbits.RE1 = 0;  // T?t LED2
            PORTEbits.RE2 = 0;  // T?t LED3
            __delay_ms(1000);   // ??i 1 giây
        }
    }
}
