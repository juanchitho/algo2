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
    split("123:456:789:0", ':'); //=> ["123", "456", "789", "0", NULL]

    // Caso 2: split("Bienvenidos a Algo2", ' ')
    const char* caso2 = "Bienvenidos a Algo2";
    char** resultado2 = split(caso2, ' ');
    printf("Resultado del Caso 2:\n");
    if (resultado2 != NULL) {
        for (int i = 0; resultado2[i] != NULL; i++) {
            printf("%s\n", resultado2[i]);
            free(resultado2[i]);
        }
        free(resultado2);
    } else {
        printf("Error en el Caso 2\n");
    }
    printf("\n");

    // Caso 3: split("Hola mundo", '?')
    const char* caso3 = "Hola mundo";
    char** resultado3 = split(caso3, '?');
    printf("Resultado del Caso 3:\n");
    if (resultado3 != NULL) {
        for (int i = 0; resultado3[i] != NULL; i++) {
            printf("%s\n", resultado3[i]);
            free(resultado3[i]);
        }
        free(resultado3);
    } else {
        printf("Error en el Caso 3\n");
    }
    printf("\n");

     // Caso 4: split(",1,2,3,", ',')
    const char* caso4 = ",1,2,3,";
    char** resultado4 = split(caso4, ',');
    printf("Resultado del Caso 4:\n");
    if (resultado4 != NULL) {
        for (int i = 0; resultado4[i] != NULL; i++) {
            printf("%s\n", resultado4[i]);
            free(resultado4[i]);
        }
        free(resultado4);
    } else {
        printf("Error en el Caso 4\n");
    }
    printf("\n");

    // Caso 5: split("", ',')
    const char* caso5 = "";
    char** resultado5 = split(caso5, ',');
    printf("Resultado del Caso 5:\n");
    if (resultado5 != NULL) {
        for (int i = 0; resultado5[i] != NULL; i++) {
            printf("%s\n", resultado5[i]);
            free(resultado5[i]);
        }
        free(resultado5);
    } else {
        printf("Error en el Caso 5\n");
    }
    printf("\n");

    // Caso 6: split(NULL, ';')
    const char* caso6 = NULL;
    char** resultado6 = split(caso6, ';');
    printf("Resultado del Caso 6:\n");
    if (resultado6 != NULL) {
        for (int i = 0; resultado6[i] != NULL; i++) {
            printf("%s\n", resultado6[i]);
            free(resultado6[i]);
        }
        free(resultado6);
    } else {
        printf("Error en el Caso 6\n");
    }
    printf("\n");


    return 0;
}
