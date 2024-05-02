/*
 * EX_SW_02.c
 *
 * Created: 2024-03-13 오후 4:31:25
 * Author : xxxx
 */ 

#define F_CPU	14745600L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// DDRE 4 ~ 7 => 0
	
	// 1111 1111 & 0000 1111 (0x0F)
	// 1111 1111 & ~1111 0000 ~(0xF0)
// 	for (int i = 0; i < 4; ++i) {
// 		DDRE &= 0x04;
// 	}

	DDRE &= ~0xF0; // SW 입력설정
	// It's useful to maintain.
	// DDRE &= ~((0x01 << DDRE7) | (0x01 << DDRE6) | (0x01 << DDRE5) | (0x01 << DDRE4));
	
	DDRC |= 0x0F; // LED 출력 설정
	// DDRC |= (0x01 << DDRE7) | (0x01 << DDRE6) | (0x01 << DDRE5) | (0x01 << DDRE4);
	
    while (1) 
    {
		// PINE : SW 입력 저장 - Hz 마다, Input 값을 확인해준다
		// PORTC = PINE >> 4;
		
		//					7654 3210
		// first	PINE	1010 0000
		// prev		PORTC	0111 0101
		// result	PORTC	0111 1010
		
		// Method 1
		// PINE >> 4		OR(0000) AND(1010)
		
		
		
		//PORTC &= 0xF0;					// 0111 0101 => 0111 0000
		//unsigned char tmp = PINE >> 4;	// tmp:			0000 1010
		//PORTC |= tmp;					// result:		0111 1010
		
// 		if(PINE == 0x10) {
// 			PORTC |= 0x01;
// 		} else {
// 			PORTC &= ~0x01;
// 		}
// 		
// 		if(PINE == 0x20) {
// 			PORTC |= 0x02;
// 		} else {
// 			PORTC &= ~0x02;
// 		}
// 		
// 		if(PINE == 0x40) {
// 			PORTC |= 0x04;
// 		} else {
// 			PORTC &= ~0x04;
// 		}
// 		
// 		if(PINE == 0x80) {
// 			PORTC |= 0x08;
// 		} else {
// 			PORTC &= ~0x08;
// 		}

// 		if (PINE & 0x10) {
		if (PINE & (0x01 << PINE4)) {
//  		PORTC |= 0x01;
			PORTC |= 0x01 << PORTC0;
 		} else {
//  			PORTC &= ~0x01;
			PORTC &= ~(0x01 << PORTC0);
 		}
		 
// 		if (PINE & 0x20) {
		if (PINE & (0x01 << PINE5)) {
// 			PORTC |= 0x02;
			PORTC |= 0x01 << PORTC1;
		} else {
// 			PORTC &= ~0x02;
			PORTC &= ~(0x01 << PORTC1);
		}
		
// 		if (PINE & 0x40) {
		if (PINE & (0x01 << PINE6)) {
// 			PORTC |= 0x04;
			PORTC |= 0x01 << PORTC2;
		} else {
			PORTC &= ~0x04;
		}
		
// 		if (PINE & 0x80) {
		if (PINE & (0x01 << PINE7)) {
// 			PORTC |= 0x08;
			PORTC |= 0x01 << PORTC3;
		} else {
			PORTC &= ~0x08;
		}
	
// 		for (int i = 0; i < 4; ++i) {
// 			if (PINE & (0x10 << i)) {
// 				PORTC |= 0x01 << i;
// 			} else {
// 				PORTC &= ~(0x01 << i);
// 			}
// 		}
	}
}

