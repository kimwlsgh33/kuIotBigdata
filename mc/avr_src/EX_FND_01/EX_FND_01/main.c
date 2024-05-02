/*
 * EX_FND_01.c
 *
 * Created: 2024-03-13 오후 3:50:34
 * Author : xxxx
 */ 
#define F_CPU	14745600L
#include <avr/io.h>
#include <util/delay.h>

void ON_FND_LED(uint8_t pin);
void ON_FND_NUM(uint8_t pin);

int main(void)
{
	// FND: PORTA 0 ~ 7, A H
	// 0 ~ F
    DDRA = 0xFF;
	unsigned char nums[] = {
		0x3F,0X06,0X5B,0X4F,0X66,0X6D,
		0X7C,0X07,0X7F,0X67,0X77,0X7C,
		0X39,0X5E,0X79,0X71 // ,0X08,0X80
	};
	
	while (1) 
    {
		// PORTA = 0x3F; // FND : 0
		for (int i = 0; i < 16; ++i) {
			// ON_FND_NUM(i);
			PORTA = nums[i];
			_delay_ms(500);
		}
    }
}

void ON_FND_LED(unsigned char pin){
	PORTA |= pin;
}

void OFF_FND_LED(unsigned char pin){
	
}

void ON_FND_NUM(unsigned char num){
	ON_FND_LED('A');
	ON_FND_LED('B');
	ON_FND_LED('C');
	ON_FND_LED('D');
	ON_FND_LED('E');
	ON_FND_LED('F');
	OFF_FND_LED('G');
	OFF_FND_LED('H');
}
