/*
 * UART0.h
 *
 * Created: 2024-04-16 오전 11:39:50
 *  Author: kkson
 */ 


#ifndef UART_H_
#define UART_H_
// UART0
void UART0_init(void);

void UART0_transmit(char data);
unsigned char UART0_receive(void);

void UART0_print_string(char *str);
void UART0_print_1_byte_number(uint8_t n);

void UART0_print_int(int n);
void UART0_print_float(float f);

// UART1
void UART1_init(void);

void UART1_transmit(char data);
unsigned char UART1_receive(void);

void UART1_print_string(char *str);
void UART1_print_1_byte_number(uint8_t n);

void UART1_print_int(int n);
void UART1_print_float(float f);

#endif /* UART_H_ */