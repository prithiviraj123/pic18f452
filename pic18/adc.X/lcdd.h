#ifdef lcd
#define lcd
#include <xc.h>
#define _XTAL_FREQ 20000000
#define LCD LATD
#define RS LATCbits.LC0
#define EN LATCbits.LC1
void pulse();
void command(char);
void data(char);
void conv(int n);
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
#endif
