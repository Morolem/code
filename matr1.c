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
				a[i][j] = rand()%4;
			}
	return a;
}

int** xx(int **a, int **b, int **c, int r)
{
	float start, end, t;
	start = clock();

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

int** xt(int **a, int **b, int **c, int r)
{
	float start, end, t;
	start = clock();

   	for(int i = 0; i < r; i++)
   		for(int j = 0; j < r; j++)
   		{
   			c[i][j] = 0;
   		    for (int k = 0; k < r; k++)
   	    		c[i][j] += a[i][k] * b[j][k];
   	 	}

	end = clock();
	t = (end - start) / (CLOCKS_PER_SEC);
	printf("time: %3.3f\n",t);
	return c;
}

int** transp(int **b, int **b1, int r)
{
	for(int i = 0; i<r; i++)
		for(int j = 0; j<r; j++)
			{
				b1[i][j] = b[j][i];
			}
	return b1;
}

int main(int argc, char const *argv[])
{
	int i, j, r, **a, **b, **c, **b1, **c1;
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

	b1 = (int **) malloc(r * sizeof(int));
	for (i=0; i<r; i++)
		b1[i] = (int *) malloc(r * sizeof(int));

	c1 = (int **) malloc(r * sizeof(int));
	for (i=0; i<r; i++)
		c1[i] = (int *) malloc(r * sizeof(int));
	
	a = inp(a,r); // заполнение матрицы а
	b = inp(b,r); // заполнение матрицы b
	c = xx(a,b,c,r); // перемножение матриц
	b1 = transp(b,b1,r); // транспонирование матрицы
	c1 = xt(a,b1,c1,r); // перемножение матрицы а и трансп. матрицы b
	
	out(a,r);
	out(b,r);
	out(c,r);
	//out(c1,r);

	free(a);
	free(b);
	free(c);
	free(b1);
	free(c1);
	return 0;
}