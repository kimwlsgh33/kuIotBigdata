/*
* EX_LED_01.c
*
* Created: 2024-03-13 오후 12:32:16
* Author : xxxx
*/

#include <avr/io.h>
#include <util/delay.h>

// 임베디드에는 int 형이 2B 인 경우가 있다
// uint32_t => system programming, 어느 하드웨어에서 라도, 32bit를 사용하도록 하기

// 함수 선언
void FUNC_LED_ON(uint8_t numPin);
void FUNC_LED_OFF(uint8_t numPin);
void FUNC_LED_TOGGLE(uint8_t numPin);

// Custom
void FUNC_LED_ON2(uint8_t numPin);
void FUNC_LED_OFF2(uint8_t numPin);
void FUNC_ORDER_BY_ASC(void);
void FUNC_ORDER_BY_DESC(void);
// LED 4개 다키는 함수
// LED

int main(void)
{
	/* Replace with your application code */
	DDRC = 0x0F;
	while (1)
	{
		// 		FUNC_LED_ON(0);
		// 		FUNC_LED_ON(1);
		// 		FUNC_LED_ON(2);
		// 		FUNC_LED_ON(3);
		// 		_delay_ms(100);
		// 		FUNC_LED_OFF(0);
		// 		FUNC_LED_OFF(1);
		// 		FUNC_LED_OFF(2);
		// 		FUNC_LED_OFF(3);
		// 		_delay_ms(100);

		for (int i = 0; i < 4; ++i) {
			//FUNC_LED_ON2(i);
			FUNC_LED_TOGGLE(i);
			_delay_ms(100);
		}
		
		_delay_ms(500);
		
		for (int i = 0; i < 4; ++i) {
			//FUNC_LED_OFF2(3 - i);
			FUNC_LED_TOGGLE(3 - i);
			_delay_ms(100);
		}

		// (매개변수, parameter)
		// FUNC_ORDER_BY_ASC();
		// FUNC_ORDER_BY_DESC();
	}
}

// 함수 구현 (implementation)
// (인자, argument)
void FUNC_LED_ON(unsigned char numPin) {
	//PORTC = 0x00;
	switch (numPin)
	{
		case 0:
		// PORTC = PORTC | 0x01;
		PORTC |= 0x01;
		break;
		case 1:
		// PORTC = PORTC | 0x02;
		PORTC |= 0x02;
		break;
		case 2:
		// PORTC = PORTC | 0x04;
		PORTC |= 0x04;
		break;
		case 3:
		// PORTC = PORTC | 0x08;
		PORTC |= 0x08;
		break;
		default:
		PORTC = 0x00;
	}
}

void FUNC_LED_OFF(unsigned char numPin) {
	
	switch (numPin)
	{
		case 0:
		// 1111 1110
		// PORTC = PORTC & 0xFE;
		// PORTC &= 0xFE;
		
		// ~ 0000 0001 => 1111 1110
		PORTC &= ~0x01;
		break;
		case 1:
		// 1111 1101
		// PORTC = PORTC & 0xFD;
		// PORTC &= 0xFD;
		PORTC &= ~0x02;
		break;
		case 2:
		// 1111 1011
		// PORTC = PORTC & 0xFB;
		// PORTC &= 0xFB;
		PORTC &= ~0x04;
		break;
		case 3:
		// 1111 0111
		// PORTC = PORTC & 0xF7;
		// PORTC &= 0xF7;
		PORTC &= ~0x08;
		break;
		default:
		PORTC = 0x00;
	}
	//PORTC = 0x0F;
}


void FUNC_LED_ON2(unsigned char numPin){
	PORTC |= 0x01 << numPin;
}

void FUNC_LED_OFF2(unsigned char numPin){
	PORTC &= ~(0x01 << numPin);
}

// void FUNC_GPIO(PORTA, 0, 0); // 포트, 핀, 모드

void FUNC_LED_TOGGLE(unsigned char numPin){
	// 1111 1110 ^ 0000 0001 => 1111 1111
	// 1111 1111 ^ 0000 0001 => 1111 1110
	// reversed by `exclusive or`
	PORTC ^= 0x01 << numPin;
}



void FUNC_ORDER_BY_ASC(void) {
	PORTC = 0x00;
	unsigned char adder = 0x01;
	
	for (int i = 0; i < 4; ++i) {
		PORTC += adder << i;
		_delay_ms(100);
	}
	
	// 	PORTC = 0x03;
	// 	PORTC = 0x07;
	// 	PORTC = 0x0F;
};

void FUNC_ORDER_BY_DESC(void) {
	PORTC = 0x0F;
	unsigned char sub = 0x01;
	
	for (int i = 3; i > 0; --i) {
		_delay_ms(100);
		PORTC -= sub << i;
	}
	
	_delay_ms(100);
}