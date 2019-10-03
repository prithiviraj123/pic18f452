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
    int x=0;
    while(1)
    {
        command(0x80);
        x=getvalue();
        conv(x);
        if((x>=190)&&(x<=240))
        {
            LATB=0XFF;
        }
        else if((x>300)||(x<170))
        {
            LATB=0X00;
        }
        else if(((x>240)&&(x<300))||((x>170)&&(x<190)))
        {
               if(PORTB==0XFF)
            {
                LATB=0XFF;
            }
               else
                   LATB=0X00;
                  
        }
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