#include <xc.h>
#define _XTAL_FREQ 20000000
#define LCD LATD
#define RS LATCbits.LC0
#define EN LATCbits.LC1
#define a1 LATBbits.LB0
#define a2 LATBbits.LB1
#define a3 LATBbits.LB2
#define b1 PORTBbits.RB3
#define b2 PORTBbits.RB4
#define b3 PORTBbits.RB5
void pulse();
void command(char);
void data(char);
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

void main(void)
{
    PORTC=0X00;
    PORTD=0X00;
    PORTB=0X00;
    TRISC=0X00;
    TRISD=0X00;
    TRISB=0X38;
    ADCON1=0X0f;
    CMCON=0X07;
    command(0x38);
    command(0x0f);
    command(0x01);
   
    while(1)
    {
        a1=1;
        {
            if(b1==1)
            {
                while(b1==1);
                data('1');
            }
            if(b2==1)
            {
                while(b2==1);
                data('2');
            }
            if(b3==1)
            {
                while(b3==1);
                data('3');
            }
        }
        a1=0;
         a2=1;
        {
            if(b1==1)
            {
                while(b1==1);
                data('4');
            }
            if(b2==1)
            {
                while(b2==1);
                data('5');
            }
            if(b3==1)
            {
                while(b3==1);
                data('6');
            }
        }
         a2=0;
          a3=1;
        {
            if(b1==1)
            {
                while(b1==1);
                data('7');
            }
            if(b2==1)
            {
                while(b2==1);
                data('8');
            }
            if(b3==1)
            {
                while(b3==1);
                data('9');
            }
        }
          a3=0;
       
       
    }
       
    
        
    return;
}
