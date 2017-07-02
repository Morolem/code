#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "time.h"

void out(int **a, int r) // вывод матрицы
{
	for(int i = 0; i<r; i++)
		for(int j = 0; j<r; j++)
			{
				if (j != r-1) printf("%i ",a[i][j]);
				else printf("%i\n",a[i][j]);
			}
			printf("\n");
}

int** inp(int **a, int r)
{
	for (int i = 0; i<r; i++)
		for (int j = 0; j<r; j++)
			{
				a[i][j] = rand()%3 + 1;
			}
	return a;
}

int** xx(int **a, int **b, int **c, int r)
{
	float start, end, t;
	start = clock();
	#pragma omp parallel for
   	for(int i = 0; i < r; i++)
   		for(int j = 0; j < r; j++)
   		{
   			c[i][j] = 0;
   		    for (int k = 0; k < r; k++)
   	    		c[i][j] += a[i][k] * b[k][j];
   	 	}

	end = clock();
	t = (end - start) / (CLOCKS_PER_SEC);
	printf("time: %3.3f\n",t);
	return c;
}

int main(int argc, char const *argv[])
{
	int i, j, r, **a, **b, **c;
	srand(time(NULL));
	printf("vvedite razmer matrci: ");
	scanf("%d",&r);

	a = (int **) malloc(r * sizeof(int));
	for (i=0; i<r; i++)
		a[i] = (int *) malloc(r * sizeof(int));
	
	b = (int **) malloc(r * sizeof(int));
	for (i=0; i<r; i++)
		b[i] = (int *) malloc(r * sizeof(int));

	c = (int **) malloc(r * sizeof(int));
	for (i=0; i<r; i++)
		c[i] = (int *) malloc(r * sizeof(int));

	a = inp(a,r); // заполнение матрицы а
	b = inp(b,r); // заполнение матрицы b
	c = xx(a,b,c,r); // перемножение матриц
		
	/*out(a,r);
	out(b,r);
	out(c,r);*/

	free(a);
	free(b);
	free(c);
	return 0;
}