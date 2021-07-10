#include "systick.h"


#define SYSTICK ((mcal::reg::SYSTICK_typedef *) mcal::reg::systick_base)



void systick_init_1sec(){
	
	mcal::reg::reg_access<std::uint32_t,std::uint32_t, mcal::reg::systick_load,(16000000-1)>::reg_set();
	mcal::reg::reg_access<std::uint32_t,std::uint32_t, mcal::reg::systick_val,0>::reg_set();
	mcal::reg::reg_access<std::uint32_t,std::uint32_t, mcal::reg::systick_ctrl,5>::reg_set(); // enble systick, user system clock, no interupt


	

}
int get_count_flag(void){
	
	return SYSTICK->CTRL & 0x10000;



}

void systick_delayms(std::uint32_t dly){
	
		mcal::reg::reg_access<std::uint32_t,std::uint32_t, mcal::reg::systick_load,(16000-1)>::reg_set();
		mcal::reg::reg_access<std::uint32_t,std::uint32_t, mcal::reg::systick_val,0>::reg_set();
		mcal::reg::reg_access<std::uint32_t,std::uint32_t, mcal::reg::systick_ctrl,5>::reg_set(); // enble systick, user system clock, no interupt
	
	
	for(int i=0;i<dly;i++){
		
		//Wait until timer flag is set//
		while(!(SYSTICK->CTRL & 0x10000)){	}
		//Stop timmer//
	
	}
	
	mcal::reg::reg_access<std::uint32_t,std::uint32_t, mcal::reg::systick_ctrl,0>::reg_set(); // disable the timmer


	

	
	


}
