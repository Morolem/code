#include <stdio.h>
#include <stdlib.h>
struct aut
{
	char nom[20];
	char marka[20];
	char fam[20];
	short den, mes;
	int god;
};
void main() 
{
    struct aut *a[3], *p;
    int i=0, j=0;
    for(i=0; i<3; i++)
    	a[i] = (struct aut *) malloc(sizeof(struct aut));
    printf("vvedite\n");
    for(i=0; i<3; i++)
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
    for(i=0; i<2; i++)
    	for(j=i; j<3; j++)
    	{
    		if(a[i]->god > a[j]->god) // сортировка по году
    		{
    			p = a[i];
    			a[i] = a[j];
    			a[j] = p;
    		}
    		else
    		{
    			if(a[i]->god == a[j]->god) // в случае равенства по годам
    			{
    				if(a[i]->mes > a[j]->mes) // сортировка по месяцу
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
printf("\n--------------------------------------------------\n");    	
printf("nommer |    marka   |    familija   |  den.mes.god\n");    	
for(i=0; i<3; i++)
	printf("%-7s|    %-8s|    %-11s|  %2i.%2i.%4i\n",a[i]->nom, a[i]->marka, a[i]->fam, a[i]->den, a[i]->mes, a[i]->god);
for(i=0; i<3; i++)
	free(a[i]);
    return;
}