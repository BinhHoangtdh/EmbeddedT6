#ifndef __I2C_SOFT_H
#define __I2C_SOFT_H

#include <stm32f10x.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_tim.h>
#include <stm32f10x_rcc.h>

#define SCK GPIO_Pin_7
#define SDA GPIO_Pin_8
#define ACK 0
#define NACK 1
#define ADDRESS 0x5B

void TIMER_Config(void);
void setOutputSDA(void);
void setInputSDA(void);
void i2c_slave(void);
uint8_t receiveAddress(void);
uint8_t receiveData(void);
void GPIO_Config(void);
void check(void);
void waitStart(void);
void delay_ms(uint32_t time);
#endif
