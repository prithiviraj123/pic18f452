#include <xc.h>

void main(void) 
{
    PORTB=0X00;
    TRISB=0X00;
    T0CON=0X53;
    T0CON=0XD3;
    ADCON1=0X0f;
    CMCON=0X07;
   unsigned int count;
     LATBbits.LB0=0;
     while(1)
  {
         if(TMR0IF==1)
         {
             count++;
             TMR0IF=0;
         }
         if(count==98)
         {
             LATBbits.LB0=~LATBbits.LB0;
            
             
             count=0;
         }
     }
    return;
}
