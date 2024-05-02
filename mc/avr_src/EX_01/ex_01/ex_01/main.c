/*
 * ex_01.c
 *
 * Created: 2024-03-12 오후 4:17:45
 * Author : xxxx
 */ 
// #define F_CPU	16000000L
#include <avr/io.h>		// AVR 입출력에 대한 헤더 파일
#include <util/delay.h>	// delay 함수사용을 위한 헤더 파일
#include <stdio.h>

int main(void)
{
	//unsigned char LED_Data = 0x00;
	//unsigned char LED_Data = 0x01;
	DDRC |= 0x0F;	// Data Direction Register C - 포트C의 입출력 방향을 결정하는 레지스터
	
	unsigned char arr[] = {0x01, 0x04, 0x08};
		
	// until specific time.
    while (1)
    {
		for (int i = 0; i < 3; ++i) {
			PORTC = arr[i];
			_delay_ms(1000);
		}
		// Generic Code - Shift Operator
// 		for (int i = 0; i < 4; ++i) {
// 			PORTC = 0x01 << i;
// 			_delay_ms(1000);
// 		}
// 		PORTC = 0x01;
// 		_delay_ms(1000);
// 		PORTC = 0x02;
// 		_delay_ms(1000);
// 		PORTC = 0x04;
// 		_delay_ms(1000);
// 		PORTC = 0x08;
// 		_delay_ms(1000);
// 		PORTC = 0x10;
// 		_delay_ms(1000);
// 		PORTC = 0x20;
// 		_delay_ms(1000);
// 		PORTC = 0x40;
// 		_delay_ms(1000);
// 		PORTC = 0x80;
// 		_delay_ms(1000);
		
		// PORT + C
		//PORTC = LED_Data;	// 데이터를 출력할때 사용하는 PORT레지스터 C
		// 포트C로 변수 LED_Data 데이터 출력
		
		// LED_Data++;			// LED_Data값을 1씩 증가
		//LED_Data *= 2;			// LED_Data값을 2배 증가
		
		// 0x01 -> 0x02 -> 0x04 -> 0x08 -> 0x10
		
		// LED_Data값이 0x0F 보다 크면 0으로 초기화
		//if(LED_Data > 0x0F) LED_Data = 0;
		
		// LED_Data값이 0x08 보다 크면 0으로 초기화
		//if(LED_Data > 0x08) LED_Data = 1;
		//_delay_ms(1000);	// 1s 시간 지연
		
		//PORTA |= 0x01;	// PA0 LED ON
		//PORTA &= ~0x01;	// PA0 LED OFF
		
		// 데이터를 입력할때 사용하는 PIN레지스터 A
		//unsigned char SOME_INPUT = PINA;
    }
}

