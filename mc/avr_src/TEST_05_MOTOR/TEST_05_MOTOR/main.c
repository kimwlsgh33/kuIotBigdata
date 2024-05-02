/*
 * TEST_05_MOTOR.c
 *
 * Created: 2024-03-15 오후 2:01:02
 * Author : kkson
 */ 
#define F_CPU	14746500L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void initMotor(void);
unsigned char motor_on_flag, motor_in_flag;

// SW0 - INTERRUPT
SIGNAL(INT4_vect){
	cli();				// another interrupts are not working!
	motor_on_flag ^= 0x01;
	// EN: 0 -> OFF, 1 -> ON
	if(motor_on_flag) {
		PORTB |= (0x01 << PORTB5);						// EN: 1
	} else {
		PORTB &= ~(0x01 << PORTB5);						// EN: 0
	}
	sei();				// another interrupts are working now!
}

// SW1 - INTERRUPT
SIGNAL(INT5_vect){
	cli();
	motor_in_flag ^= 0x01;
	// IN: 01 -> RIGHT, 10 -> LEFT
	// flag: 0 -> RIGHT, 1 -> LEFT
	if(motor_in_flag) {
		PORTD &= ~(0x01 << PORTD4 | 0x01 << PORTD5);	// IN: 00
		PORTD |= (0x01 << PORTD5);						// IN: 10
	} else {
		PORTD &= ~(0x01 << PORTD4 | 0x01 << PORTD5);	// IN: 00
		PORTD |= (0x01 << PORTD4);						// IN: 01
	}
	sei();
}

SIGNAL(INT6_vect){
	cli();
	// 11 or 00 - emergency stop
	PORTD ^= (0x01 << PORTD4);
	_delay_ms(1000);
	// Reset motor
	initMotor();
	sei();
}


int main(void)
{
	// Set SW0 ~ SW3 Direction to Input
	DDRE &= ~(0x01 << PINE4 | 0x01 << PINE5 | 0x01 << PINE6 | 0x01 << PINE7);
	// Set MOTOR IN Direction to Output
	DDRD |= (0x01 << PORTD4 | 0x01 << PORTD5);
	// Set MOTOR EN Direction to Output
	DDRB |= (0x01 << PORTB5);
	
	// Set SW0 INTERRUPT Control -> rising edge 00 00 00 11
	// Set SW1 INTERRUPT Control -> rising edge 00 00 11 00
	// Set SW2 INTERRUPT Control -> rising edge 00 11 00 00
	EICRB |= (0x01 | 0x01 << 1 | 0x01 << 2 | 0x01 << 3 | 0x01 << 4 | 0x01 << 5);
	// Set SW0~2 INTERRUPT (INT4~6) Initialize to 0
	EIFR |= (0x01 << PINE4 | 0x01 << PINE5 | 0x01 << PINE6);
	// Mask INTERRUPT (INT4~6)
	EIMSK |= (0x01 << PINE4 | 0x01 << PINE5 | 0x01 << PINE6);
	// Enable INTERRUPT
	sei();
	
	initMotor();
    while (1) 
    {
	}
}

void initMotor(void){
	motor_on_flag = 0;
	motor_in_flag = 0;
	PORTB &= ~(0x01 << PORTB5);						// EN: 0
	PORTD &= ~(0x01 << PORTD4 | 0x01 << PORTD5);	// IN: 00
	PORTD |= (0x01 << PORTD4);						// IN: 01
}