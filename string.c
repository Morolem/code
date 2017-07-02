#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
	char *str[100],*str1;
	scanf("%s",str);
	printf("flag1\r\n");
	str1 = (char *) malloc(sizeof(char));
	for(int i=0; i<100; i++)
		str[i] = (char *) malloc(sizeof(char *));
	printf("flag2\r\n");
	for(int i=0, j=strlen(*str); i<j; i++, j--)
		{
			*str1 = *str[i];
			*str[i] = *str[j];
			*str[j] = *str1;
		}
	printf("%s",*str);
	for(int i=0; i<strlen(*str); i++)
		free(str[i]);
	return 0;


}