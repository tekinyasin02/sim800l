#include "main.h"                  // Device header

char  ch = '\0';
char no[12]="05367955342";
int sayi=26;
char *deneme = (char)26;

char dizgi[100];
char *dizi[100];
int sayac = 0;

char id[]="CMGS:";
char *bulunan;
void delay()
{
int i =0;
  while(i<100000)
  {
  i++;
  }
}
void parseveri(char *gelenveri[])
{  
     bulunan =  strstr(*gelenveri,id);

     if(bulunan)
     {
     USART_SendData(USART1,'x');
     }
}

void USART2_IRQHandler(void)
{
while(USART_GetITStatus(USART2, USART_IT_RXNE))
{
    ch = USART2->DR; 
    USART_SendData(USART1,ch);
   if(ch != '\n')
   {
    dizgi[sayac] = ch; 
    dizi[sayac]= &dizgi[sayac];
    sayac++;  
   }     
     else
    {
   dizgi[sayac] = ch; 
   dizi[sayac]= &dizgi[sayac];
   sayac++;     
    parseveri(dizi);
    dizgi[sayac]='\0';
    sayac= 0;
    }  
 
}

}

int main()
{
  Usart1_Init();
  delay();
  sim800_Init();
  delay();
//  sim_Gonder(USART2,"AT\r");
//  delay();
//  sim_Gonder(USART2,"AT+CMGF=1\r");
//  delay();
  sim_Gonder(USART2,"AT+CMGS=\"05367955342\"\r");
  delay();
  sim_Gonder(USART2,"deneme mesaj1");
  delay();
  USART_SendData(USART2,deneme);
  delay();

while(1);
}