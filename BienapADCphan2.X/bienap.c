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

unsigned char digital[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
unsigned char dot[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};

void ADC_Init() {
    ADCON0 = 0x41; 
    ADCON1 = 0x80; 
}

unsigned int ADC_Read(int channel) {
    if (channel > 7)
        return 0;
    ADCON0 &= 0xC5; 
    ADCON0 |= (channel << 3); 
    __delay_ms(2);
    GO_nDONE = 1; 
    while (GO_nDONE); 
    return ((ADRESH << 8) + ADRESL); 
}

void display(float voltage) {
    int integer_part, decimal_part;
    int i;

    integer_part = (int) voltage;
    decimal_part = (int) ((voltage - integer_part) * 10);

    for (i = 0; i < 125; i++) {
        PORTB = digital[integer_part];
        RC0 = 1; 
        __delay_ms(5);
        RC0 = 0; 
        PORTB = digital[decimal_part];
        RC1 = 1; // Enable second 7-segment display
        __delay_ms(5);
        RC1 = 0; // Disable second 7-segment display
    }
}

void main(void) {
    TRISB = 0x00; // Set PORTB as output
    PORTB = 0x00; // Clear PORTB
    TRISC = 0x00; // Set PORTC as output
    TRISA = 0xFF; // Set PORTA as input
    ADC_Init(); // Initialize ADC

    unsigned int value_adc;
    float voltage;

    while (1) {
        value_adc = ADC_Read(0); // Read ADC value from channel 0
        voltage = (value_adc * 1023) / 50; // Convert ADC value to voltage (0-5V range)
        
        // Display voltage on 7-segment display
        display(voltage);
    }
}
