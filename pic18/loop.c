#include<stdio.h>
int main()
{
	int i,d,count=0,sum,x,j;

	for(i=1;i<1000;i++)
	{
		count=0;
		d=i;
	while(d!=0)
	{
		count++;
		d=d/10;
	}
	 
		
		
		sum=0;
		j=i;
	
	 
	while(j>0)
	{
	
    x=j%10;
    if(count==3)
    {
	
    sum=sum+(x*x*x);
}
    else if(count==2)
{

	   sum=sum+(x*x);
}
	   else
	  {
	    sum=sum+x;
	}
	   j=j/10;
}
    if(sum==i)
    printf("\n%d",sum);
}

}
