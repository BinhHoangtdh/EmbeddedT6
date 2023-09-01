#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>
#include "spi_soft_slave.h"

uint8_t rev = 0;

int main(){

	GPIO_Config();
	while (1)
  {
		rev = SPI_trans_recei_slave(111);
  }
}
