#ifndef _TIMER2_H
#define _TIMER2_H
#include "mcal_reg.h"
#include <stdio.h> // for printf

void timer2_init_1Hz(void);
void wait_for_timeout(void);
void tim2_ch1_compare_mode_init(void);

#endif
