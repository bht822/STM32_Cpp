#include "uart.h"

int main(){
	
	uart_init();
	while(1){
		
		uart_write('a');
		
		for(int i=0;i<180000;i++){}
		
	
	}



}
