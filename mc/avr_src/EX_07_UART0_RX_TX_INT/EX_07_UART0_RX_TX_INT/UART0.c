/*
 * UART0.c
 *
 * Created: 2024-04-16 오전 11:40:04
 *  Author: kkson
 */ 
#include <avr/io.h>
#include <stdio.h>

void UART0_init(void)
{
	UBRR0H = 0x00;
	UBRR0L = 7;		// 9,600 bit rate
	
	// UCSR0A |= _BV(U2X1);
	UCSR0A = 0x00;
	UCSR0B |= (0x01 << TXEN0 | 0x01 << RXEN0);
	UCSR0C &= ~(0x01 << UMSEL0 | 0x01 << UPM00 | 0x01 << UPM01 | 0x01 << USBS0);
	UCSR0C |= (0x01 << UCSZ00 | 0x01 << UCSZ01);
}

void UART0_transmit(char data)
{
	while(!(UCSR0A & (0x01 << UDRE0)));
	UDR0 = data;
}

unsigned char UART0_receive(void)
{
	unsigned char data;
	while(!((UCSR0A) & (0x01 << RXC0)));
	
	data = UDR0;
	if(data != '\r')
		UART0_transmit(data);
		
	return data;
}



void UART0_print_string(const char *str)
{
	// stop if str[i] == '\0'
	for(int i = 0; str[i]; i++)
		UART0_transmit(str[i]);
}

void UART0_print_1_byte_number(uint8_t n)
{
	char numString[4] = "0";
	int i;
	
	if(n > 0) {
		// stop if (n / 10) is not 0
		for(i = 0; n != 0; ++i) {
			// convert integer to number character
			numString[i] = n % 10 + '0';
			// delete last number
			n = n / 10;
		}
		numString[i] = '\0';
		// store last index into i
	}
	
	// i: [index, 0]
	for(i = i - 1; i >= 0; --i)
		UART0_transmit(numString[i]);
}

void UART0_print_int(int n)
{
	// 0000 0000 00
	char numString[11] = "0";
	sprintf(numString, "%d", n);
	UART0_print_string(numString);
}

void UART0_print_float(float f)
{
	char numString[20] = "0.0";
	sprintf(numString, "%f", f);
	UART0_print_string(numString);
}