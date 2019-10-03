#include <xc.h>
#define _XTAL_FREQ 20000000
void main(void)
{
    ADCON1=0X0F;
    CMCON=0X07;
    TRISC=0b00011000;
    TRISA=0X20;
    TRISD=0X00;
    SSPSTAT=0b01000000;
    SSPCON1=0b00010101;
    SSPCON1=0b00110101;
      unsigned char c;
    while(1)
    {
       
        if(BF==1)
        {
        BF=0;   
        c=SSPBUF;
        }
         if(PORTAbits.NOT_SS==0)
        {
        if(c=='D')
        {
            LATD=~LATD;
           
        }
          __delay_ms(1000);
        }         
    
    }
    return;
}

