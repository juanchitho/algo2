#include "split.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int contador_de_separadores(const char* string, char separador)
{
    int contador = 0;
    int i;
    for(i = 0; string[i] != '\0'; i++ ) {
        if (string[i] == separador)
            contador++;
    }
    return contador;
}

char** split(const char* string, char separador)
{
    //armamos el char**
    int catidad_de_elementos_vec = contador_de_separadores(string, separador) + 1;
    char** vec_de_punteros = (char**)malloc((catidad_de_elementos_vec + 1) * (sizeof(char*)));
    if (vec_de_punteros == NULL){
        return NULL;
    }
    int posicion_inicial_de_palabra = 0;
    int indice_del_vector = 0;
    int puedo_continuar = 0;
    int i,j;

    for(i=0; string[i] != '\n' && puedo_continuar != 1; i++){
        if (string[i] == separador) {
            vec_de_punteros[indice_del_vector] = malloc((i - posicion_inicial_de_palabra + 1) * (sizeof(char)));
            if (vec_de_punteros[indice_del_vector] == NULL) {
                puedo_continuar = 1;
            } else {
                strcpy(vec_de_punteros[indice_del_vector], string + posicion_inicial_de_palabra);
                vec_de_punteros[indice_del_vector][i - posicion_inicial_de_palabra] = '\0';
                posicion_inicial_de_palabra = i + 1;
                indice_del_vector++;
            }
        }
    }

    if(!puedo_continuar) {
        vec_de_punteros[indice_del_vector] = malloc((strlen(string) - posicion_inicial_de_palabra + 1) * (sizeof(char)));
        if (vec_de_punteros[indice_del_vector] == NULL) {
            puedo_continuar = 1;
        } else {
            strcpy(vec_de_punteros[indice_del_vector], string + posicion_inicial_de_palabra);
        }
    }

    if (puedo_continuar){
        for (j = 0; j <= indice_del_vector; j++) {
            free(vec_de_punteros[j]);
        }
        free(vec_de_punteros);
        return NULL;
        
    }
    
    vec_de_punteros[catidad_de_elementos_vec] = NULL;
    
    return vec_de_punteros;
}