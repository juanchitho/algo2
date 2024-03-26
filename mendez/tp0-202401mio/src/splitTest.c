#include "split.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función auxiliar para contar la cantidad de ocurrencias de un caracter en una cadena
int contar_ocurrencias(const char* string, char separador) {
    int contador = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == separador) {
            contador++;
        }
    }
    return contador;
}

char** split(const char* string, char separador) {
    // Contamos la cantidad de subcadenas que se generarán
    int cantidad_subcadenas = contar_ocurrencias(string, separador) + 1;

    // Asignamos memoria para el arreglo de punteros a cadenas
    char** subcadenas = (char**)malloc((cantidad_subcadenas + 1) * sizeof(char*));
    if (subcadenas == NULL) {
        return NULL; // En caso de error al asignar memoria
    }

    int inicio = 0; // Indice de inicio de la subcadena actual
    int indice_subcadenas = 0; // Índice para recorrer el arreglo de punteros a cadenas

    // Recorremos la cadena original para encontrar los separadores
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == separador) {
            // Asignamos memoria para almacenar la subcadena
            subcadenas[indice_subcadenas] = (char*)malloc((i - inicio + 1) * sizeof(char));
            if (subcadenas[indice_subcadenas] == NULL) {
                // En caso de error al asignar memoria
                // Liberamos la memoria asignada previamente
                for (int j = 0; j < indice_subcadenas; j++) {
                    free(subcadenas[j]);
                }
                free(subcadenas);
                return NULL;
            }
            // Copiamos la subcadena desde la cadena original
            strncpy(subcadenas[indice_subcadenas], string + inicio, i - inicio);
            subcadenas[indice_subcadenas][i - inicio] = '\0'; // Terminamos la subcadena
            inicio = i + 1; // Actualizamos el índice de inicio para la siguiente subcadena
            indice_subcadenas++; // Pasamos a la siguiente posición del arreglo de punteros a cadenas
        }
    }

    // Copiamos la última subcadena (o la única si no hay separadores al final )
    subcadenas[indice_subcadenas] = strdup(string + inicio);
    if (subcadenas[indice_subcadenas] == NULL) {
        // En caso de error al asignar memoria
        // Liberamos la memoria asignada previamente
        for (int j = 0; j < indice_subcadenas; j++) {
            free(subcadenas[j]);
        }
        free(subcadenas);
        return NULL;
    }

    // Marcamos el final del arreglo de punteros a cadenas con NULL
    subcadenas[indice_subcadenas + 1] = NULL;

    return subcadenas;
}

int main() {
    const char* string = "123:456:789:0";
    char** subcadenas = split(string, ':');

    if (subcadenas != NULL) {
        // Imprimir las subcadenas
        printf("Subcadenas resultantes:\n");
        for (int i = 0; subcadenas[i] != NULL; i++) {
            printf("%s\n", subcadenas[i]);
            free(subcadenas[i]);
        }
        free(subcadenas);
    } else {
        printf("Error: no se pudo dividir la cadena.\n");
    }

    return 0;
}
