#include<stdio.h>
void main()
{
	int i,a=0,n[20]={0},c=1,m[20]={0};
	scanf("%d",&a);
	for(i=0;i<8;i++)
	{
		if(a%2==0)
		{
			n[i]=0;
			
		}
		else
		{
		
		n[i]=1;
	}
		a=a/2;
	}
	
	for(i=7;i>=0;i--)
	{
		printf("%d",n[i]);
	}
	printf("\n");
	for(i=7;i>=0;)
	{
	if(n[i]==0)
	{
		n[i]=1;
		i--;
	}
	if(n[i]==1)
	{
		n[i]=0;
		i--;
	}

	}	
		for(i=7;i>=0;i--)
	{
		printf("%d",n[i]);
	}
	printf("\n");	
for(i=0;i<=7;i++)
{
if(n[i]==1 && c==1)
{
	m[i]=0;
}
else if(n[i]==0 && c==1)	
{
	m[i]=1;
	c=0;
}	
else 
{
	m[i]=n[i];
}

}
for(i=7;i>=0;i--)
printf("%d",m[i]);

}
	
