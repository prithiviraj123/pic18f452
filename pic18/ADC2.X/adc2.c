#include <xc.h>
#define LCD LATD
#define RS LATCbits.LC0
#define EN LATCbits.LC1
void pulse();
void command(char);
void data(char);
void conv(int n);
#define _XTAL_FREQ 20000000

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
    ADIF=0;
    ADIE=1;
    GIE=1;
    command(0x38);
    command(0x0f);
    command(0x01);
    ADCON0=0x01;
    int x=0;
    while(1)
    {
        GO=1;
        if(ADIF==1)
        {
        command(0x80);
        x=(ADRESH*256)+ADRESL;
        conv(x);
        ADIF=0;
    }
}
}
    

void pulse()
{
  EN=1;
__delay_ms(10); 
 EN=0;
__delay_ms(10); 
}
void command(char cmd)
{
 RS=0;
 LCD=cmd;
 pulse();
}
void data(char data)
{
 RS=1;
 LCD=data;
 pulse();   
}
void conv(int n)
{
  unsigned thou,hun,ten,one;
int temp;
thou=n/1000;
temp=n%1000;
hun=temp/100;
temp=temp%100;
ten=temp/10;
one=temp%10;
data(thou+48);
data(hun+48);
data(ten+48);
data(one+48);
}