/*
 * EX_03_SW_EXTIT.c
 *
 * Created: 2024-03-15 오전 9:30:09
 * Author : xxxx
 */ 
#define F_CPU	14745600L
#include <avr/io.h>
#include <avr/interrupt.h> // sei(), cli()
#include <util/delay.h>

// Special Function Register -> 주소저장 -> Interrupt Vector address -> 처리해야할 ISR의 주소

unsigned char flag_led0 = 0;
unsigned char flag_led1 = 0;

// 4번 인터럽트 발생시, 호출되는 함수
// Interrupt Service Routine (ISR), Event Handler - 반복문 금지 (메인 프로그램으로 넘어가지못함)
SIGNAL(INT4_vect) {
	cli();	// 전체 인터럽트 금지 - 인터럽트 처리중에, 중복해서 인터럽트 발생 가능
	// CPU 선점 -> 선점형 == CPU 뺏음, AVR: 비선점형
	if(flag_led0 == 0) {
// 		PORTC |= 0x01;
		flag_led0 = 1;
	} else {
// 		PORTC &= ~0x01; // TODO : 알려주기
		flag_led0 = 0;
	}
	sei();	// 전체 인터럽트 허용
}

// 5번 인터럽트 발생시, 호출되는 함수
SIGNAL(INT5_vect) {
	cli();
	if(flag_led1 == 0) flag_led1 = 1;
	else flag_led1 = 0;
	sei();
}

// HAL: Hardware Abstract Level -> 함수를 보면, 좋은 코드를 알수있다.

int main(void)
{
	// SW 0,1
	DDRE &= ~(0x01 << PINE4 | 0x01 << PINE5);
	DDRC |= (0x01 << PORTC0 | 0x01 << PORTC1 | 0x01 << PORTC2 | 0x01 << PORTC3);
	PORTC &= ~(0x0F);	// init (OFF)
	
	
	// EXIT4,5 동작 설정 (11 rising edge, 10 falling edge, 00 low level of INTn) 
	EICRB	|= (0x01 << 0 | 0x01 << 1 | 0x01 << 2 | 0x01 << 3);	// External Interrupt Control Register B (to allow 4,5 interrupt separated by 2bits)
	// EXIT4,5 0으로 설정 (0: no interrupt, 1: interrupt)
	EIFR	|= (0x01 << PINE4 | 0x01 << PINE5);					// External Interrupt Flag Register (to clear 4,5)
	// EXIT4,5 Interrupt 기능 활성화
	
	
	EIMSK	|= (0x01 << PINE4 | 0x01 << PINE5);					// External Interrupt MaSK register (allow 4) - 씌운다
	// CPU => Interrupt 개수, 완료 개수 카운트 필요 => Flag Register에 카운트 - 해당 하드웨어가 1로 바꿈, 프로그래머 혹은 MCU가 0으로 바꿈 (인터럽트 여부 확인)
	// 1을 써도 인터럽트가 발생하는 일이 없도록 => 프로그래머는 1로 설정하고, 내부적으로 0으로 바꿔주는 방식을 사용하는게 아닐까? - 추측
	
	sei();				// 전체 인터럽트를 허용		SREG - Status REGister (연산결과값 저장용), 다른 비트 접근차단용 함수사용
	// cli();			// 전체 인터럽트를 클리어
	
	while (1)
    {
		// 두가지 동작이 순차적으로 움직임 => 따로 => 타이머 => 통신 주기 맞추기
		if (flag_led0) PORTC ^= (0x01 << PORTC0); _delay_ms(300);
		if (flag_led1) PORTC ^= (0x01 << PORTC1); _delay_ms(500);
    }
	
	
}

// ISC : Interrupt SC 01
// CS : Clock S 01