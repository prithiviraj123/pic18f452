#include <xc.h>
int static count;
unsigned int static count1;
void main(void) 
{
    PORTB=0X00;
    TRISB=0X00;
    INTCON=0XE0;
    T0CON=0X40;
    T0CON=0Xc0;
    ADCON1=0X0f;
    CMCON=0X07;
   
     LATBbits.LB0=0;
      LATBbits.LB1=0;
     while(1)
  {
         
         if(count==7918)
         {
             LATBbits.LB0=~LATBbits.LB0;
            
             
             count=0;
         }
         if(count1==15836)
         {
             LATBbits.LB1=~LATBbits.LB1;
            
             
             count1=0;
         }
     }
}
      void interrupt isr()
      {
       if(TMR0IF==1)
         {
             count++;
             count1++;
             TMR0IF=0;
         }   
      }


