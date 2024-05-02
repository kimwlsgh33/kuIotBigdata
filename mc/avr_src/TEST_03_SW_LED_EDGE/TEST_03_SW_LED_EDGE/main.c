/*
* TEST_03_SW_LED_EDGE.c
*
* Created: 2024-03-14 오후 3:18:18
* Author : kkson
*/

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>
#define BASE = 0x01;
#define SW0 = (BASE << PINE4);

int main(void)
{
	DDRE &= ~0xF0;					// SW 입력설정
	DDRC |= 0x0F;					// LED 출력 설정
	
	// 0000 led3,led2,led1,led0
	unsigned char flag_led = 0;
	// 0000 pre3,pre2,pre1,pre0
	unsigned char pre_sw = 0;
	// 0000 cur3,cur2,cur1,cur0
	unsigned char cur_sw = 0;

// 	unsigned char pre_sw0, pre_sw1;
// 	pre_sw0 = 0;
// 	pre_sw1 = 0;
// 	unsigned char cur_sw0, cur_sw1;
	

	PORTC &= ~0x01;

	// while 문 -> sw 값을 저장 -> 다음 반복에서 비교
	while (1)
	{
		// 현재 값 갱신
// 		cur_sw0 = (PINE & (0x01 << PINE4))? 1 : 0;
// 		cur_sw1 = (PINE & (0x01 << PINE5))? 1 : 0;
		// TODO : (PINE & (0x01 << PINE4))? PINE |=  : 0;

		//========================= flag 변수 사용법 ===============================
		if(cur_sw0 && pre_sw0 == 0) {
			if(flag_led & (0x01 << PORTC0)) {
				PORTC &= ~(0x01 << PORTC0);
				flag_led &= ~(0x01 << PORTC0);
			} else {
				PORTC |= 0x01 << PORTC0;
				flag_led |= 0x01 << PORTC0;
			}
			// _delay_ms(300);
		}

		if(cur_sw1 && pre_sw1 == 0) {
			if(flag_led & (0x01 << PORTC1)) {
				PORTC &= ~(0x01 << PORTC1);
				flag_led &= ~(0x01 << PORTC1);
			} else {
				PORTC |= 0x01 << PORTC1;
				flag_led |= 0x01 << PORTC1;
			}
			// _delay_ms(300);
		}

		// 현재 값을 이전값에 대입
		pre_sw0 = cur_sw0;
		pre_sw1 = cur_sw1;
	}
}