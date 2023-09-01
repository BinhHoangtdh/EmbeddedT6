#include "spi_soft.h"

void GPIO_Config(void)
{ 
   GPIO_InitTypeDef  GPIO_InitStructure; 
	/* GPIO Ports Clock Enable */
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	/*Configure GPIO pin- A3*/
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
   GPIO_Init(GPIOA, &GPIO_InitStructure); 
	/*Configure GPIO pin- A4*/
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
   GPIO_Init(GPIOA, &GPIO_InitStructure); 
	/*Configure GPIO pin- A5*/
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
   GPIO_Init(GPIOA, &GPIO_InitStructure); 
	/*Configure GPIO pin- A6*/
	 //GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
   GPIO_Init(GPIOA, &GPIO_InitStructure); 
}
void TIMER_Config(void)
{

	TIM_TimeBaseInitTypeDef TIM_BaseInitStruct;
	/* TIM Clock Enable */
   RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	/*Configure TIMER*/
	
	/* Select the Counter Mode */
	TIM_BaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	/* Set the clock division */
	//TIM_BaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	/* Set the Autoreload value */
	TIM_BaseInitStruct.TIM_Period = 0xFFFF;
	/* Set the Prescaler value */
	TIM_BaseInitStruct.TIM_Prescaler = 71;
	/* Set the Repetition Counter value */
	//TIM_BaseInitStruct.TIM_RepetitionCounter = 0x0000;
	
	TIM_TimeBaseInit(TIM2, &TIM_BaseInitStruct);
	TIM_Cmd(TIM2, ENABLE);
}
void SPI_setup(void)
{
	GPIO_SetBits(GPIOA, SS);
	GPIO_ResetBits(GPIOA, SCK);
}
void SPI_begin(void)
{
	GPIO_ResetBits(GPIOA, SS);
}
void SPI_end(void)
{
	GPIO_ResetBits(GPIOA, SCK);
	GPIO_SetBits(GPIOA, SS);
}
uint8_t SPI_trans_recei_master(uint8_t byte_out)
{
	uint8_t byte_in = 0;
	for(uint8_t i=0; i<8; i++)
	{
		if(byte_out & (0x80>>i))
			GPIO_SetBits(GPIOA, MOSI);
		else
			GPIO_ResetBits(GPIOA, MOSI);
		delay_ms(1000);
		GPIO_SetBits(GPIOA, SCK);
		if(GPIO_ReadInputDataBit(GPIOA, MISO) == 1) byte_in |= 0x80>>i;
		delay_ms(1000);
		GPIO_ResetBits(GPIOA, SCK);
	}
	return byte_in;
}
void delay_ms(uint32_t time)
{
	while(time){
		TIM_SetCounter(TIM2, 0U);
		while(TIM_GetCounter(TIM2)<1000U);
		//WRITE_REG(TIM2->CNT,0U);
		//while(READ_REG(TIM2->CNT)<20U);
		time--;
	}
}
