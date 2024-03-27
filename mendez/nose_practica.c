#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{
	//char* vector[10];
	printf("Parametros enviados al programa \n");
	for(int i=0; i<argc; i++)
		printf("parametro %i: %s \n",i,argv[i]);
	return 0;
}
