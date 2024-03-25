#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char** strings = NULL;
  int tope = 0;

  char linea[4];
  while(strcmp(linea, "salir")== 0) {
    printf("ingrese una linea de texto (\"salir\" para terminar): ");
    //usuario ingresa una palabra
    scanf(" %s", linea);
  }



  return 0;
}
