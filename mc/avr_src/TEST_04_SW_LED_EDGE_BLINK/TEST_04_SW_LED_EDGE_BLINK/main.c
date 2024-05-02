/*
 * TEST_04_SW_LED_EDGE_BLINK.c
 *
 * Created: 2024-03-14 오후 3:48:05
 * Author : xxxx
 */ 
#define F_CPU	14745600L

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	unsigned char flag_led0 = 0;  // 0:OFF, 1:ON
	unsigned char flag_led1 = 0;  // 0:OFF, 1:ON
	
	unsigned char pre_sw0 = 0, cur_sw0 = 0;
	unsigned char pre_sw1 = 0, cur_sw1 = 0;
	
	// setup
	DDRE &= ~0xF0;	// 스위치 입력 설정
	//DDRE &= ~( (0x01<<DDRE7)|(0x01<<DDRE6)|(0x01<<DDRE5)|(0x01<<DDRE4) );
	DDRC |= 0x0F;	// LED 출력 설정
	//DDRC |= (0x01<<DDRE3)|(0x01<<DDRE2)|(0x01<<DDRE1)|(0x01<<DDRE0);
	
	// init(초기화)
	PORTC &= ~0x03;

	while (1)
	{
		// 현재값을 갱신
		cur_sw0 = (PINE & 0x10)? 1:0;
		cur_sw1 = (PINE & 0x20)? 1:0;
		
		//SW0 체크
		if( (pre_sw0 == 0) && (cur_sw0 == 1) ){
			if( flag_led0 == 0){	// 꺼져있으면
				
				flag_led0 = 1;		// 상태값 변경
			}
			else{					// 켜져있으면

				flag_led0 = 0;		// 상태값 변경
			}
		}
		//SW1 체크
		if( (pre_sw1 == 0) && (cur_sw1 == 1) ){
			if( flag_led1 == 0){	// 꺼져있으면
				flag_led1 = 1;
			}
			else{					// 켜져있으면
				flag_led1 = 0;
			}
		}
		
		
		if(flag_led0 == 0) PORTC &= ~0x01;		// 상태값에 따른 동작 구현
		else {
			PORTC ^= 0x01;						// 상태값에 따른 동작 구현
			_delay_ms(100);
// 			PORTC &= ~0x01;
// 			_delay_ms(300);
		}

		if(flag_led1 == 0) PORTC &= ~0x02;
		else {
			PORTC ^= 0x02;
			_delay_ms(100);
		}
		
		// 현재값을 이전값에 대입
		pre_sw0 = cur_sw0;
		pre_sw1 = cur_sw1;
	}
}