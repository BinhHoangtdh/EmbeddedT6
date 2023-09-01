#include "i2c_soft_slave.h"
extern uint8_t address_Receive;
extern uint8_t data[2];

void GPIO_Config(void)
{ 
   GPIO_InitTypeDef  GPIO_InitStructure; 
	/* GPIO Ports Clock Enable */
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);
	/*Configure GPIO pin- SDA, SCK*/
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
   GPIO_InitStructure.GPIO_Pin = SDA | SCK;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
   GPIO_Init(GPIOB, &GPIO_InitStructure); 
	/*Configure GPIO pin- SIGNAL*/
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
   GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
   GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
   GPIO_Init(GPIOC, &GPIO_InitStructure); 
	 
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

uint8_t receiveAddress(){
	uint8_t address = 0;
	for(uint8_t i = 0; i<8; i++){
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 0);
		if(GPIO_ReadInputDataBit(GPIOB, SDA) == 1) address = address | 0x80 >> i;
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 1);
	}
	return address;
}

uint8_t receiveData(void){
	uint8_t receiveData = 0;
	for(uint8_t i = 0; i<8; i++){
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 0);
		if(GPIO_ReadInputDataBit(GPIOB, SDA) == 1) receiveData = receiveData | 0x80 >> i;
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 1);
	}
	return receiveData;
}

void check(void){
	GPIO_SetBits(GPIOC, GPIO_Pin_13);
	delay_ms(50);
	GPIO_ResetBits(GPIOC, GPIO_Pin_13);
	delay_ms(50);
}

void delay_ms(uint32_t time)
{
	while(time){
		TIM_SetCounter(TIM2, 0U);
		while(TIM_GetCounter(TIM2)<1000U);
		//WRITE_REG(TIM2->CNT,0U);
		//while(READ_REG(TIM2->CNT)<1000U);
		time--;
	}
}

void i2c_slave(void){
	
	waitStart();
	
	uint8_t address_WR = receiveAddress();
	setOutputSDA();
	address_Receive = address_WR >> 1;
	if(address_Receive == ADDRESS) GPIO_ResetBits(GPIOB, SDA);
	else{
		GPIO_SetBits(GPIOB, SDA);
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 0);
		setInputSDA();
		return;
	}
	
	while(GPIO_ReadInputDataBit(GPIOB, SCK) == 0);
	setInputSDA();
	
	if((address_WR & 1) ==0){
		data[0] = receiveData();
		setOutputSDA();
		GPIO_ResetBits(GPIOB, SDA);
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 0);
		setInputSDA();
		
		data[1] = receiveData();
		setOutputSDA();
		GPIO_ResetBits(GPIOB, SDA);
		while(GPIO_ReadInputDataBit(GPIOB, SCK) == 0);
		setInputSDA();
		return;
	} else{}
}
void setOutputSDA(void){
	//GPIOB->CRL &= ~(GPIO_CRH_MODE8 | GPIO_CRH_MODE8);
	//GPIOB->CRL |= GPIO_CRH_MODE8_0;
	//GPIOB->BSRR = GPIO_Pin_8;
	GPIOB->CRH &= ~(GPIO_CRH_CNF8 | GPIO_CRH_MODE8);
	GPIOB->CRH |= GPIO_CRH_MODE8_1; // 0x00000002
}
void setInputSDA(void){
	//GPIOB->CRL &= ~(GPIO_CRH_MODE8 | GPIO_CRH_MODE8);
	//GPIOB->CRL |= GPIO_CRH_MODE8_1;
	//GPIOB->BRR = GPIO_Pin_8;
	GPIOB->CRH &= ~(GPIO_CRH_CNF8 | GPIO_CRH_MODE8);
	GPIOB->CRH |= GPIO_CRH_CNF8_0; // 0x00000004
}
void waitStart(void){
	while(GPIO_ReadInputDataBit(GPIOB, SCK) == 1){
		if(GPIO_ReadInputDataBit(GPIOB, SDA) == 0){
			while(GPIO_ReadInputDataBit(GPIOB, SCK) == 1);
			return;
		}
	}
}
