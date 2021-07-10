#include "mcal_reg.h"


/**@program: toggle LED(PA5) with the drivers toggle the led when push button PC13 is pressed**/
int main(){
	
	std::uint32_t button_state;
		
	/**Enable the GPIO A and GPIO C clock**/
	
	mcal_dynamic::reg::reg_access<std::uint32_t, std::uint32_t>::reg_or(mcal::reg::ahb1enr,(1U<<0));
	mcal_dynamic::reg::reg_access<std::uint32_t, std::uint32_t>::reg_or(mcal::reg::ahb1enr,(1U<<2));

	
	/**Set PA5 as output pin and PC13 as input **/
	
	mcal_dynamic::reg::reg_access<std::uint32_t, std::uint32_t>::reg_or(mcal::reg::gpioa_moder,(1U<<10));
	mcal_dynamic::reg::reg_access<std::uint32_t, std::uint32_t>::reg_or(mcal::reg::gpioc_moder,(0U<<27));
	mcal_dynamic::reg::reg_access<std::uint32_t, std::uint32_t>::reg_or(mcal::reg::gpioc_moder,(0U<<26));


	while(1){
	
	/**Togle PA5**/
		button_state = mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::gpioc_idr,0U>::reg_get();
		if(button_state & 0x2000){
		mcal_dynamic::reg::reg_access<std::uint32_t, std::uint32_t>::reg_set(mcal::reg::gpioa_odr,(1U<<5));
		}else{
			mcal_dynamic::reg::reg_access<std::uint32_t, std::uint32_t>::reg_set(mcal::reg::gpioa_odr,(0U<<5));
		
		}
			
		
		
		
	}
	
	
	
	
}
