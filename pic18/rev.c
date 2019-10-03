#include<stdio.h>
#include<string.h>
void main()
{
	char a[30],k;
	int i=0,j=0;
	gets(a);
	puts(a);
	for(i=0;a[i]!=0;i++)
	{
		for(j=i+1;a[j]!=0;j++)
		{
			if(a[i]<a[j])
			{
				k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}	
	}
	puts(a);
}
