#ifndef _UART_H
#define _UART_H
#include "mcal_reg.h"
#include <stdio.h>

void uart_init();
int uart2_wrtie(int ch);
int uart2_read(void);
#endif
