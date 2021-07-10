#ifndef _MCAL_REG_ACCESS_DYNAMIC
#define _MCAL_REG_ACCESS_DYNAMIC

namespace mcal_dynamic {
	
	namespace reg {
		
		template<typename addr_type,typename reg_type>

				class reg_access {

				public:

						static void reg_set(addr_type addr, reg_type val) {
								*reinterpret_cast<volatile addr_type*>(addr) = static_cast<reg_type>(val);

						}

						static void reg_or(addr_type addr, reg_type val) {
								*reinterpret_cast<volatile addr_type*>(addr) |= static_cast<reg_type>(val);

						}

						static void reg_and(addr_type addr, reg_type val) {
								*reinterpret_cast<volatile addr_type*>(addr) &= static_cast<reg_type>(val);
						}

						static void reg_not(addr_type addr, reg_type val) {
								*reinterpret_cast<volatile addr_type*>(addr) &= static_cast<reg_type>(~val);
						}

						static reg_type reg_get(addr_type addr, reg_type val) {
								return *reinterpret_cast<volatile addr_type*>(addr);
						}

						static void bit_set(addr_type addr, reg_type val) {
								*reinterpret_cast<volatile addr_type*>(addr) |= static_cast<reg_type>(1U<<val);
						}

						static void bit_clear(addr_type addr, reg_type val) {
								*reinterpret_cast<volatile addr_type*>(addr) &= static_cast<reg_type>(static_cast<reg_type>(1U<<val));
						}

						static void bit_not(addr_type addr, reg_type val) {
								*reinterpret_cast<volatile addr_type*>(addr) ^= static_cast<reg_type>(1U<<val);
						}


						static bool bit_get(addr_type addr, reg_type val) {

								return ((reg_get(addr) & static_cast<reg_type>(1U<<val))) != static_cast<reg_type>(0U);
						}




				};






}




}





#endif
