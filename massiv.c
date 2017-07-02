#include <stdio.h>
#include <stdlib.h>
char ss()
{
	char s;
	scanf("%i ",&s);
	return s;
}
void main()
{

	
	int b=5,i,j,a[b][b];
	srand(time(NULL));
	for(i=0; i<b; i++)
		for(j=0; j<b; j++)
		{
			if (j!=b-1)
			{
				a[i][j]=-50+rand()%100;
				printf(" a[%d][%d]=%3i ",i,j,a[i][j]);
			}
			else
			{
				a[i][j]=-50+rand()%100;
				printf(" a[%i][%i]=%3i \n",i,j,a[i][j]);	
			}

		}
	return;
}