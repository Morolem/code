// Stack.cpp: определяет точку входа для консольного приложения.
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
//#include "stdafx.h"
#include "windows.h"

typedef struct stack
{
	int top;
	char data[10];
} st;

void create(st *S)
{
	S->top = -1;
}

int empty(st S)
{
	if (S.top == -1) return 1;
	return 0;
}

int push(char x, st *S)
{
	if (S->top != 10 - 1)
	{
		S->top++;
		S->data[S->top] = x;
		return 1;
	}
	return 0;
}

int pop(char *x, st *S)
{
	if (!empty(*S))
	{
		*x = S->data[S->top];
		S->top--;
		return 1;
	}
	return 0;
}

void out(st *S)
{
	st S2;
	char a;
	create(&S2);
	while (!empty(*S))
	{
		pop(&a, S);
		push(a, &S2);
		printf("%c", a);
	}
	printf("\n");
	while (empty(S2))
	{
		pop(&a, &S2);
		push(a, S);
	}
}

void formula(char file[], st *S)
{
	char a, b, c;
	int i = 0;
	//char file[] = "M(m(M(9,7),m(8,9)),m(6,8))";
	while (file[i] != '\0')
	{
		a = file[i];
		if (a != ')')
		{
			if (a != '(' && a != ',') push(a, S);
		}
		else
		{
			if (!empty(*S))
			{
				pop(&b, S);
				pop(&c, S);
				pop(&a, S);
				if (a == 'M')
				{
					if (b > c) push(b, S);
					else push(c, S);
				}
				if (b < c) push(b, S);
				else push(c, S);
			}
		}
		i++;
	}
}

int main(int argc, char const argv[])
{
	st S1;
	char file[] = "M(m(M(4,7),m(8,9)),m(6,4))";
	//FILE *file;
	//file = fopen("text.txt", "r");
	
	create(&S1);
	
	formula(file, &S1);
	out(&S1);

	//system("pause");
	//fclose(file);
    return 0;
}

