#include "uart.h"
//#include <iostream>

	/*
		Simple UART drive for STM32F411RE 
		use terra term or coolterm,
		iostream code is large, use the standard printf	
		
		*/

int main(){
	
	uart_init();
	while(1){
		
		// uncommend the //#include <iostream>
		//std::cout('Hello From cout');
		printf("Hello From C++ printf \r\n");
		
		for(int i=0;i<180000;i++){}
		
	
	}



}
