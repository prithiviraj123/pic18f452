#include<stdio.h>
main()
{
	int num,d,count=0,c,p=1,x;
	scanf("%d",&num);
	d=num;
	while(d!=0)
	{
		count++;
		d=d/10;
	}
	 printf("%d\n%d",count,num);
	for(c=1;c<count;c++)
	{
		p=p*10;
	}
	 printf("\n%d\n",p);
	while(num!=0)
	{
	
    x=num/p;
    printf("\t%d",x);
    num=num%p;
    p=p/10;
}
}
