#include <xc.h>
#define _XTAL_FREQ 20000000
#define sw1 PORTBbits.RB0
void main(void) 
{
PORTB=0X00;
PORTC=0X00;
TRISC=0X00;
TRISB=0XFF;
int i=0,j=0;

int arr[]={0X3F,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
LATC=arr[0];
__delay_ms(1000);
  while(1)
  {
    
        if(sw1==1)
        {
            while(sw1==1);
         LATC=arr[i];
          i++;
        }
    }
  
   
    return;
}
