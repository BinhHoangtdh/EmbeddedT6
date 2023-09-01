#include "i2c_soft_master.h"

void GPIO_Config(void)
{ 
   GPIO_InitTypeDef  GPIO_InitStructure; 
	/* GPIO Ports Clock Enable */
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC, ENABLE);
	/*Configure GPIO pin- SDA, SCK*/
   GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
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
void i2c_setup(void)
{
	GPIO_SetBits(GPIOB, SDA);
	GPIO_SetBits(GPIOB, SCK);
}
void i2c_begin(void)
{
	GPIO_ResetBits(GPIOB, SDA);
	delay_ms(50);
	GPIO_ResetBits(GPIOB, SCK);
}
void i2c_end(void)
{
	GPIO_ResetBits(GPIOB, SDA);
	GPIO_SetBits(GPIOB, SCK);
	delay_ms(50);
	GPIO_SetBits(GPIOB, SDA);
}

void transmit7BitAddress(uint8_t address){

	for(uint8_t i = 0; i<7; i++){
		if(address & (0x40>>i)) GPIO_SetBits(GPIOB, SDA);
		else GPIO_ResetBits(GPIOB, SDA);
		clock();
	}
	// Bit W: mode Write
	GPIO_ResetBits(GPIOB, SDA);
	clock();
}

void transmitData(uint8_t data){
	for(uint8_t i = 0; i<8; i++){
		if(data & (0x80>>i)) GPIO_SetBits(GPIOB, SDA);
		else GPIO_ResetBits(GPIOB, SDA);
		clock();
	}
}

void clock(void){
	GPIO_SetBits(GPIOB, SCK);
	delay_ms(50);
	GPIO_ResetBits(GPIOB, SCK);
	delay_ms(50);
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

void i2c_master(void){
	again:
	//setup i2c
	i2c_setup();
	delay_ms(3000);	
	
	// start transmit
	i2c_begin();
	
	// transmit address of slave
	transmit7BitAddress(SLAVE_ADDRESS);
	
	//Check address transmitted through bit ACK and continually transmit data if ACK = 0 
	setInputSDA();
	if(GPIO_ReadInputDataBit(GPIOB, SDA) == ACK){
		setOutputSDA();
		transmitData(170);
		setInputSDA();
		if(GPIO_ReadInputDataBit(GPIOB, SDA)== ACK){
			setOutputSDA();
			transmitData(48);
			setInputSDA();
			if(GPIO_ReadInputDataBit(GPIOB, SDA)== ACK){
				setOutputSDA();
				i2c_end();
			}
			else{
				setOutputSDA();
				goto again;
			}
		}
		else{
			setOutputSDA();
			goto again;
		}
	}
	else{
		setOutputSDA();
		goto again;
	}
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

