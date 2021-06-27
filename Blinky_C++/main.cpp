#include "mcal_reg.h"

/* 
	LED BLINK STM32F07RB with C++
	Bharat Trehan
	
	Simple program to blink LED connected on port A pin 5 of the Nucleo-F07RBTR board
*/




int main(){
	
	RCC_AHB2ENR |=(1U<<17);
	
	mcal::Led led5(mcal::reg::gpioa,mcal::reg::gpio_pin5);
	
	while(1){
		led5.toggle();
		led5.pseudo_delayms(100);
	}
		
}
