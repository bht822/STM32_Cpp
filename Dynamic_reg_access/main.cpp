	#include "mcal_reg.h"
	
	// Bit mapping for the bit specific settings, the datasheet usually has bit values so i preffer using the bit mapping,  works better for my brain.
	
	typedef struct bit32_type{
		
		std::uint8_t b0: 1;
		std::uint8_t b1: 1;
		std::uint8_t b2: 1;
		std::uint8_t b3: 1;
		
		std::uint8_t b4: 1;
		std::uint8_t b5: 1;
		std::uint8_t b6: 1;
		
		std::uint8_t b7: 1;
		std::uint8_t b8: 1;
		std::uint8_t b9: 1;
		std::uint8_t b10: 1; 
		
		std::uint8_t b11: 1;
		std::uint8_t b12: 1;
		std::uint8_t b13: 1;
		std::uint8_t b14: 1; 
		
		std::uint8_t b15: 1;
		std::uint8_t b16: 1;
		std::uint8_t b17: 1;
		std::uint8_t b18: 1; 
		
		std::uint8_t b19: 1;
		std::uint8_t b20: 1;
		std::uint8_t b21: 1;
		std::uint8_t b22: 1; 
		
		std::uint8_t b23: 1;
		std::uint8_t b24: 1;
		std::uint8_t b25: 1;
		std::uint8_t b26: 1; 
		
		std::uint8_t b27: 1;
		std::uint8_t b28: 1;
		std::uint8_t b29: 1;
		std::uint8_t b30: 1; 
		
		std::uint8_t b31: 1; 
	
	
	}bit32_type;

	// Alternatively we can use a union as well so we can either write the value in hex or access the single bit inf needed
	
	template<typename addr_type, typename reg_type, typename bits_type>
	struct reg_map_dynamic
	{
		
		static reg_type &value (const addr_type addr){
			
			return *reinterpret_cast<reg_type *>(addr);
		
		}
		static bits_type& bits(const addr_type addr){
			return *reinterpret_cast<bits_type*>(addr);
		
		}
	
	
	
	};		
	
	typedef union reg_map
{
	// for writting multiple pin values
	std::uint32_t value;
	bit32_type bits;


}reg_map ;
	
/* template is the for the register value which the address will be and what value of the register will be .
Using this template, the fucntions are given the address of the port or pin of interest and can be used to dynamically assign the pins*/
	template<typename addr_type,typename reg_type>

	class reg_access{

	public:
		
		static void reg_set(addr_type addr, reg_type val){
			*reinterpret_cast<volatile addr_type*>(addr) = static_cast<reg_type>(val);				
			
		}
		
		static void reg_or(addr_type addr, reg_type val){
			*reinterpret_cast<volatile addr_type*>(addr) |= static_cast<reg_type>(val);
			
		}
		
		static void reg_and(addr_type addr, reg_type val){
		*reinterpret_cast<volatile addr_type*>(addr) &= static_cast<reg_type>(val);
		}
		
		static void reg_not(addr_type addr, reg_type val){
			*reinterpret_cast<volatile addr_type*>(addr) &= static_cast<reg_type>(~val);
		}
		
		static reg_type reg_get(addr_type addr, reg_type val){
		return *reinterpret_cast<volatile addr_type*>(addr);
		}
		
		static void bit_set(addr_type addr, reg_type val){
			*reinterpret_cast<volatile addr_type*>(addr) |= static_cast<reg_type>(1U<<val);
		}
		
		static void bit_clear(addr_type addr, reg_type val){
			*reinterpret_cast<volatile addr_type*>(addr) &= static_cast<reg_type>(static_cast<reg_type>(1U<<val));
		}
		
		static void bit_not(addr_type addr, reg_type val){
			*reinterpret_cast<volatile addr_type*>(addr) ^= static_cast<reg_type>(1U<<val);
		}
		
		
		static bool bit_get(addr_type addr, reg_type val){
			
			return ((reg_get(addr) & static_cast<reg_type>(1U<<val))) != static_cast<reg_type>(0U);
		}
		
	


	};

	int main(){
		
		std::uint32_t ahb1enr = mcal::reg::rcc::ah1enr;
		std::uint32_t gpiob = mcal::reg::gpio::cfg_regs::gpiob_cfg::gpiob_odr;
		std::uint32_t gpioa =mcal::reg::gpio::cfg_regs::gpioa_cfg::gpioa_odr;
		
		
		/*Enable clock to port B*/
		// using the reg_map union and each pin
		//reinterpret_cast<volatile reg_map*>(ahb1enr)->bits.b1 = 1U;
		reg_map_dynamic<std::uint32_t,std::uint32_t,bit32_type>::bits(ahb1enr).b1 = 1U;
		
		/*Set first 8 pins of GPIOB to High*/
	//	reinterpret_cast<volatile bit32_type*>(gpiob)->b5 = 1U;
		reg_map_dynamic<std::uint32_t,std::uint32_t,bit32_type>::value(gpiob) = 0xFF;

		
		
		// Accessing the port using the reg_map union
	//	reinterpret_cast<volatile reg_map*>(gpiob) ->value = 0xFF;
		
		
		
		while(1){
						//	reinterpret_cast<volatile bit32_type*>(gpiob)->b7 ^= 1U;
						//	reinterpret_cast<volatile reg_map*>(gpiob)->bits.b11 ^=1U;
					reg_map_dynamic<std::uint32_t,std::uint32_t,bit32_type>::bits(gpiob).b11 ^= 1U;
					reg_map_dynamic<std::uint32_t,std::uint32_t,bit32_type>::bits(gpioa).b4 ^= 1U;


		
		
		}




}
