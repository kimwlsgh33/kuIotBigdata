/*
 * UART0.c
 *
 * Created: 2024-04-16 오전 11:38:10
 * Author : kkson
 */ 
#define F_CPU 14745600
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include "UART0.h"


FILE OUTPUT = FDEV_SETUP_STREAM(UART0_transmit, NULL, _FDEV_SETUP_WRITE);
FILE INPUT = FDEV_SETUP_STREAM(NULL, UART0_receive, _FDEV_SETUP_READ);

int main(void)
{
	uint8_t counter = 100;
	char buffer[20] = "";
	
	stdout = &OUTPUT;
	stdin = &INPUT;
	
	UART0_init();
	
	char str[] = "Test using UART0 Library";
	uint8_t num = 128;
	
// 	UART0_print_string(str);
// 	UART0_print_string("\n\r");
// 	
// 	UART0_print_1_byte_number(num);
// 	UART0_print_string("\n\r");

	printf("Current Counter Value : ");
	printf("%d\r\n");
	
    while (1) 
    {
		scanf("%s", &buffer);
		
		if (strcasecmp(buffer, "DOWN") == 0) {
			counter--;
			printf("Current Counter Value : ");
			printf("%d\r\n", counter);
		} else if (strcasecmp(buffer, "UP") == 0) {
			counter++;
			printf("Current Counter Value : ");
			printf("%d\r\n", counter);
		} else {
			printf("** Unknown Command **\r\n");
		}
    }
}

