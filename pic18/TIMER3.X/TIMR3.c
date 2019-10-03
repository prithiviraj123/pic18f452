#include <xc.h>

void main(void) 
{
    PORTB=0X00;
    TRISB=0X00;
    T3CON=0X80;
   
    ADCON1=0X0f;
    CMCON=0X07;
   
    
     LATBbits.LB0=0;
     while(1)
  {
         TMR3L=0X09;
         TMR3H=0XFF;
         T3CONbits.TMR3ON=1;
         while(TMR3IF==0);
        //  T3CONbits.TMR3ON=0;
          TMR3IF=0;
             LATBbits.LB0=~LATBbits.LB0;
            
             
            
         }
   
}
