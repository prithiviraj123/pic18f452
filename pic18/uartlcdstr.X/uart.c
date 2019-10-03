#include <xc.h>
#define _XTAL_FREQ 20000000
#define LCD LATD
#define RS LATCbits.LC0
#define EN LATCbits.LC1
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
    TRISC=0X80;
    TRISD=0X00;
    ADCON1=0X0F;
    CMCON=0X07;
    TXSTA=0X24;
    RCSTA=0X90;
    SPBRG=129;
    char a[20];
    int i;
    command(0x38);
    command(0x0f);
    command(0x01);
    while(1)
    {
        
        for(i=0;i<6;i++)
        {
        while(RCIF==0);
         a[i]=RCREG;
         data(a[i]);
        }
        
       
         
         for(i=0;i<6;i++)
         {
         while(TRMT==0);
         TXREG=a[i];
             
         }
        
        
    }
    
}
