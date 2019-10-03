#include <xc.h>
#define _XTAL_FREQ 20000000
void main(void) 
{
    PORTC=0X00;
    TRISC=0X80;
    ADCON1=0X0F;
    CMCON=0X07;
    TXSTA=0X24;
    RCSTA=0X90;
    SPBRG=129;
     
     
      while(1)
      {
     
     if(TRMT==1)
     {
         TXREG='A';
         
     }
    
      __delay_ms(1000);  
       
      }
    
    return;
}
