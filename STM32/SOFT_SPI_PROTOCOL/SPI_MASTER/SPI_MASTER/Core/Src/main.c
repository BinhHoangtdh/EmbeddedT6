/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "string.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
//#define write_SS(x) x? SET_BIT(GPIOA->ODR, GPIO_ODR_ODR3):CLEAR_BIT(GPIOA->ODR, GPIO_ODR_ODR3)
//#define write_SCK(x) x? SET_BIT(GPIOA->ODR, GPIO_ODR_ODR4):CLEAR_BIT(GPIOA->ODR, GPIO_ODR_ODR4)
//#define write_MOSI(x) x? SET_BIT(GPIOA->ODR, GPIO_ODR_ODR5):CLEAR_BIT(GPIOA->ODR, GPIO_ODR_ODR5)
//#define read_MISO() READ_BIT(GPIOA->IDR, GPIO_IDR_IDR6)
#define write_SS(x) (x)?(GPIOA->ODR|= 1<<3):(GPIOA->ODR &= ~(1<<3))
#define write_SCK(x)(x)?(GPIOA->ODR|= 1<<4):(GPIOA->ODR &= ~(1<<4))
#define write_MOSI(x) (x)?(GPIOA->ODR|= 1<<5):(GPIOA->ODR &= ~(1<<5))
#define read_MISO() (GPIOA->IDR & (1<<6))?1:0

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;
volatile uint8_t rev1;
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */
void SPI_setup(void);//Ham nay co the khong can,Vi ham MX_GPIO_Init()da khai bao cac chan vao/ra va gia tri mac dinh
void SPI_begin(void);
void SPI_end(void);
uint8_t SPI_trans_recei_master(uint8_t byte_out);
void delay_1ms(void);
void delay_ms(int time);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
	SPI_setup();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
		SPI_begin();
		rev1 = SPI_trans_recei_master(10);
		SPI_end();
		HAL_Delay(100);
		//delay_ms(1000);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 400;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 19999;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(SS_PIN_GPIO_Port, SS_PIN_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, SCK_PIN_Pin|MOSI_PIN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : SS_PIN_Pin SCK_PIN_Pin MOSI_PIN_Pin */
  GPIO_InitStruct.Pin = SS_PIN_Pin|SCK_PIN_Pin|MOSI_PIN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : MISO_PIN_Pin */
  GPIO_InitStruct.Pin = MISO_PIN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(MISO_PIN_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */

void SPI_setup(void)
{
	//Ham nay co the khong can,Vi ham MX_GPIO_Init()da khai bao cac chan vao/ra va gia tri mac dinh:
	//+ khai bao cac chan OUTPUT: SS_PIN, SCK_PIN, MOSI_PIN -> declared in MX_GPIO_Init()function
	//+ khai bao chan INPUT: MISO_PIN -> declared in MX_GPIO_Init()function
	//+ Khai bao gia tri mac dinh cua SS_PIN = HIGH , SCK_PIN = LOW
	// -> VI CO THE AP DUNG CHO CAC DONG VDK KHAC NEN SU DUNG HAM NAY. O DAY CHI KHAI BAO GIA TRI MAC DINH CUA SS_PIN = HIGH , SCK_PIN = LOW
	//    CON O VDK KHAC PHAI KHAI BAO THEM INPUT/OUTPUT
	write_SS(1);
	write_SCK(0);
}
void SPI_begin(void)
{
	write_SS(0);
}
void SPI_end(void)
{
	write_SCK(0);
	write_SS(1);
}
// MODE 0: CPOL = 0, CPHASE = 0, Bit_orser = MSB, T = 4 ms
uint8_t SPI_trans_recei_master(uint8_t byte_out)
{
	uint8_t byte_in = 0;
	uint8_t result, i ;
	for(i = 0x80; i>0; i = i>>1)
	{
		result = byte_out & i;
		write_MOSI(result);
		HAL_Delay(100);
		write_SCK(1);
		if(read_MISO() == 1) byte_in |= i;
		HAL_Delay(100);
		write_SCK(0);
	}
	return byte_in;
}
void delay_1ms(void)
{
	//__HAL_TIM_SetCounter(&htim2,0);
	//while(__HAL_TIM_GetCounter(&htim2)<1);
	WRITE_REG(TIM2->CNT,0);
	while(READ_REG(TIM2->CNT<20));
}
void delay_ms(int time)
{
	for(int i=0; i< time; i++)
		{
			delay_1ms();
		}
}

void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
