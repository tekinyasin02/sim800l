#include "main.h"                  // Device header

char  ch = '\0';
char no[12]="05367955342";
int sayi=26;
char *deneme = (char)26;

char dizgi[100];
char *dizi[100];
int sayac = 0;

char id[]="+CMGS:";
char *bulunan;

int a = 0;
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
     USART_SendData(USART2,'x');
       a=1;
     }
}

void USART1_IRQHandler(void)
{
while(USART_GetITStatus(USART1, USART_IT_RXNE))
{
    ch = USART1->DR; 
    USART_SendData(USART2,ch);
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
void mesaj()
{
while(a==0)
  {
  Usart_Gonder(USART1,"AT+CMGS=\"05367955342\"\r");
  delay();
  Usart_Gonder(USART1,"deneme");
  delay();
  USART_SendData(USART1,deneme);
  delay();
    a=1;
  }
}
int main()
{
  Usart1_Init();
  delay();
  Usart2_Init();
  delay();
//Usart_Gonder(USART1,"AT+CFUN=1\r");
//delay();
//Usart_Gonder(USART1,"AT+CREG?\r");
//delay();
//  Usart_Gonder(USART1,"AT+CMGF=1\r");
//  delay();
     mesaj();
//  Usart_Gonder(USART1,"AT+IPR=9600\r");
//  delay();
//  Usart_Gonder(USART1,"AT&W\r");
//  delay();
//  Usart_Gonder(USART1,"AT+CMGR=32\r");
//  delay(); 
while(1);
}