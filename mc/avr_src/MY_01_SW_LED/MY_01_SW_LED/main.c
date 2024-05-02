/*
 * MY_01_SW_LED.c
 *
 * Created: 2024-03-14 오후 2:52:18
 * Author : kkson
 */ 
#define F_CPU	14745600L
#include <avr/io.h>


int main(void)
{
	unsigned char sw[] = {DDRE4, DDRE5, DDRE6, DDRE7};
	// set switches into 0 
	for (int i = 0; i < 4; ++i) {
		DDRE &= ~(0x01 << sw[i]);
	}
	DDRC |= 0xFF; // set LED into 1

	// 0000 led3,led2,led1,led0
	unsigned char flags = 0;
    while (1) 
    {
		if (PINE & (0x01 << sw[0])) {
			
		}
    }
}

