#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_tim.h>
#include <stm32f10x_rcc.h>
#include "i2c_soft_slave.h"

uint8_t address_Receive;
uint8_t data[2] = {0};

int main(){
	GPIO_Config();
	TIMER_Config();
	
	while(1){
	
		i2c_slave();
		delay_ms(100);
	
	}

}
