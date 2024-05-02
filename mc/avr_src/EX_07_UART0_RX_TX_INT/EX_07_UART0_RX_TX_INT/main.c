/*
 * EX_07_UART0_RX_TX_INT.c
 *
 * Created: 2024-04-16 오후 2:16:29
 * Author : kkson
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <string.h>
#include "UART0.h"

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

// 수신완료 인터럽트 서비스 루틴

SIGNAL(USART0_RX_vect) {
	cli(); // 타 인터럽트 중지
	static unsigned char str_cnt = 0;
	unsigned char data = UDR0;
	if (data == '\r' || str_cnt == 99){
		rx_str[str_cnt] = '\0';
		str_cnt = 0;
		
		run_command(rx_str);
		UART0_print_string(rx_str);
	} else {
		rx_str[str_cnt++] = data;
	}
	sei(); // 타 인터럽트 허용
}

void LED_init(void) {
	DDRC |= (1 << PORTC0);
}

// 다른 하드웨어끼리의 통신을 할때, 전위레벨을 맞춰주기 위해서 GND를 연결해주어야 한다. (0, 1을 올바르게 받기위해)
int main(void)
{
	LED_init();
    UART0_init();
	// UART0_Rx_Interrupt();
	UCSR0B |= (1 << RXCIE0);	// 수신완료 개별 인터럽트 허용
	sei();						// 전체 인터럽트 허용
	
    while (1) 
    {
		if(i_flag == 0) {
			UART0_print_string("\n\r명령어를 입력하세요. : ");
			i_flag = 1;	
		}
		
// 		if(strcasecmp(rx_str, "LED_ON") == 0) {
// 			PORTC |= (1 << PORTC0);
// 			i_flag = 0;
// 			// rx_str[0] = '\0';
// 			for(int i = 0; i < 10; ++i)
// 				rx_str[i] = '\0';
// 		} else if (strcasecmp(rx_str, "LED_OFF") == 0) {
// 			PORTC &= ~(1 << PORTC0);
// 			i_flag = 0;
// 			// rx_str[0] = '\0';
// 			for(int i = 0; i < 10; ++i)
// 				rx_str[i] = '\0';
// 		}
    }
}

