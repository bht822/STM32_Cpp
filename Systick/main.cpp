#include "uart.h"
#include "systick.h"

/**@program: SYSTIC driver for STM32F411RE*/

int sysflag;
int main() {
	
	uart_init();
	/*Enable clock to gpioa*/ 
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::ahb1enr,(1U<<0)>::reg_or(); 
	
	/*PA5 as output pin */
	mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::gpioa_moder,(1U<<10)>::reg_or();

	

	



    while(1) {
				mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::gpioa_odr,5>::bit_not();
			systick_delayms(1);

	

			
    }












}
