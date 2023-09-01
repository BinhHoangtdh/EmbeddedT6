#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_tim.h>
#include <stm32f10x_rcc.h>
#include "i2c_soft_master.h"

int main(){
	GPIO_Config();
	TIMER_Config();
	i2c_setup();

	while(1){
		i2c_master();
	}
}


