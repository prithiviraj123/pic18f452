#include <xc.h>
#include "lcd.h"
void main(void) 
{
   PORTC=0X00;
   PORTD=0X00;
   TRISC=0X00;
    TRISB=0X00;
    TRISD=0X00;
    ADCON1=0X0F;
    CMCON=0X07;
    init();
    while(1)
    {
        command(0x80);
        data('a');
    }
    return;
}
