#include "adc.h"

#define ADC ((mcal::reg::ADC_TypeDef * )mcal::reg::adc1_base)


void adc1_init(void){

	/*Init clock at APB2*/
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::apb2enr,(1U<<8)>::reg_or();
	/*****Configure PA1 as analog input ****/
	
	/*Enable clock to port A*/
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::apb1enr,(1U<<0)>::reg_or();
	
	/*analog for port a pin 1 */
	
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::gpioa_moder,0xC0>::reg_or();
	
	/* SW trigger*/
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::adc1_cr2,0x00>::reg_set();
	
	// Conversion sequence start at ch-1
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::adc1_sqr3,(1U<<0)>::reg_set();
	// Conversion sequence length 1 
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::adc1_sqr1,(0x00)>::reg_set();
	
	// Enable the adc
		mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::adc1_cr2,(1U<<0)>::reg_or();

}

std::uint32_t adc_getValue(void){
	
	// Start conversion
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::adc1_cr2,(1U<<30)>::reg_or();

	// wait for conversion 
	while(!(ADC->SR &(0x2))){}
	
	//Read value from data regsiter
	return	mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::adc1_dr,0>::reg_get();
	



}
