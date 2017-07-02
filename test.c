#include <stdio.h>
typedef struct spisok
{
	spisok *next;
	int data;
} sp;

void out(sp *a)
{
		while (a != NULL)
		{
			printf("%d ", a->data);
			a = a->next;
		}
		printf("\n");
}

sp* insert(sp *s, int x)
{
	sp *r, *t = s;
	r = new sp;
	r->data = x;
	r->next = NULL;
	if(!s) t = r;
	else
	{
		while(s->next) s = s->next;
		s->next = r;
	}
	return t;
}

int find(sp *a, int c)
{
	printf("1\n");
	while (a != NULL)
	{
		if (a->data == c) 
		{
			printf("Error");
			return 0;
		}
		a = a->next;
	}
	return 1;
}

int dell(sp **s, int x)
{
	sp *r, *t;
	if(*s) if((*s)->data == x)
	{
		r = *s;
		*s = r->next;
		delete r;
		return 1;
	}
	else
	{
		t = *s;
		while(t->next != NULL && t->next->data != x) t = t->next;
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

int st()
{
	static int a = 0;
	if(a == 0) scanf("%d",&a);
	return a;
}

int main(int argc, char const *argv[])
{
	/*sp *s = NULL;
	int i = 0;
	s = new sp;
	s->next = s;
	while(i != -1)
	{
		scanf("%d",&i);
		if(i >= 0) s = insert(s,i);
	}
	out(s);
	scanf("%d",&i);
	dell(&s,i);
	printf("\n");
	out(s);*/

	int a = 0;
	a = st();
	printf("%d\n", a);
	a = st();
	printf("%d\n", a);

	//find(s,i);
	return 0;
}