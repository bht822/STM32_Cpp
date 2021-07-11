#ifndef _I2C_H
#define _I2C_H
#include "mcal_reg.h"


void i2c1_burstRead(char saddr,char maddr, int n, char * data);
int  i2c_bytewrite(char saddr,char maddr,char data);
void i2c_ds1307_rtc_init(void);



#endif