// Table.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

//#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <locale>
#define N 10
typedef struct command
{
	int nc;
	double one, last, three;
} cm;

typedef struct table
{
	cm elem[N];
	int n;
} tb;

void zero(tb *T)
{
	for (int i = 0; i != N; i++)
	{
		T->elem[i].one = 0;
		T->elem[i].last = 0;
		T->elem[i].three = 0;
	}
}

int insert(tb *T, int x[])
{
	int n = 0, i = 0;
		while (i != 5) // öèêë ñ÷åòà ìàññèâà õ[]
		{
			n = 0;
			while (n != T->n) // öèêë ïîèñêà îäèíàêîâûõ ýëåìåíòîâ
			{
				if (T->elem[n].nc != x[i]) n++;
				else switch (i)
				{
				case 4: T->elem[n].three += 1; n = 0; i++; break;
				case 3: T->elem[n].three += 1; n = 0; i++; break;
				case 2: T->elem[n].three += 1; n = 0; i++; break;
				case 1: T->elem[n].last += 1; n = 0; i++; break;
				case 0: T->elem[n].one += 1; n = 0; i++; break;
				}
			}

			if (i != 5 && T->n != N)
			{
				T->elem[T->n].nc = x[i];
				T->n++;
				switch (i)
				{
				case 4: T->elem[n].three += 1; i++; break;
				case 3: T->elem[n].three += 1; i++; break;
				case 2: T->elem[n].three += 1; i++; break;
				case 1: T->elem[n].last += 1; i++; break;
				case 0: T->elem[n].one += 1; i++; break;
				}
			}
			else if (T->n >= N) return -1;
			else if(i != 5) i++;
		}
	return 0;
}
void procent(tb *T)
{
	int one = 0, last = 0, three = 0;
	for (int i = 0; i != T->n; i++)
	{
		one += T->elem[i].one;
		last += T->elem[i].last;
		three += T->elem[i].three;
	}
	
	for (int i = 0; i != T->n; i++)
	{
		T->elem[i].one = T->elem[i].one / one * 100;
		T->elem[i].last = T->elem[i].last / last * 100;
		T->elem[i].three = T->elem[i].three  / three * 100;
	}
}
void out(tb T)
{
	printf(" ¹  one    last  three\n");
	for (int i = 0; i != T.n; i++)
		printf("%2i  %2.2f  %2.2f  %2.2f\n", T.elem[i].nc, T.elem[i].one, T.elem[i].last, T.elem[i].three);
}

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "Russian");
	tb T; T.n = 0;
	int x[5], i = 0, tmp = 0;
	FILE *file;
	file = fopen("SPORT.txt", "r");
	zero(&T); // îáíóëåíèå ãîëîñîâ
	while (fscanf(file, "%d", &x[i]) != EOF)
	{
		i++;
		while (i != 5)
		{
			fscanf(file, "%d", &x[i]);
			i++;
		}
		i = 0;
		tmp = insert(&T, x); // çàïîëíåíèå òàáëèöû
		if (tmp == -1)
		{
			//printf("%d", count);
			printf("Error: êîëè÷åñòâî êîìàíä ïðèâûøàåò ìàêñèìàëüíûé ðàçìåð òàáëèöû\n");
			system("pause");
			return 0;
		}
	}
	procent(&T); // ïåðåâîä ãîëîñîâ â ïðîöåíòû
	out(T); 
	system("pause");
	return 0;
}

