#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// complejidad computacional
// O(1) + 2 O(n) + n * (2 O(n) + (2 O(1)))
// 2 O(1) + 2 O(n²)
// O(n²) --> en el infinito

int comparar_strings(char *s1, char *s2) {
  int i = 0; // O(1)
  // para mejorar el algoritmo
  int len_s1 = strlen(s1);
  int len_s2 = strlen(s2);

  if (len_s1 != len_s2) // 2* O(n)
    return -1;          // O(1)

  // s1 y s2 en definitiva son punteros a char, y un puntero a char no es mas
  // que un vector de char.(estoy comparando 2 vectores) comparamos caracter a
  // caracter strcmp()--> devuelve 0 si son iguales

  // n veces
  while (i < len_s1 && i < len_s2) { // O(n) + O(n)
    if (s1[i] != s2[i]) {            // O(1)
      return -1;                     // O(1)
    }
    i++; // O(1)
  }
  return 0; // O(1)
}

int otra_forma_de_comparar_strings(char *s1, char *s2) {
  while (*s1 != 0 && *s2 != 0) {
    if (*s1 != *s2)
      return -1;
    s1++;
    s2++;
  }
  // esto podria ponerse de otra forma , coinsiderenado que:
  // false == 0
  // true != 0
  if (*s1 == 0 && *s2 == 0) { // quedaria-> if(!*s1 && *s2)
    return 0;
  }
  return -1;
}

// complejidad computacional
// sabemos que el teorema maestro no funciona en este caso
// el teorema maestro es para los algoritmos de tipo : divide - conquista
// CS(n) = 5 O(1) + CS(n - 1)
// CS(n-1) = 5 O(1) + CS(n - 2)
// CS(n-2) = 5 O(1) + CS(n - 3)
//...
// CS(2) = 5 O(1) + CS(1)
// CS(1) = 5 O(1) + CS(0)
// CS(0) = 5 O(1)
//
// 5 O(1) * n => O(n)
int comparar_strings_recursiva(char *s1, char *s2) {
  if (*s1 == 0 && *s2 == 0)
    return 0;

  if (*s1 != *s2)
    return -1;
  return comparar_strings_recursiva(s1 + 1, s2 + 1);
  // diferencia entre hacer ++ y + 1
  //++ es un operador unario , modifica
  //+ 1 pasa una copia modificada y le suma uno , no lo modifica
  // en este caso s1 no quedaria modificado
}

char *copiar_string(char *destino, char *origen) {
  *destino = *origen;
  if (*destino == 0)
    return destino;
  return copiar_string(destino + 1, origen + 1);
}

int main() {
  char **strings = NULL;
  int tope = 0;

  char linea[100];
  linea[0] = 0;
  int puedo_continuar = 1;

  while (comparar_strings(linea, "salir") != 0 && puedo_continuar) {
    printf("ingrese una linea de texto (\"salir\" para terminar): ");
    scanf("%s", linea);

    char **nuevos_strings = realloc(strings, (tope + 1) * (sizeof(char *)));

    if (nuevos_strings != NULL) {
      strings = nuevos_strings;
      strings[tope] = malloc((strlen(linea) + 1) * sizeof(char));

      if (strings[tope] != NULL)
        strcpy(strings[tope], linea);
      tope++;
    } else {
      puedo_continuar = 0;
    }
  }

  for (int i = 0; i < tope; i++) {
    printf("Linea %i: %s \n", i, strings[i]);
    free(strings[i]);
  }

  free(strings);
  return 0;
}
