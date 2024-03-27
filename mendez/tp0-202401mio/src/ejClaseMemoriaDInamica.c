#include "split.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split(const char *string, char separador) { return NULL; }

int main() {
  char **strings = NULL;
  int tope = 0;

  char linea[100];
  linea[0] = 0;
  int puedo_continuar = 1;
  while (strcmp(linea, "salir") != 0 && puedo_continuar) {
    printf("Ingresa una texto (\"salir\" para terminar): ");
    scanf("%s", linea);

    char **nuevos_strings = realloc(strings, (tope + 1) * (sizeof(char *)));

    if (nuevos_strings != NULL) {
      strings = nuevos_strings;
      strings[tope] = malloc((strlen(linea) + 1) * sizeof(char));

      if (strings[tope] != NULL)
        strcpy(strings[tope], linea);

      tope++;
    } else {
      puedo_continuar = 1;
      //printf("OJO qu no pude guardar esa palabra, continuemos \n");
    }
  }
  for (int i = 0; i < tope; i++) {
    printf("Linea %i: %s \n", i, strings[i]);
    free(strings[i]);
  }
  free(strings);
  return 0;
}
