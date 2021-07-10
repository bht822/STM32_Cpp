#include "uart.h"
#define UART2  ((mcal::reg::USART_typedef *) mcal::reg::uart2_base)


		
	
	void uart_init(){
		

    /**Enable port A clock AHB1**/
    mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::ahb1enr,(1U<<0)>::reg_or();

    /**Enable USART2 clock APB1**/
    mcal::reg::reg_access<std::uint32_t, std::uint32_t,mcal::reg::apb1enr,(1U<<17)>::reg_or();

    /**Set PA2 and PA3 to alternate function**/
    mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::gpioa_moder,(0U<<4)>::reg_or();
    mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::gpioa_moder,(1U<<5)>::reg_or();
	  mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::gpioa_moder,(0U<<6)>::reg_or();
    mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::gpioa_moder,(1U<<7)>::reg_or();
 //	  mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::gpioa_moder,0xA0>::reg_or();




    /**Enable Port A pin 2 and pin 3 AF07 alternate function***/
    mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::gpioa_afrl,0x7700>::reg_or();

    /**Configure USART2 baud rate to 9600**/
    mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::uart2_brr,0x0683>::reg_set();
    /**Enable Tx 8-bit**/
    mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::uart2_cr1,0xC>::reg_set();
	  /*1 stop bit*/
    mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::uart2_cr3,0x000>::reg_set();

    /*No flow control**/
    mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::uart2_cr3,0x000>::reg_set();
    /**Enable UART2**/
    mcal::reg::reg_access<std::uint32_t, std::uint32_t, mcal::reg::uart2_cr1,0x2000>::reg_or();
		
		
	}
	int uart2_wrtie(int ch) {

    std::uint32_t _ch = ch&0xFF;
    /* Wait till Tx buffer is empty*/
    while(!(UART2->SR & 0x0080)) {}
    mcal_dynamic::reg::reg_access<std::uint32_t, std::uint32_t>::reg_set(mcal::reg::uart2_dr,_ch);
		return 1;



}
	int uart2_read(void)
{
	char rcv_ch;
	while(!(UART2->SR &0x0020)){}
		
		rcv_ch = mcal::reg::reg_access<std::uint32_t,std::uint32_t,mcal::reg::uart2_dr,0U>::reg_get();
		return rcv_ch;
		
	
}

namespace std {
  struct __FILE
  {
    int handle;
    /* Whatever you require here. If the only file you are using is */
    /* standard output using printf() for debugging, no file handling */
    /* is required. */
  };
  FILE __stdout;
  FILE __stdin;
  FILE __stderr;
  int fgetc(FILE *f)
  {
    int c;
		c = uart2_read();
		if(c=='\r'){
			uart2_wrtie(c);
			c='\n';
		
		}
		uart2_wrtie(c);
    return c;
  }
  int fputc(int c, FILE *stream)
  {
		return uart2_wrtie(c);
    
  }
  int ferror(FILE *stream)
  {
    /* Your implementation of ferror(). */
		return 0;
  }
  long int ftell(FILE *stream)
  {
    /* Your implementation of ftell(). */
		return 0;
  }
  int fclose(FILE *f)
  {
    /* Your implementation of fclose(). */
    return 0;
  }
  int fseek(FILE *f, long nPos, int nMode)
  {
    /* Your implementation of fseek(). */
    return 0;
  }
  int fflush(FILE *f)
  {
    /* Your implementation of fflush(). */    
    return 0;
  }
}
