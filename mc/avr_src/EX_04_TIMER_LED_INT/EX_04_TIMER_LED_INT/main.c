/*
 * EX_04_TIMER_LED_INT.c
 *
 * Created: 2024-03-18 오후 12:24:28
 * Author : kkson
 */ 
#define F_CPU	14745600 // 1024 = 14400
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned char LED_Data = 0x00;
unsigned char timer0Cnt = 0, timer2Cnt = 0;

// Interrupt Service Routine

SIGNAL(TIMER0_OVF_vect) {
	cli();
	TCNT0 = 112;	// Reset Timer Counter -> 0.01 s -> 256 - 144 -> 112
	
	++timer0Cnt;
	
	// 1초마다 실행
	if(timer0Cnt == 100) {
		PORTC ^= (0x01 << PORTC0);
		timer0Cnt = 0;
	}
	
	sei();
}


SIGNAL(TIMER0_COMP_vect) {
	cli();
	TCNT0 = 0;
	
	++timer0Cnt;
	
	// 1초마다 실행
// 	if(timer0Cnt == 30) {
// 		PORTC ^= (0x01 << PORTC0);
// 		timer0Cnt = 0;
// 	}
	if(0 <= timer0Cnt && timer0Cnt <= 1) {
		PORTC |= (0x01 << PORTC0);
	} else if (2 <= timer0Cnt && timer0Cnt <= 9) {
		PORTC &= ~(0x01 << PORTC0);
	}
	
	if(timer0Cnt == 9) {
		timer0Cnt = 0;
	}
	
	sei();
}


SIGNAL(TIMER2_COMP_vect) {
	cli();
	TCNT2 = 0;
	
	++timer2Cnt;
	
	// 0.5초마다 실행
	if(timer2Cnt == 50) {
		PORTC ^= (0x01 << PORTC1);
		timer2Cnt = 0;
	}
	
	sei();
}


int main(void)
{
    DDRC |= 0x0F;
	PORTC |= 0x0F;
	// PORTC &= ~0x0F;
	// PORTC |= (0x01 << PORTC2 | 0x01 << PORTC3);
	
	// Timer Counter Control (F_CPU/1024)
	TCCR0 |= (0x01 | 0x01 << 1 | 0x01 <<2);
	//TCNT0 = (256 - 144);		// Overflow interrupt starting count 112 = 256 - 144
	TCNT0 = 0;					// Output Compare interrupt starting count 0
	// OCR0 = 144 - 1;
	OCR0 = 11 - 1;
	//TIMSK |= 0x01 << TOIE0;	// Timer Interrupt MaSK - Timer Overflow Interrupt Enable
	TIMSK |= 0x01 << OCIE0;		// Timer Output Compare Interrupt Enable
	TIFR |= 0x01 << OCF0;			// Timer Interrupt Flag - Timer Overflow
	
	
	TCCR2 |= (0x01 | 0x01 <<2);	// 1?1
	TCCR2 &= ~(0x01 << 1);		// 101
	TCNT2 = 0;
	OCR2 = 144 - 1;
	
	TIMSK |= 0x01 << OCIE2;
	TIFR |= 0x01 << OCF2;
	
	
	sei();
	
    while (1) 
    {
    }
}

