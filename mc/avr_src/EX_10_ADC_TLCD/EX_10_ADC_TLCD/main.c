/*
 * EX_10_ADC_TLCD.c
 *
 * Created: 2024-04-17 오후 12:51:30
 * Author : kkson
 */ 
#define F_CPU 14745600
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "Text_LCD.h"

uint8_t MODE = 4;

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

int main(void)
{
	int read;
	double volt = 0.0;
	char str[30] = {'\0'};
	
	LCD_init();
	ADC_init(1);
	
    while (1) 
    {
		// LCD_clear();
		
		read = read_ADC();
		volt = read * (3.3/1024.0);
		
		LCD_goto_XY(0, 0);
		sprintf(str, "%3d, %.2f V", read, volt);
		LCD_write_string(str);
		
		_delay_ms(1000);
    }
}

