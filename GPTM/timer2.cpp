#include "timer2.h"

#define TIMER2  ((mcal::reg::TIM_TypeDef *) mcal::reg::tim2_base)



/*SYTEM CLOCK = 16Mhz = 16 000 000 */
void timer2_init_1Hz(void){

	/*Enable clock access to APB1*/
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::apb1enr,(1U<<0)>::reg_or();
	
	/* 16 000 000 /1600 = 160000*/
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::tim2_psc,(1600-1)>::reg_set();

	/* Auto reload at 10,000 CNTs*/
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::tim2_arr,(1000-1)>::reg_set();
	
	// clear timer counter
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::tim2_cnt,0>::reg_set();
	
	// Enable timer
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::tim2_cr1,(1U<<0)>::reg_set();

	
	
}

void wait_for_timeout(void){
	
	/*Wait for UIF is set*/
	while(!(TIMER2->SR &1)){}
		
		/*Clear the SR*/
		TIMER2->SR &= ~1;

}
