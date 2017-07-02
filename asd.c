#include <stdio.h>
#include <stdlib.h>
#define S 3
struct aut
{
    char nom[20];
    char marka[20];
    char fam[20];
    short den, mes;
    int god;
};
void arrI(struct aut *a[S])
{
	int i = 0;
	printf("\n--------------------------------------------------\n");      
printf("nommer |    marka   |    familija   |  den.mes.god\n");     
for(i=0; i<S; i++)
    printf("%-7s|    %-8s|    %-11s|  %2i.%2i.%4i\n",a[i]->nom, a[i]->marka, a[i]->fam, a[i]->den, a[i]->mes, a[i]->god);
}
void arrSort(struct aut *a[S])
{    
	struct aut *p;
	int i = 0, j = 0;
    for(i=0; i<2; i++)
        for(j=i; j<S; j++)
        {
            if(a[i]->god > a[j]->god) 
            {
                p = a[i];
                a[i] = a[j];
                a[j] = p;
            }
            else
            {
                if(a[i]->god == a[j]->god) 
                {
                    if(a[i]->mes > a[j]->mes) 
                    {
                        p = a[i];
                        a[i] = a[j];
                        a[j] = p;
                    } 
                    else
                    {
                        if(a[i]->mes == a[j]->mes)  // в случае равенства по месяцам
                            if(a[i]->den > a[j]->den) // сортировка по дням
                            {
                                p = a[i];
                                a[i] = a[j];
                                a[j] = p;
                            }
                    } 
                }
            }
        }
arrI(a);
}
int arrP() 
{
    struct aut *a[S];
    int i=0, j=0;
    for(i=0; i<S; i++)
    	a[i] = (struct aut *) malloc(sizeof(struct aut));
    printf("vvedite\n");
    for(i=0; i<S; i++)
    {
    	printf("nomer auto: ");
        scanf("%s",a[i]->nom);
        printf("marku auto: ");
        scanf("%s",a[i]->marka);
        printf("familija: ");
        scanf("%s",a[i]->fam);
        printf("den | mesac | god\n");
        scanf("%i %i %i",&a[i]->den, &a[i]->mes, &a[i]->god);
	}
    arrSort(a);  
for(i=0; i<S; i++)
    free(a[i]); 
}
int main()
{
arrP();
return 0;
}