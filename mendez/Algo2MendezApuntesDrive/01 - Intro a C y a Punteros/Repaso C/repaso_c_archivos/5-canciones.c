#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.h"

typedef struct colaborador colaborador_t; // Tipo de dato struct colaborador como colaborador_t

#define MAX_LINEA 50
#define MAX_NOMBRE 100
#define CANTIDAD_VALORES 2
#define FORMATO_LECTURA "%*[^=]=%[^\n]\n"


void leer_archivo (char *nombre_archivo)
{
        FILE *archivo = fopen(nombre_archivo, "r");
        if (!archivo)
                return;

        char linea1[MAX_NOMBRE];
        char linea2[MAX_NOMBRE];

        char *linea_leida1 = fgets(linea1, MAX_LINEA, archivo); // nombre
        char *linea_leida2 = fgets(linea2, MAX_LINEA, archivo);  // nombre cancion

        colaborador_t colab;

        sscanf(linea1, FORMATO_LECTURA, colab.nombre);
        sscanf(linea2, FORMATO_LECTURA, colab.cancion);

        while (linea_leida1 && linea_leida2) {
                printf("Nombre: %s - Canción: %s\n", colab.nombre, colab.cancion);

                linea_leida1 = fgets(linea1, MAX_LINEA, archivo);
                linea_leida2 = fgets(linea2, MAX_LINEA, archivo);

                sscanf(linea1, FORMATO_LECTURA, colab.nombre);
                sscanf(linea2, FORMATO_LECTURA, colab.cancion);
        }

        fclose(archivo);
}


int main ()
{
        leer_archivo("playlist.txt");

        return 0;
} 