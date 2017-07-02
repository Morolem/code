#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
int main() {
    FILE *file;
    char b;
 
    file = fopen("test.txt", "a");
    //fprintf(file,"Hello");
    fscanf(file,"%c",&b);
    //while((b = getc (file)) != EOF)
    printf("%c",b);
    fclose(file);
    return 0;
}
