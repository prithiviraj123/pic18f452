#include<stdio.h>

void main()
{
int a,i;
scanf("%d",&a);
for(i=7;i>=0;i--)	
{
	if((a&(1<<i)))
	{
		printf("1");
		
	}
	else
	{
	
	printf("0");
}
}
}
