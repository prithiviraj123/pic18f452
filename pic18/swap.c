#include<stdio.h>
void main()
{
	int a,b;
	scanf("%d",&a);
	scanf("%d",&b);
	printf("a=%d",a);
	printf("\nb=%d",b);
	a=a^b;
	b=a^b;
	a=a^b;
	printf("\na=%d",a);
	printf("\nb=%d",b);

}
