#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

const char * const allowedFlags[] = { "--size","--sort","--print"};
const int const allowedFlagsLength = sizeof allowedFlags / sizeof allowedFlags[0];

void validateFlags(const char * const flags[], const int const length)
{
	bool flagExists = false;
	int incorrectFlagIndex = -1;
	for(int i=1; i<length; i++)
	{	
		flagExists=false;
		for(int j=0; j<allowedFlagsLength; j++ )
			if(strcmp(flags[i],allowedFlags[j]) == 0) 
				{
					flagExists=true;
					incorrectFlagIndex = -1;
				}
			else incorrectFlagIndex = i;
		if (!flagExists) 
		{
			printf("[-]Error: %s incorrect flag was given!", flags[incorrectFlagIndex] );
			exit(EXIT_FAILURE);
		}
	}
}

int main(const int const argc,const char * const argv[])
{
	if(argc > 1) validateFlags(argv,argc);
	printf("[+] SALLUT!!!");
	return EXIT_SUCCESS;
}