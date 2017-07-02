#include <stdio.h>
 int main(int argc, char const *argv[])
 {
 	#pragma omp for
 		for (int i = 0; i<16; i++)
 			printf("%i\n",i);
 	
 	return 0;
 }