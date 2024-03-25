#include <stdio.h>//vamos a necesitar entrada y salida standard
#include <stdlib.h>//memoria dinamica
#include <string.h>

//vector de strings

int main(int argc, char *argv[])
{
  //¿por que el vector de strings es de tipo char*?
  //porque es un vector de strings , al programa le paso texto, le paso varios elementos de texto
  //y el texto es string , los strings son char*
  //por lo tanto cada palabra que le paso es un char* , si estoy pasando varios char*
  //entonces estoy pasando un vector de char*
  //*argv[] es un vector de alguna cantidad indeterminada de char*
  //en este caso -> char *argv[] == char **argv
  printf("Parametros enviados al programa\n");

  //for (int i=0; i < argc; i++) {
  for (int i=0; argv[i] != NULL; i++) {
    printf("Parametro %i: %s \n", i, argv[i]);
  }
  return 0;
}
