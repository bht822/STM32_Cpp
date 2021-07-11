#include "timer2.h"
#include "uart.h"

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
		uart_init();
	
	/*Wait for UIF is set*/
	while(!(TIMER2->SR &1)){
	
	}
		
		/*Clear the SR*/
		TIMER2->SR &= ~1;

}

void tim2_ch1_compare_mode_init(void){

	/*Enable clock to gpioa*/ 
	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::ahb1enr,(1U<<0)>::reg_or(); 
	
	/*PA5 as output pin */
	mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::gpioa_moder,(0U<<10)>::reg_or();
	mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::gpioa_moder,(1U<<11)>::reg_or();
	
	/*Alternate fucntions AF1 -> timer2*/
	mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::gpioa_afrl,(1U<<20)>::reg_or();
	
	/*Enable clock access to APB1*/
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::apb1enr,(1U<<0)>::reg_or();
	
	/* 16 000 000 /1600 = 160000*/ 
	/**@Resolution or the period**/
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::tim2_psc,(1600-1)>::reg_set();
	
	/*Multiplier*/
		/* Auto reload at 10,000 CNTs*/
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::tim2_arr,(10000-1)>::reg_set();
	
	
	/*****Output compare mode config******/
	
	/*set output to toggle match    OCIM[4:6]*/
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::tim2_ccmr1,(0x30)>::reg_set();

	/*Set match value*/
 mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::tim2_ccr1,0>::reg_set();

	/*Enable channel 5 to compare mode*/
 mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::tim2_ccer,1>::reg_or();
 
 /*Clear timer counter */
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::tim2_cnt,0>::reg_set();
	/*enable timer 2*/
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::tim2_cr1,1>::reg_set();



	
	



}
