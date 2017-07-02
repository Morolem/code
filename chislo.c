#include <stdio.h>

int main ()
{
	signed short min = 1001;
	unsigned short array[10000], n, p;
	printf("vvedite kolichestvo signalov\r\nne menee 6\r\n");
	scanf("%d",&n);
	if(n>10000 || n<6) 
	{
		printf("oshibka vvoda, programma budet ostanovlena\r\n");
		return 0;
	}
	printf("vvedite pokazanija pribora\r\n");
	printf("ne bolee 1000\r\n");
	for(int i = 0; i<n; i++)
	{
		printf("%-5i znachenie - ",i+1);
		scanf("%d",&array[i]);
		if (array[i]>1000 || array[i]<0)
		{
			printf("oshibka vvoda, programma budet ostanovlena\r\n");
			return 0;
		}
	}
	for(unsigned short i = 0; i<n-6; i++)
		for(unsigned short j = i+6; j<n; j++)
		{
			p=array[i]*array[j];
			if((p < min) && (p % 2 == 0))
				min = p;
		}
	if(min == 1001) 
	{
		min = -1;
		printf("Error: beta-znachenie = %i\r\n ",min);
	}
	else
	{
		printf("beta-znachenie =%i\r\n",min);
	}
return 0;
}