#include <cstdint>


#define RCC_AHB2ENR (*((volatile unsigned int *)0x40021014))
#define GPIOA_MODER (*((volatile unsigned int *)0x48000000))
#define GPIOA_ODR   (*((volatile unsigned int *)0x48000014))
namespace mcal 
{
	// Namespce for the register
	namespace reg
	{
		const std::uint32_t gpioa = 0x48000014;
		const std::uint32_t gpio_pin5 = 5;

	
	}
	// LED class to create a LED object initiated with the port and the bit value
	class Led 
{
	public:
		typedef std::uint32_t port_type;
	  typedef std::uint32_t bval_type;
		
	//Constructor
	Led(const port_type p, bval_type b):port(p),bval(b)
	{
		// Disable pin
		/*In C we deisabe a pin by using :
		*((volatile uint32_t *) GPIOB) &= (uint32_t)1<<bval 
		*/
		*reinterpret_cast<volatile port_type *>(port) &= ~(1U<<bval);
		
		// Set pin mode to output
		const port_type gpio_mode_reg = port - 0x14;
		
		*reinterpret_cast<volatile port_type *>(gpio_mode_reg) |= (1U<<bval*2);
		
		
		
	}
	// Private variables to be used inside the fucntion of the constructor
	void toggle() const{
	
		*reinterpret_cast<volatile port_type *>(port) ^=(1U<<bval);
		
	
	}
	void pseudo_delayms(int n){
		
		int i;
		for(;n>0;n--){
			
			for(i=0;i<3200;i++){}
		}
		
	}
	private:
		const port_type port;
		const bval_type bval;
	
};

}
