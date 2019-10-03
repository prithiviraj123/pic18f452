#include <xc.h>
#define _XTAL_FREQ 20000000
#define LCD LATD
#define RS LATCbits.LC0
#define EN LATCbits.LC1
void pulse();
void command(char);
void data(char);
void conv(int n);
int getvalue();
void dec(int);
void main(void)
{
    PORTC=0X00;
    PORTD=0X00;
    PORTC=0X00;
    PORTA=0X00;
    TRISC=0X00;
    TRISB=0X00;
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
    float x=0;
     int y=0;
    while(1)
    {
        command(0x80);
        x=getvalue();
        conv(x);
         y=(x/204.6)*100;
        command(0xc0);
        dec(y);
    }
}
int getvalue()
{
    int x;
    GO=1;
    while(GO==1);
    x=(ADRESH*256)+ADRESL;
    return x;
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

void dec(int n)
{
unsigned int one,x1,x2,temp;
one=n/100;
temp=n%100;
x1=temp/10;
x2=temp%10;
data(one+48);
data('.');
data(x1+48);
data(x2+48);
}
void conv(int n)
{
int thou,hun,ten,one;
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