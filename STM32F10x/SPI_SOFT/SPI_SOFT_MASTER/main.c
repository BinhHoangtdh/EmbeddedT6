#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_tim.h>
#include <stm32f10x_rcc.h>
#include "spi_soft.h"

uint8_t rev1 = 0;
int main(){
	GPIO_Config();
	TIMER_Config();
	SPI_setup();
	while (1)
  {
		delay_ms(3000);
		SPI_begin();
		rev1 = SPI_trans_recei_master(222);
		SPI_end();
  }
}
