/*
 * EX_09_ADC0_UART0.c
 *
 * Created: 2024-04-17 오전 10:06:57
 * Author : kkson
 */ 

#define F_CPU 14745600
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "UART.h"

void ADC_init(unsigned char channel){
	// ADC Multiplexer Selection
	// AREF (REFS1: 0, REFS0: 0)
	// Right Align
	// channel 0 -> 0x00
	ADMUX = ((ADMUX & 0xE0) | channel);
	
	// ADC Control and Status Register A
	ADCSRA |= 0x07;	// 111: 128분주
	ADCSRA |= (1 << ADEN | 1 << ADFR);	// ADC Enable, ADC Free Running (연속)
	ADCSRA |= (1 << ADSC);	// ADC Start Conversion
}

int read_ADC(void) {
	while(!(ADCSRA & (1 << ADIF)));	// ADC Interrupt Flag
	return ADC;	// 
}

// Analog -> Digital
// Ref: 3.3V
// 1024
// 651
// == 전압값
int main(void)
{
	int read;
	double volt = 0.0;
	char str[30] = {'\0'};
	
	UART0_init();
	ADC_init(0);
    
    while (1) 
    {
		read = read_ADC();
		volt = read * (3.3/1024.0);
		sprintf(str, "%d, %.2f V\n", read, volt);
		
		UART0_print_string(str);
		
		_delay_ms(1000);
    }
}

