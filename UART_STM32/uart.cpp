#include "uart.h"

/*
	Simple UART drive for STM32F411RE 

	USART2 TX = PA2
	USART2 RX = PA3
	RTS =PA1
	CTS = PA0
	USART2 clock is  APB 
	Port A clock is AHB2
	Flow control not used in this driver
*/

void uart_init(void){
	
	RCC->AHB1ENR |=	0x1;  // Enable GPIO clock for Rx and Tx
	RCC->APB1ENR |= 0x20000; // Enable USART2 clock
	
	/*Configure PA2, PA3 for USART2 Tx */
	
	GPIOA->AFR[0] |=0x7700; // Configure Alternate function 7
	GPIOA->MODER |= 0x00A0; // Enable alternate function 
	
	USART2-> BRR = 0x0683; // 9600 baud @16Mhz
	USART2->CR1 = 0x000C;  // Enable Tx, Rx, 8-bit data
	USART2->CR2 = 0x000; // 1 stop bit
	USART2->CR3 = 0x000; // No flow control
	USART2->CR1 |= 0x2000; // enable USART2

}


int uart_write(int ch){
	
	while(!(USART2->SR & 0x0080)){} // Wait until Tx is empty
	USART2->DR =(ch &0xFF);
 return 1;
	

}

int uart_read(void){
	while(!(USART2->SR & 0x020)){}
	return USART2->DR;
	

}
