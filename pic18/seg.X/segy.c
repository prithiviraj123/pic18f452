#include <xc.h>
#define _XTAL_FREQ 20000000
void main(void) 
{
PORTB=0X00;
PORTC=0X00;
TRISC=0X00;
TRISB=0X03;
int i=0,j=0;

int arr[]={0X3F,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
  while(1)
  {
    
        if(RB0==1)
        {
            while(RB0==1);
           
         PORTC=arr[i];
          i++;
        }
    }
  
   
    return;
}
