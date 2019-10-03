#include <xc.h>
#define"lcdd.h"
#define _XTAL_FREQ 20000000
int getvalue();
void main(void)
{
    PORTC=0X00;
    PORTD=0X00;
    PORTA=0X00;
    TRISC=0X00;
    TRISD=0X00;
    TRISA=0Xff;
    ADCON0=0x00;
    ADCON1=0X0E;
    ADCON2=0XB6;
    CMCON=0X07;
    command(0x38);
    command(0x0f);
    command(0x01);
    ADCON0=0x01;
    int x=0;
    while(1)
    {
        command(0x80);
        x=getvalue();
        conv(x);
    }
}
int getvalue()
{
    int x;
    GO=1;
    while(GO==1);
    x=(ADRESH*256)+ADRESL;
    ADRESH=0;
    ADRESL=0;
    return x;
}