/*
 * EX_06_UART_hello.c
 *
 * Created: 2024-04-15 오후 4:09:29
 * Author : kkson
 */ 
#define F_CPU 14745600
#include <avr/io.h>

void putch(unsigned char ch) {
	// Data Register Empty (Empty: 0)
	while((UCSR0A & (0x01 << UDRE0)) == 0);	// Data Register 사용가능 신호대기
	UDR0 = ch;							// 데이터를 UDR0 buffer에 쓰고, 전송
	// UCSR0A = (0x01 << UDRE0);			// Read Only - 쓰기 불가능	
	// Data Register 사용가능 신호는, Hardware가 준다
}

unsigned char getch() {
	// 8 bit buffer
	unsigned char ch;
	// Receive Complete
	while((UCSR0A & (0x01 << RXC0)) == 0);
	ch = UDR0; // write data to buffer
	// UCSR0A |= 0x01 << RXC0;
	return ch;
}

void putstr(const unsigned char *str){
	unsigned int i = 0;
	while (str[i] != '\0')
	{
		putch(str[i++]);
	}
}

void init_uart0(void) {
	// Control & Status
	UCSR0A = 0x00;
	
	// UCSR0B = 0x18;	// Enable Rx, Tx
	UCSR0B |= (0x01 << RXEN0 | 0x01 << TXEN0);
	
	// MSEL: Mode Select
	// PM: Parity Mode
	// SBS: Stop Bit Select
	// CSZ: Character SiZe
	// CPOL: Clock POLarity
	
	// UCSR0C = 0x06;	// Databit: 8, no parity, 1 stop bit --> 8-N-1
	UCSR0C &= ~(0x01 << UMSEL0 | 0x01 << UPM00 | 0x01 << UPM01 | 0x01 << USBS0 | 0x01 << UCSZ02 | 0x01 << UCPOL0);
	UCSR0C |= (0x01 << UCSZ00 | 0x01 << UCSZ01);
	
	// Baud Rate - How many symbols can be transmitted per second.
	UBRR0H = 0x00;
	UBRR0L = 0x07;	// 115200 bps
	// H: 0b0000, L: 0b0000_0111
}

// 기존인원이 그만둬서 뽑는거냐, 회사 규모가 커져서 뽑는거냐

int main(void)
{
    unsigned char text[] = "\r\nWelcome! edgeiLAB\r\n USART 0 Test Program.\r\n";
	unsigned char echo[]  = "ECHO >> ";
    
	// Set UART direction
	DDRE &= ~(0x01 << PORTE0);
	DDRE |= (0x01 << PORTE1);
	
	init_uart0();
	
	putstr(text);
	putstr(echo);
	
	// echo all received data
	while(1) {
		putch(getch());
	}
}

