/*
 * TEST_06_BLINK_LED_SW_INT_TIMER.c
 *
 * Created: 2024-03-18 오후 4:30:25
 * Author : kkson
 */ 
#define F_CPU	14745600
#include <avr/io.h>
#include <avr/interrupt.h>


unsigned char led_flag0 = 0, led_flag1 = 0;
unsigned char timer_cnt0 = 0, timer_cnt1 = 0;


SIGNAL(INT4_vect) {
	cli();
	led_flag0 ^= 0x01;
	sei();
}


SIGNAL(INT5_vect) {
	cli();
	led_flag1 ^= 0x01;
	sei();
}


SIGNAL(TIMER0_COMP_vect) {
	cli();
	if (timer_cnt0 == 143) {
		timer_cnt0 = 0;
	}
	timer_cnt0++;
	sei();
}


SIGNAL(TIMER2_COMP_vect) {
	cli();
	if (timer_cnt1 == 143) {
		timer_cnt1 = 0;
	}
	timer_cnt1++;
	sei();
}


int main(void)
{
	// Set SW0,1 direction to Input
	DDRE &= ~(0x01 << PINE4 | 0x01 << PINE5);
	// Set LED0,1 direction to Output
	DDRC |= (0x01 << PORTC0 | 0x01 << PORTC1);
	
	// Init SW0,1
	PINE &= ~(0x01 << PINE4 | 0x01 << PINE5);
	// Init LED0,1
	PORTC &= (0x01 << PORTC0 | 0x01 << PORTC1);
	
	// Set external interrupt control to rising edge
	EICRB |= (0x01 | 0x01 << 1 | 0x01 << 2 | 0x01 << 3);
	// Clear external interrupt flag to 0
	EIFR |= (0x01 << PINE4 | 0x01 << PINE5);
	// Mask external interrupt to 1
	EIMSK |= (0x01 << PINE4 | 0x01 << PINE5);
	// Enable global interrupt
	sei();
	
	// Set Timer0, 2 control to prescale 1024 (14400)
	TCCR0 |= (0x01 | 0x01 << 1 | 0x01 << 2);	// 0000 0111
	TCCR2 |= (0x01 | 0x01 << 2);				// 0000 01?1
	TCCR2 &= ~(0x01 << 1);						// 0000 0101

	// Clear Timer0, 2 interrupt flag
	TIFR |= (0x01 << OCF0 | 0x01 << OCF2);
	
	// Set Timer Count
	TCNT0 = 0;
	TCNT2 = 0;
	
	// Set Output Compare Value
	
	OCR0 = 144 - 1;
	OCR2 = 144 - 1;
	
	// Mask Timer0, 2 interrupt to 0
	TIMSK |= (0x01 << OCIE0 | 0x01 << OCIE2);
	
    while (1) 
    {
		if(led_flag0) PORTC |= 0x01;
		else PORTC &= ~0x01;
		
		if(led_flag1) PORTC |= 0x01 << PORTC1;
		else PORTC &= ~(0x01 << PORTC1);
    }
}

