/*
* TEST_02_SW_LED.c
*
* Created: 2024-03-14 오후 2:10:12
* Author : kkson
*/
#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRE &= ~0xF0;					// SW 입력설정
	DDRC |= 0x0F;					// LED 출력 설정
	//unsigned char flag_led0 = 0;	// 0: LED OFF, 1: LED ON
	//unsigned char flag_led1 = 0;

	// 0000 led3,led2,led1,led0
	// unsigned char flag = 0;			// 0: pull off, 1: push on
	
	while (1)
	{
		//========================= flag 변수 사용법 ===============================
		// if (PORTC & 0x01) is continuous?
		// flag = PORTC & (0x01 << PORTC0);
// 		if(PINE == (0x01 << PINE4)) {
// 			// if(flag_led0) {
// 			if(flag & (0x01 << PORTC0)) {
// 				PORTC &= ~(0x01 << PORTC0);
// // 				flag_led0 = 0;
// 				flag &= ~(0x01 << PORTC0);
// 			} else {
// 				PORTC |= 0x01 << PORTC0;
// // 				flag_led0 = 1;
// 				flag |= 0x01 << PORTC0;
// 			}
// 			_delay_ms(300);
// 		}
// 
// 		if(PINE == (0x01 << PINE5)) {
// // 			if(flag_led1) {
// 			if(flag & (0x01 << PORTC1)) {
// 				PORTC &= ~(0x01 << PORTC1);
// // 				flag_led1 = 0;
// 				flag &= ~(0x01 << PORTC1);
// 			} else {
// 				PORTC |= 0x01 << PORTC1;
// // 				flag_led1 = 1;
// 				flag |= 0x01 << PORTC1;
// 			}
// 			_delay_ms(300);
// 		}
		//========================= PORTX 변수 사용법 ===============================
		// check SW0
		if(PINE & (0x01 << PINE4)) {
			if (PORTC & (0x01 << PORTC0)) {
				PORTC &= ~(0x01 << PORTC0);
			} else {
				PORTC |= 0x01 << PORTC0;
			}
			// _delay_ms(300); - CPU낭비 -> 엣지체크
		}
	}
}

