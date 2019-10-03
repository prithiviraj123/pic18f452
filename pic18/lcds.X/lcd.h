#include<xc.h>
#define LCD LATD
#define RS LATCbits.LC0
#define EN LATCbits.LC1
#define _XTAL_FREQ 20000000
void pulse();
void command(char);
void data(char);
void pulse();
void init();
