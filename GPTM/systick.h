#ifndef _SYSTICK_H
#define _SYSTICK_H

#include "mcal_reg.h"
int get_count_flag(void);
void systick_init_1sec();
void systick_delayms(std::uint32_t delay);

#endif
