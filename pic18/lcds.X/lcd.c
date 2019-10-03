#include"lcd.h"
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

void init()
{
     command(0x38);
    command(0x0f);
    command(0x01);
}
