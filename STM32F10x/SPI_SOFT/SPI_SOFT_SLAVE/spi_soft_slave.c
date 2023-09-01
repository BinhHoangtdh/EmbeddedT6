#include "spi_soft_slave.h"

void GPIO_Config(void)
{ 
   GPIO_InitTypeDef  GPIO_InitStructure; 
	/* GPIO Ports Clock Enable */
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	/*Configure GPIO pin SS- B3*/
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
   GPIO_Init(GPIOB, &GPIO_InitStructure); 
	/*Configure GPIO pin SCK- B4*/
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
   GPIO_Init(GPIOB, &GPIO_InitStructure); 
	/*Configure GPIO pin MOSI- B5*/
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
   GPIO_Init(GPIOB, &GPIO_InitStructure); 
	/*Configure GPIO pin MISO- B6*/
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
   GPIO_Init(GPIOB, &GPIO_InitStructure); 
}

uint8_t SPI_trans_recei_slave(uint8_t byte_out)
{
	uint8_t byte_in = 0;
	while(GPIO_ReadInputDataBit(GPIOB, SS) == 1);
	for(uint8_t i = 0; i<8; i++)
	{
		if(byte_out & (0x80>>i))
			GPIO_SetBits(GPIOB, MISO);
		else
			GPIO_ResetBits(GPIOB, MISO);
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 0);
		if(GPIO_ReadInputDataBit(GPIOB, MOSI) == 1) byte_in |= 0x80>>i;
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 1);
	}
	return byte_in;
}
