/*
 * GPIO_lecture.cpp
 *
 * Created: 2024-04-12 오후 5:14:45
 * Author : kkson
 */ 
#define F_CPU 14

745600
#include <avr/io.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>

class GPIO {
	int port;
	int pin;
	bool mode;
	void init();
public:
	GPIO(int port, int pin, bool mode);
};

GPIO::GPIO(int port, int pin, bool mode) {
	this->port = port;
	this->pin = pin;
	this->mode = mode;
	init();
}

void GPIO::init() {
	if (port == 2) {
		DDRC &= ~(0x01 << pin);
		PORTC = mode ? PORTC | (0x01 << pin) : PORTC & ~(0x01 << pin);
	}
}

int main(void)
{
	// PORTC => A, B, C => 0, 1, 2
	// PIN0 => 0
	// MODE => 1
	GPIO led0(2,0,1);
	
    while (1) 
    {
		PORTC |= 0x01;
		_delay_ms(100);
		PORTC &= ~(0x01);
		_delay_ms(100);
		
		// macro function!
		if ( bit_is_set(PINE, 4) );
    }
}

