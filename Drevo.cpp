#include <stdio.h>
typedef struct drevo
{
	drevo *l, *r;
	char data;
} dr;
typedef struct stack
{
	stack *next;
	dr *el;
} st;

st * push(dr *x, st *s)
{
	st *r;
	r = new st;
	r->el = x;
	r->next = s;
	return r;
}

st * pop(dr **x, st *s)
{
	st *r;
	r = s;
	*x = s->el;
	s = s->next;
	delete r;
	return s;
}

dr * build_tree() 
{ 
	char sym; 
	dr *d; 
	scanf("%c", &sym); 
	switch (sym) 
	{ 
	case '(': {d = new dr; 
		scanf("%c", &sym); d->data = sym; 
		d->l = build_tree(); 
		d->r = build_tree(); scanf("%c", &sym); 
		return d; } 
	case '0':return NULL; 
	case ',':d = build_tree(); return d; 
	}
} 

int sravn(dr *t, dr *elem)
{
	drevo *d = t;
	st *s = NULL;
	while (d != NULL)
	{
		if (d->data == elem->data && d != elem) return 1;
		if (d->l != NULL && d->r != NULL)
		{
			s = push(d->r, s);
			d = d->l;
		}
		else if (d->l == NULL && d->r == NULL)
			if (s != NULL) s = pop(&d, s);
			else d = NULL;
		else if (d->l != NULL) d = d->l;
		else d = d->r;
	}
	return 0;
}
int obhod(dr *t)
{
	st *s1 = NULL;
	int n = 0;
	drevo *d = t;
	while (d != NULL)
	{
		n = sravn(t, d);
		if (n == 1) return 1;
		if (d->l != NULL && d->r != NULL)
		{
			s1 = push(d->r, s1);
			d = d->l;
		}
		else if (d->l == NULL && d->r == NULL)
			if (s1 != NULL) s1 = pop(&d, s1);
			else d = NULL;
		else if (d->l != NULL) d = d->l;
		else d = d->r;
	}
	return 0;
}

/*void out(dr *t)
{
	st *s1 = NULL;
	drevo *d = t;
	while (d != NULL)
	{
		printf("%c", d->data);
		if (d->l != NULL && d->r != NULL)
		{
			push(d->r, s1);
			d = d->l;
		}
		else if (d->l == NULL && d->r == NULL)
			if (s1 != NULL) pop(&d, s1);
			else d = NULL;
		else if (d->l != NULL) d = d->l;
		else d = d->r;
	}
	printf("\n");
}*/

void out(dr *d)
{
	//st *s1 = NULL;
	//drevo *d = t;
	if (d != NULL)
	{
		printf("%c", d->data);
		out(d->l);
		out(d->r);
	}
	printf("\n");
}

int main()
{
	dr *t = NULL;
	int n = 0;
	t = build_tree();
	out(t);
	/*n = obhod(t);
	if (n == 1) printf("Yes");
	else printf("No");*/
	return 0;
}

