#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int tamanio = 100;
  char *texto = malloc(tamanio*sizeof(char));
  int tope = 0;
  while (tope < 500) {
    scanf("%s",texto+tope);
    tope = strlen(texto);
    if (tope >= tamanio/2) {
      tamanio *= 2;
      char* texto_aux = malloc(tamanio*sizeof(char));
      strcpy(texto_aux, texto);
      free(texto);
      texto=texto_aux;
    }

    printf("hasta ahora ingresaste esto : \n\n %s \n...............\n",texto);
  }
  free(texto);
  return 0;
}
