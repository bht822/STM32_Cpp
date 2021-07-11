#include "adc.h"

/**@program: Reading Analog voltage from @PA1 */

std::uint32_t sensorValue;
int main() {
	
	adc1_init();
	
	
    while(1) {
			
			sensorValue = adc_getValue();

			
    }












}
