#include "sys.h"
#include "delay.h"
#include "usart.h"


void Delay(__IO uint32_t nCount);

void Delay(__IO uint32_t nCount)
{
  while(nCount--){}
}

int main(void)
{

	GPIO_InitTypeDef GPIO_Initure;
     
    HAL_Init();                     //初始化HAL库    
    Stm32_Clock_Init(360,25,2,8);   //设置时钟,180Mhz

    __HAL_RCC_GPIOB_CLK_ENABLE();           //开启GPIOB时钟
	
    GPIO_Initure.Pin=GPIO_PIN_0|GPIO_PIN_1; //PB1,0
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  //推挽输出
    GPIO_Initure.Pull=GPIO_PULLUP;          //上拉
    GPIO_Initure.Speed=GPIO_SPEED_HIGH;     //高速
    HAL_GPIO_Init(GPIOB,&GPIO_Initure);

	while(1)
	{
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);	//PB1置1 
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_SET);	//PB0置1  			
		Delay(0x7FFFFF);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_RESET);	//PB1置0
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,GPIO_PIN_RESET);	//PB0置0  
		Delay(0x7FFFFF);
	}
	}

