#include <stdio.h>
#include <Windows.h>

typedef struct spisok
{
	spisok *next;
	int el;
} sp;

int sizeGraph()
{
	static int a = 0;
	if(a == 0) scanf("%d",&a);
	return a;
}

int sum(int i)
{
	static int s = 0;
	if(i == 0) s++;
	else if(i == 1) s--;
	else if(i == 2) s = 0;
	return s;
}

sp* insert(sp *s, int x)
{
	sp *r, *t = s;
	r = new sp;
	r->el = x;
	r->next = NULL;
	if (!s) t = r;
	else
	{
		while (s->next) s = s->next;
		s->next = r;
	}
	return t;
}

int find(sp *s, int c)
{
	while (s != NULL)
	{
		if (s->el == c) return 1;
		s = s->next;
	}
	return 0;
}

int dell(sp **s, int x)
{
	sp *r, *t;
	if(*s) if((*s)->el == x)
	{
		r = *s;
		*s = r->next;
		delete r;
		return 1;
	}
	else
	{
		t = *s;
		while(t->next != NULL && t->next->el != x) t = t->next;
		if (t->next)
		{
			r = t->next;
			t->next = r->next;
			delete r;
			return 1;
		}
		else return 0;
	}
	else return 0;
}

int** MemAlloc(int **a)
{
	int r = sizeGraph();
	a = (int **)malloc(r * sizeof(int));
	for (int i = 0; i<r; i++)
		a[i] = (int *)malloc(r * sizeof(int));
	return a;
}

int** zero(int **a)
{
	int r = sizeGraph();
	for (int i = 0; i<r; i++)
		for (int j = 0; j<r; j++)
		{
			a[i][j] = 0;
		}
	return a;
}

int** inp(int **a)
{
	int r = sizeGraph();
	int i;
	int j;

	printf("vvedite nomera 2 vershin N > 0\n");
	printf("vvedite 0, esli konec vvoda\n");

	scanf("%d", &i);
	if (i < 1) return a;
	scanf("%d", &j);
	if (j < 1) return a;

	while (i != 0)
	{
		if (i <= r && j <= r) a[i - 1][j - 1] = a[j - 1][i - 1] = 1;
		else return NULL;

		scanf("%d", &i);
		if (i == 0) return a;
		scanf("%d", &j);
		if (j == 0) return a;

		if(i < 0 || j < 0) return 0;
	}
	return a;
}

void dfs(int **a, int i, int *max, sp *s)
{
	for (int j = 0; j< sizeGraph(); j++)
		if (a[i][j] > 0 && find(s, j) != 1)
		{
			sum(0); 
			s = insert(s, j);
			dfs(a, j, max, s);
			sum(1);
			dell(&s, j);
		}
if (sum(3) > *max) *max = sum(3); 
}

int main(int argc, char const *argv[])
{
	int **a = NULL;
	int max = -1;
	sp *s = NULL;

	printf("vvedite kol-vo vershin Grafa\n");
	
	if(sizeGraph() <= 0)
	{
		printf("Error\n");
		return 0;
	}

	a = MemAlloc(a);
	a = zero(a);
	a = inp(a);
	if(a == NULL)
	{
		printf("Error\n");
		return 0;
	}

	for (int i = 0; i < sizeGraph(); i++)
	{
		sum(2);
		s = NULL;
		s = insert(s, i);
		dfs(a, i, &max, s);
	}
	
	if (max >= 0) printf("\nMax %d\n", max);
	else printf("Error\n");
	system("pause");
	return 0;
}