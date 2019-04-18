#ifndef sim800_H
#define sim800_H

#include "stm32f10x.h" 




void sim800_Init();
void sim_Gonder(USART_TypeDef* USARTx,char *s);
void Usart1_Init(void);
#endif