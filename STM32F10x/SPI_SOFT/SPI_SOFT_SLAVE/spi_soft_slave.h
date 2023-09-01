#ifndef __SPI_SOFT_SLAVE_H
#define __SPI_SOFT_SLAVE_H

#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_rcc.h>

#define SS GPIO_Pin_3
#define SCK GPIO_Pin_4
#define MOSI GPIO_Pin_5
#define MISO GPIO_Pin_6

void GPIO_Config(void);
uint8_t SPI_trans_recei_slave(uint8_t byte_out);

#endif
