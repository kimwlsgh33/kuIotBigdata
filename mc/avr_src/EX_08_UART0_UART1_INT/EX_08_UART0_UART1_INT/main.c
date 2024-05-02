/*
 * EX_08_UART0_UART1_INT.cpp
 *
 * Created: 2024-04-16 오후 4:26:48
 * Author : kkson
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "UART.h"

char rx_str[100] = {0};
int i_flag = 0;

void run_command(const char *str) {
	if(strcasecmp(str, "LED_ON") == 0) {
		PORTC |= (1 << PORTC0);
		i_flag = 0;
	} else if (strcasecmp(str, "LED_OFF") == 0) {
		PORTC &= ~(1 << PORTC0);
		i_flag = 0;
	} else {
		UART0_print_string("THERE IS NO COMMAND FOR : ");
		i_flag = 0;
	}
}

SIGNAL(USART0_RX_vect){ // from My PC
	cli();
	// unsigned char data = data;
	UART1_transmit(UDR0);
	sei();
}
	
SIGNAL(USART1_RX_vect){ // from MN's MCU
	cli();
	// unsigned char data = UDR1;
	// UART0_transmit(UDR1);
	
	static unsigned char str_cnt = 0;
	unsigned char data = UDR1;
	if (data == '\r' || str_cnt == 99){
		rx_str[str_cnt] = '\0';
		str_cnt = 0;
		
		run_command(rx_str);
		// UART0_print_string(rx_str);
	} else {
		rx_str[str_cnt++] = data;
		UART0_transmit(data);
	}
	sei();
}

void LED_init(void) {
	DDRC |= (1 << PORTC0);
}

int main(void)
{

	LED_init();
	
	UART0_init();
	UCSR0B |= (1 << RXCIE0);
	
	UART1_init();
	UCSR1B |= (1 << RXCIE1);
	
	sei();
    
    while (1) 
    {
		if(i_flag == 0) {
			UART0_print_string("\n\r명령어를 입력하세요. : ");
			i_flag = 1;
		}
    }
}

