#include <xc.h>
void main(void) 
{
    
    TRISC=0X00;
    CCPR1L=0XF5;
    CCP1CON=0X0F;
    ADCON1=0X0f;
    CMCON=0X07;
    PR2=0XFF;
    T2CON=0X02;
    T2CON=0X06;
}   