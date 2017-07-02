#include <stdio.h>
#include <time.h>
struct list
{
	list *next;
	char data;
};

int find(list *S, int x)
{
	list *r;
	r = S;
	while(r != NULL)
	{
		if (r->data == x) return 1;
		r = r->next;
	}
	return 0;
}

list* insert(list *p, char x)
{

	list *r, *t = p;
	r = new list;
	r->data = x;
	r->next = NULL;
	if(!p) t = r;
	else
	{
		while(p->next) p = p->next;
		p->next = r;
	}
	return t;
}

void out(list *S)
{
	list *r = S;
	while(r != NULL)
	{
		printf("%c", r->data);
		r = r->next;
	}
printf("\n");
}

int comparison(list *S1, list *S2)
{
	list *s1 = S1;
	list *s2 = S2;
	while(s1 != NULL || s2 != NULL)
		if(s1->data == s2->data) 
		{
			s1 = s1->next;
			s2 = s2->next;
		}
		else return 1;
	return 0;
}

int main(int argc, char const *argv[])
{
	char x[] = "Hello World!!!,Hello World!!!";
	list *S1 = NULL;
	list *S2 = NULL;
	bool flag = false;
	int i = 0;
	
	while(x[i] != ',')
	{
		S1 = insert(S1,x[i]);
		i++;
	}

	i++;

	while(x[i] != '\0')
	{
		S2 = insert(S2,x[i]);
		i++;
	}

	if(comparison(S1,S2)) printf("Stroki raznie\n");
	else printf("stroki odinakovie\n");

	out(S1);
	out(S2);

	return 0;
}