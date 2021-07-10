#ifndef _MCAL_REG_H
#define _MCAL_REG_H

#include <cstdint>
#include "mcal_reg_access.h"
#include "mcal_reg_access_dynamic.h"

namespace mcal {

	namespace reg {


					// Global base address
					const std::uint32_t periph_base     = 0x40000000U;

					// Indivisual Unit base address

					const std::uint32_t ahb1periph_base = periph_base + 0x00020000U;
					const std::uint32_t rcc_base        = ahb1periph_base + 0x00003800U;

					const std::uint32_t ahb1enr         =  rcc_base + 0x30;
					const std::uint32_t ahb2enr         =  rcc_base + 0x34;
					const std::uint32_t ahb3enr         =  rcc_base + 0x38;

					const std::uint32_t gpioa_base = ahb1periph_base + 0x0000;
					const std::uint32_t gpiob_base = ahb1periph_base + 0x0400;
					const std::uint32_t gpioc_base = ahb1periph_base + 0x0800;
					const std::uint32_t gpiod_base = ahb1periph_base + 0x0C00;
					const std::uint32_t gpioe_base = ahb1periph_base + 0x1000;
					const std::uint32_t gpiof_base = ahb1periph_base + 0x1400;
					const std::uint32_t gpiog_base = ahb1periph_base + 0x1800;

					//Port register

					const std::uint32_t moder_offset     = 0x0000;
					const std::uint32_t otyper_offset    = 0x0004;
					const std::uint32_t ospeedr_offset   = 0x0008;
					const std::uint32_t pupdr_offset     = 0x000C;
					const std::uint32_t idr_offset       = 0x0010;
					const std::uint32_t odr_offset       = 0x0014;
					const std::uint32_t bsrr_offset      = 0x0018;
					const std::uint32_t lckr_offset      = 0x001C;
					const std::uint32_t afrl_offset      = 0x0020;
					const std::uint32_t afrh_offset      = 0x0024;

					// GPIO A register

					const std::uint32_t gpioa_moder      = gpioa_base + moder_offset;
					const std::uint32_t gpioa_otyper     = gpioa_base + otyper_offset;
					const std::uint32_t gpioa_ospeedr    = gpioa_base + ospeedr_offset;
					const std::uint32_t gpioa_pupdr      = gpioa_base + pupdr_offset;
					const std::uint32_t gpioa_idr        = gpioa_base + idr_offset;
					const std::uint32_t gpioa_odr        = gpioa_base + odr_offset;
					const std::uint32_t gpioa_bsrr       = gpioa_base + bsrr_offset;
					const std::uint32_t gpioa_lckr       = gpioa_base + lckr_offset;
					const std::uint32_t gpioa_afrl       = gpioa_base + afrl_offset;
					const std::uint32_t gpioa_afrh       = gpioa_base + afrh_offset;

					// GPIO B register

					const std::uint32_t gpiob_moder      = gpiob_base + moder_offset;
					const std::uint32_t gpiob_otyper     = gpiob_base + otyper_offset;
					const std::uint32_t gpiob_ospeedr    = gpiob_base + ospeedr_offset;
					const std::uint32_t gpiob_pupdr      = gpiob_base + pupdr_offset;
					const std::uint32_t gpiob_idr        = gpiob_base + idr_offset;
					const std::uint32_t gpiob_odr        = gpiob_base + odr_offset;
					const std::uint32_t gpiob_bsrr       = gpiob_base + bsrr_offset;
					const std::uint32_t gpiob_lckr       = gpiob_base + lckr_offset;
					const std::uint32_t gpiob_afrl       = gpiob_base + afrl_offset;
					const std::uint32_t gpiob_afrh       = gpiob_base + afrh_offset;

					// GPIO C register

					const std::uint32_t gpioc_moder      = gpioc_base + moder_offset;
					const std::uint32_t gpioc_otyper     = gpioc_base + otyper_offset;
					const std::uint32_t gpioc_ospeedr    = gpioc_base + ospeedr_offset;
					const std::uint32_t gpioc_pupdr      = gpioc_base + pupdr_offset;
					const std::uint32_t gpioc_idr        = gpioc_base + idr_offset;
					const std::uint32_t gpioc_odr        = gpioc_base + odr_offset;
					const std::uint32_t gpioc_bsrr       = gpioc_base + bsrr_offset;
					const std::uint32_t gpioc_lckr       = gpioc_base + lckr_offset;
					const std::uint32_t gpioc_afrl       = gpioc_base + afrl_offset;
					const std::uint32_t gpioc_afrh       = gpioc_base + afrh_offset;

					// GPIO D register

					const std::uint32_t gpiod_moder      = gpiod_base + moder_offset;
					const std::uint32_t gpiod_otyper     = gpiod_base + otyper_offset;
					const std::uint32_t gpiod_ospeedr    = gpiod_base + ospeedr_offset;
					const std::uint32_t gpiod_pupdr      = gpiod_base + pupdr_offset;
					const std::uint32_t gpiod_idr        = gpiod_base + idr_offset;
					const std::uint32_t gpiod_odr        = gpiod_base + odr_offset;
					const std::uint32_t gpiod_bsrr       = gpiod_base + bsrr_offset;
					const std::uint32_t gpiod_lckr       = gpiod_base + lckr_offset;
					const std::uint32_t gpiod_afrl       = gpiod_base + afrl_offset;
					const std::uint32_t gpiod_afrh       = gpiod_base + afrh_offset;

					// GPIO E register

					const std::uint32_t gpioe_moder      = gpioe_base + moder_offset;
					const std::uint32_t gpioe_otyper     = gpioe_base + otyper_offset;
					const std::uint32_t gpioe_ospeedr    = gpioe_base + ospeedr_offset;
					const std::uint32_t gpioe_pupdr      = gpioe_base + pupdr_offset;
					const std::uint32_t gpioe_idr        = gpioe_base + idr_offset;
					const std::uint32_t gpioe_odr        = gpioe_base + odr_offset;
					const std::uint32_t gpioe_bsrr       = gpioe_base + bsrr_offset;
					const std::uint32_t gpioe_lckr       = gpioe_base + lckr_offset;
					const std::uint32_t gpioe_afrl       = gpioe_base + afrl_offset;
					const std::uint32_t gpioe_afrh       = gpioe_base + afrh_offset;

					// GPIO F register

					const std::uint32_t gpiof_moder      = gpiof_base + moder_offset;
					const std::uint32_t gpiof_otyper     = gpiof_base + otyper_offset;
					const std::uint32_t gpiof_ospeedr    = gpiof_base + ospeedr_offset;
					const std::uint32_t gpiof_pupdr      = gpiof_base + pupdr_offset;
					const std::uint32_t gpiof_idr        = gpiof_base + idr_offset;
					const std::uint32_t gpiof_odr        = gpiof_base + odr_offset;
					const std::uint32_t gpiof_bsrr       = gpiof_base + bsrr_offset;
					const std::uint32_t gpiof_lckr       = gpiof_base + lckr_offset;
					const std::uint32_t gpiof_afrl       = gpiof_base + afrl_offset;
					const std::uint32_t gpiof_afrh       = gpiof_base + afrh_offset;













	}



}



#endif
