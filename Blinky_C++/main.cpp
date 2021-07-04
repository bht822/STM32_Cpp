#include "mcal_reg.h"

/* 
	LED BLINK STM32F07RB with C++
	Bharat Trehan
	
	Simple program to blink LED connected on port A pin 5 of the Nucleo-F07RBTR board
*/



// Creating a template which is used to make the code more generic, can be used for both 8 bit and 32bit processor

template<typename port_type, typename bval_type, const port_type port, const bval_type bval>
	
class led_template {
	
	//ctor 
	public:
		led_template(){
			
			/*Set Pin low*/
			*reinterpret_cast <volatile  port_type *>(port) &= (~(1U<<bval));
				
			/*Set pin mode*/
			*reinterpret_cast <volatile port_type *>(gpio_mode_reg) |= (1U<<(bval*2));
		
		}
		
		static void toggle(){
			
			*reinterpret_cast<volatile port_type *>(port) ^=(1U<<bval);
		
		
		}
		static void pseudo_delay(){for(int i=0;i<19000;i++){}}
		
	private:
		static const port_type gpio_mode_reg = port -0x14;
	
	
};
	


int main(){
	
	RCC_AHB2ENR |=(1U<<17);
	
	const led_template<std::uint32_t,std::uint32_t,mcal::reg::gpioa,mcal::reg::gpio_pin5> led5;
	
	while(1){
		led5.toggle();
		led5.pseudo_delay();
	}
		
}
