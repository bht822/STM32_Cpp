#include "i2c.h"

#define I2C1 ((mcal::reg::I2C_TypeDef * )mcal::reg::i2c1_base)


/*
 i2c1_SCL = PB8
 i2c2_SDA = PB9


*/

#define SLAVE_ADDR 0x68
void i2c_ds1307_rtc_init(void){
	
	// Enable clock access to GPIOB
	
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::ahb1enr, (1U<<1)>::reg_or();
	
	// Enable clock access to I2C1
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::apb1enr, (1U<<21)>::reg_or();
	
	// Set alternate function in moder for PB8
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::gpiob_moder, (0U<<16)>::reg_or();
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::gpiob_moder, (1U<<17)>::reg_or();
	
	// Set alternate fucntion moder for PB9
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::gpiob_moder, (0U<<18)>::reg_or();
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::gpiob_moder, (1U<<19)>::reg_or();
	
	// Set PB8, PB9 to i2c alternate function 
	
	// Clear the registers 0-7
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::gpiob_afrh, (0xFF)>::reg_not();
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::gpiob_afrh, (0x44)>::reg_or();


	// set output type to open-drain
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::gpiob_otyper, (0x300)>::reg_or();
	
	//Set pins to pull up
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::gpiob_pupdr, (0xF0000)>::reg_not();
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::gpiob_pupdr, (0x50000)>::reg_not();
	
	/*I2C configuration */
	
	// Sw reset 
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::i2c1_cr1, (0x80000)>::reg_set();
	// out of reset 
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::i2c1_cr1, (0x8000)>::reg_not();
	// peripherial clock 16mhz
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::i2c1_cr2, (0x0010)>::reg_set();
	
	// standard mode. 100kHz clock
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::i2c1_ccr, 80>::reg_set();

	
	// Set max rise time 
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::i2c1_trise, 17>::reg_set();
	
	// enable i2c module
	mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::i2c1_cr1, (0x0001)>::reg_or();

	
	



}

int  i2c_bytewrite(char saddr,char maddr,char data){

  volatile int tmp;
	
	//Wait until bus is not busy
	while(I2C1->SR2 & 2){}
		
	//Generate start
	I2C1->CR1 |=0x100;
	
	//Wait until start flag is set
	while(!(I2C1->SR1 & 1)){}	

  /*transmit slave address*/
		I2C1->DR =  saddr <<1;	
		
	//Wait until addr flag is set
	while(!(I2C1->SR1 & 2)){}		
		//clear addr flag
		tmp =  I2C1->SR2;
		/*Wait until data register empty*/
  while (!(I2C1->SR1 & 0x80)){} 
		/*send memory address*/
		I2C1->DR = maddr;
		
	/*Wait until data register empty*/
  while (!(I2C1->SR1 & 0x80)){} 
		/*Send data*/
		I2C1->DR = data;
		
	/*Wait until transfer is finished*/
   while (!(I2C1->SR1 & 4)){}
		 
	 /*Generate stop*/
   I2C1->CR1 |=0x200;
		 

   return 0;
		
}



void i2c1_burstRead(char saddr,char maddr, int n, char * data){

  volatile int tmp;
	
	//Wait until bus is not busy
	while(I2C1->SR2 & 2){}
		
	/*Disable POS*/
  I2C1->CR1 &=~(0x800);
		
  //Generate start
	I2C1->CR1 |=0x100;
		
		//Wait until start flag is set
	while(!(I2C1->SR1 & 1)){}	
		
	  /*transmit slave address*/
		I2C1->DR =  saddr <<1;	
	
	//Wait until addr flag is set
	while(!(I2C1->SR1 & 2)){}		
		//clear addr flag
		tmp =  I2C1->SR2;
		
		/*Wait until transmitter is empty*/
		while(!(I2C1->SR1 & 0x80)){}	
   /*Send memory address*/
			I2C1->DR = maddr;
			
	/*Wait until transmitter is empty*/
		while(!(I2C1->SR1 & 0x80)){}	
		
			
	//Generate REstart
	I2C1->CR1 |=0x100;
 //Wait until start flag is set
	while(!(I2C1->SR1 & 1)){}	
			
	/*Transmit slave addr +read*/
		I2C1->DR =  saddr <<1 |1;	
		
	//Wait until addr flag is set
	while(!(I2C1->SR1 & 2)){}	
		
		//clear addr flag
		tmp =  I2C1->SR2;
	
	/*Enable Acknowledge*/
	I2C1->CR1  |= (0x0400);  
		
	while( n > 0U){
	
	   /*one byte left*/
		if(n == 1U){
		   
			/*1. Disable Acknowledge*/
			I2C1->CR1  &= ~(0x0400); 
			/*2. Generate stop*/
			I2C1->CR1 |=0x200;
			/*3. Wait for RXNE flag set*/
				while(!(I2C1->SR1 & 0x40)){}	
			/*4.Read data from DR*/
			  *data++  = I2C1->DR;
			 break;
		}
		else{
			 /*1. Wait for RXNE flag set*/
				while(!(I2C1->SR1 & 0x40)){}	

			/*2.Read data from DR*/
				(*data++)  = I2C1->DR;
			/*3.Decrement "n"*/
					n--;
		}
	}

}




















