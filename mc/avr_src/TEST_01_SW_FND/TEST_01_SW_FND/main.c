/*
 * TEST_01_SW_FND.c
 *
 * Created: 2024-03-14 오전 11:16:50
 * Author : kkson
 */ 
// FND -> 0 출력
// SW0 입력 -> count
// SW1 입력 -> FND 0
// SW2 입력 -> count down
// FND : 0 ~ F

#define F_CPU	14745600L
#include <avr/io.h>


int main(void)
{
	// SW0, SW1, SW2 -> 0 (input)
	DDRE &= ~(0x01 << DDRE4 | 0x01 << DDRE5 | 0x01 << DDRE6);
	// FND0 ~ FND7 -> 1 (output)
	// DDRA = (0x01 << DDRA0 | 0x01 << DDRA1 | 0x01 << DDRA2 | 0x01 << DDRA3 | 0x01 << DDRA4 | 0x01 << DDRA5 | 0x01 << DDRA6 | 0x01 << DDRA7);
	DDRA = 0xFF;
	// DDRD |= (0x01 << DDRD4 | 0x01 << DDRD5);

	unsigned char fnd[] = {
		0X3F,0X06,0X5B,0X4F,0X66,0X6D,
		0X7C,0X07,0X7F,0X67,0X77,0X7C,
		0X39,0X5E,0X79,0X71
	};

	PORTA = fnd[0]; // 0 출력
	// char cnt = 0;	// [-2^4,2^4)
	unsigned char cnt = 0;
	unsigned char prev = 0;
	
    while (1) 
    {
		// PORTA = FND[cnt];
		// SW0 == true
		if (PINE & (0x01 << PINE4)) {
			// 0x3F -> 0x06, [0] -> [1] -> [2] -> ...
// 			if(status) {
// 				// do nothing..
// 			} else if (cnt < 15) {
// 				cnt++;
// 				status = 1;
// 			} else {
// 				cnt = 0;
// 			}

			// 처음 누르는 경우
			if(prev == 0) {
				cnt++;
				prev = 1; // 누르고 있다
			}
			if (cnt > 15) cnt = 0;
			PORTA = fnd[cnt];
		// SW2 == true
		} else if (PINE & (0x01 << PINE6)) {
			if(prev == 0) {
				if (cnt == 0) {
					cnt = 15;
				} else {
					cnt--;
					prev = 1;
				}
			}
			PORTA = fnd[cnt];
		} else {
			// SW0 == false
			prev = 0;
		}
		
		// SW1 == true
		if (PINE & (0x01 << PINE5)) {
			cnt = 0;
			PORTA = fnd[cnt];
		}
	}
}

