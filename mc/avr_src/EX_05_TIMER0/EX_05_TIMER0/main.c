/*
 * EX_05_TIMER0.c
 *
 * Created: 2024-04-15 오전 11:53:33
 * Author : kkson
 */ 
#define F_CPU 14745600
#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char LED_Data = 0;
unsigned char timer0Cnt = 0, brightness = 128;

// Timer0 Overflow 
SIGNAL(TIMER0_OVF_vect){
	cli();
	PORTC &= ~(0x01 << PORTC0);
	PORTC |= (0x01 << PORTC1);
	sei();
}

// Timer0 Output Compare
SIGNAL(TIMER0_COMP_vect){
	cli();
	PORTC |= (0x01 << PORTC0);
	PORTC &= ~(0x01 << PORTC1);
	sei();
}

SIGNAL(INT4_vect){
	cli();
	// 밝게
	if (brightness >= 230) {
		brightness = 255;
	} else {
		brightness += 25;
	}
	OCR0 = brightness;
	sei();
}

SIGNAL(INT5_vect){
	cli();
	// 어둡게
	if (brightness <= 25) {
		brightness = 0;
	} else {
		brightness -= 25;
	}
	OCR0 = brightness;
	sei();
}

	
int main(void)
{
	// Set LED direction
	DDRC |= 0x0F;
	// Set Switch direction
	DDRE &= ~(0x01 << PINE4 | 0x01 << PINE5);
	
	// Set interrupt
	EICRB |= (0x01 << ISC40 | 0x01 << ISC41 | 0x01 << ISC50 | 0x01 << ISC51);
	EIMSK |= (0x01 << INT4 | 0x01 << INT5);
	EIFR |= (0x01 << INTF4 | 0x01 << INTF5);
	
	// Timer/Counter Control Register
	// Pre-scale by 1024 (14400)
	// TCCR0 |= (0x01 << CS00 | 0x01 << CS01 | 0x01 << CS02);
	// Pre-scale by 256 (57600)
	TCCR0 &= ~(0x01 << CS00);
	TCCR0 |= (0x01 << CS01 | 0x01 << CS02);
	
	// Set initial count
	// TCNT0 = 112; // 256 - 144, Overflow
	TCNT0 = 0;
	OCR0 = brightness; // Output Compare
	
	// Interrupt by Overflow
	TIMSK |= 0x01 << TOIE0;
	// Interrupt by Output Compare
	TIMSK |= (0x01 << OCIE0);
	
	// Clear flag when the interrupt is done.
	TIFR |= (0x01 << TOV0);
	TIFR |= (0x01 << OCF0);
	
	// Enable global interrupt
	sei();
	
    while (1) 
    {
    }
}

