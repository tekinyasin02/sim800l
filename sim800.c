#include "sim800.h"

void Usart2_Init()
{
    GPIO_InitTypeDef   GPIO2_Ayar;
	  USART_InitTypeDef  USART2_Ayar;
	  NVIC_InitTypeDef   NVIC2_Ayar;
	  USART_ClockInitTypeDef USART_ClockInitStructure;
  
  
	 RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);;
   
   GPIO2_Ayar.GPIO_Pin = GPIO_Pin_2;
   GPIO2_Ayar.GPIO_Mode = GPIO_Mode_AF_PP;
   GPIO2_Ayar.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO_Init(GPIOA, &GPIO2_Ayar);
      

   GPIO2_Ayar.GPIO_Pin =GPIO_Pin_3;
   GPIO2_Ayar.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO2_Ayar.GPIO_Mode = GPIO_Mode_IN_FLOATING;
   GPIO_Init(GPIOA, &GPIO2_Ayar);
   
    USART_ClockStructInit(&USART_ClockInitStructure);
    USART_ClockInit(USART2, &USART_ClockInitStructure);
   
	 
	 USART2_Ayar.USART_BaudRate = 115200;
   USART2_Ayar.USART_WordLength = USART_WordLength_8b;
   USART2_Ayar.USART_StopBits = USART_StopBits_1;
   USART2_Ayar.USART_Parity = USART_Parity_No;
   USART2_Ayar.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
   USART2_Ayar.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
   USART_Init(USART2, &USART2_Ayar);
    USART_Cmd(USART2, ENABLE);
    
    

	 NVIC2_Ayar.NVIC_IRQChannel = USART2_IRQn;
   NVIC2_Ayar.NVIC_IRQChannelPreemptionPriority =0;
   NVIC2_Ayar.NVIC_IRQChannelSubPriority =0;
   NVIC2_Ayar.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC2_Ayar);
   
   
   USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
	 
}

  void Usart_Gonder(USART_TypeDef* USARTx,char *s)
  {
 
 while(*s)
 { 
   while( !(USARTx->SR & 0x00000040));
   USART_SendData(USARTx, *s);
   s++;
 }
 
  }
  
  void Usart1_Init()           
 {
    GPIO_InitTypeDef   GPIO1_Ayar;
    GPIO_InitTypeDef   GPIO1Ayar;
	  USART_InitTypeDef  USART1_Ayar;
	  NVIC_InitTypeDef   NVIC1_Ayar;
	  USART_ClockInitTypeDef USART_ClockInitStructure;
	 RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
   RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
   
	 GPIO1_Ayar.GPIO_Pin = GPIO_Pin_9;
   GPIO1_Ayar.GPIO_Mode = GPIO_Mode_AF_PP;
   GPIO1_Ayar.GPIO_Speed = GPIO_Speed_50MHz;
 
	    
   
   GPIO1Ayar.GPIO_Pin =GPIO_Pin_10;
   GPIO1Ayar.GPIO_Speed = GPIO_Speed_50MHz;
   GPIO1Ayar.GPIO_Mode =GPIO_Mode_IN_FLOATING;
   GPIO_Init(GPIOA, &GPIO1Ayar);
	  GPIO_Init(GPIOA, &GPIO1_Ayar);

    USART_ClockStructInit(&USART_ClockInitStructure);
    USART_ClockInit(USART1, &USART_ClockInitStructure);
   
	 USART1_Ayar.USART_BaudRate = 9600;
   USART1_Ayar.USART_WordLength = USART_WordLength_8b;
   USART1_Ayar.USART_StopBits = USART_StopBits_1;
   USART1_Ayar.USART_Parity = USART_Parity_No;
   USART1_Ayar.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
   USART1_Ayar.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
   USART_Init(USART1, &USART1_Ayar);
 
   USART_Cmd(USART1, ENABLE);
   
  
	 
	 NVIC1_Ayar.NVIC_IRQChannel = USART1_IRQn;
   NVIC1_Ayar.NVIC_IRQChannelPreemptionPriority =0x0F;
   NVIC1_Ayar.NVIC_IRQChannelSubPriority =0x0F;
   NVIC1_Ayar.NVIC_IRQChannelCmd = ENABLE;
   NVIC_Init(&NVIC1_Ayar);
   USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
   
 }