/*
 * TEST_05_SW_MOTOR_INT.c
 *
 * Created: 2024-03-18 오전 9:22:14
 * Author : kkson
 */ 
#define F_CPU	14745600

#define STOP	0
#define CW		1
#define CCW		2
#define BREAK	3

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void setDD(void);
void initINT(void);
void enINT(void);

// Functions
void FUNC_MOTOR(int mode);

// Interrupt Service Routine

// SW0 interrupt
SIGNAL(INT4_vect) {
	cli();
	// Right (01)
// 	PORTD &= ~(0x01 << PORTD5);
// 	PORTD |= (0x01 << PORTD4);
	FUNC_MOTOR(CW);
	sei();
}

// SW1 interrupt
SIGNAL(INT5_vect) {
	cli();
	// Left (10)
// 	PORTD &= ~(0x01 << PORTD4);
// 	PORTD |= (0x01 << PORTD5);
	FUNC_MOTOR(CCW);
	sei();
}

// SW2 interrupt
SIGNAL(INT6_vect) {
	cli();
	// Stop
// 	PORTB &= ~(0x01 << PORTB5);
	FUNC_MOTOR(STOP);
	sei();
}

int main(void)
{
	setDD();
	initINT();
	enINT();
	
    while (1) 
    {
//		FUNC_MOTOR(CW);		_delay_ms(2000);
		
// 		FUNC_MOTOR(STOP);	_delay_ms(2000);
		
//		FUNC_MOTOR(CCW);	_delay_ms(2000);
		
// 		FUNC_MOTOR(BREAK);	_delay_ms(2000);
    }
}


void setDD(void) {
	// Set SW0~2 direction to INPUT(0)
	DDRE &= ~(0x01 << PINE4 | 0x01 << PINE5 | 0x01 << PINE6);
	// Set Motor P/N direction to OUTPUT(1)
	DDRD |= (0x01 << PORTD4 | 0x01 << PORTD5);
	// Set Motor EN direction to OUTPUT(1)
	DDRB |= (0x01 << PORTB5);
}


void initINT(void) {
	// Set SW0~2 interrupt control to RISING EDGE(1,1)
	EICRB |= (0x01 | 0x01 << 1 | 0x01 << 2 | 0x01 << 3 | 0x01 << 4 | 0x01 << 5);
	// Set SW0~2 interrupt flag to OFF(0) -> Check whether Interrupt Service Routine is done (0: done)
	EIFR |= (0x01 << PINE4 | 0x01 << PINE5 | 0x01 << PINE6);
}


void enINT(void) {
	// Mask SW0~2 interrupt
	EIMSK |= (0x01 << PINE4 | 0x01 << PINE5 | 0x01 << PINE6);
	// Enable global interrupt
	sei();
}


void FUNC_MOTOR(int mode){
	// 0: stop, 1: CW, 2: CCW
	switch(mode) {
		case CW:
			PORTB |= (0x01 << PORTB5); // Enable
			// Right (01)
			PORTD &= ~(0x01 << PORTD5);
			PORTD |= (0x01 << PORTD4);
			break;
		case CCW:
			PORTB |= (0x01 << PORTB5); // Enable
			// Left (10)
			PORTD &= ~(0x01 << PORTD4);
			PORTD |= (0x01 << PORTD5);
			break;
		case BREAK:
			PORTD |= (0x01 << PORTD4 | 0x01 << PORTD5);
			break;
		case STOP:
			PORTB &= ~(0x01 << PORTB5); // Disable
			PORTD &= ~(0x01 << PORTD4 | 0x01 << PORTD5);
	}
}