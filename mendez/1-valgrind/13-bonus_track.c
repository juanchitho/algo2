
#include <stdio.h>
#include <stdlib.h>

int main() {
    char* letra = malloc(sizeof(char));
    letra = "Hola!";
    //printf("\n\n El valor almacenado en el heap es %p \n\n", *letra);
    free(letra);
    return 0;
}


/*
    Como bonus track, te dejo este ejercicio. Decís que funciona? Salta algún error? Qué está pasando?

    Para resolver este ejercicio, pensá en lo siguiente:
    1. Estás pisando un puntero. Qué pasa con la memoria original? se pierde la referencia de memoria y no se puede recuperar
    2. Dónde vive el literal "Hola!"? En qué zona de memoria? Se le puede hacer free?
    3. Yo reservé memoria para un char, pero el literal "Hola!" son 5 chars. Qué pasará con la memoria?

*/
/*
Estás pisando un puntero. ¿Qué pasa con la memoria original?
    En la línea letra = "Hola!";, estás asignando la dirección de memoria del literal de cadena "Hola!" al puntero letra. Esto significa que estás sobrescribiendo la dirección de memoria que previamente estaba siendo apuntada por letra, lo cual resulta en una pérdida de la referencia al bloque de memoria que habías asignado dinámicamente en la línea anterior (char* letra = malloc(sizeof(char));). Esto crea una fuga de memoria porque la memoria asignada dinámicamente no se libera correctamente antes de perder la referencia a ella.

¿Dónde vive el literal "Hola!"? ¿En qué zona de memoria? ¿Se le puede hacer free?
    El literal "Hola!" vive en la sección de memoria de solo lectura de la aplicación. Intentar liberar esta memoria con free() resultaría en un comportamiento indefinido y probablemente causaría un error en tiempo de ejecución.

Yo reservé memoria para un char, pero el literal "Hola!" son 5 chars. ¿Qué pasará con la memoria?
    En realidad, aunque asignaste memoria solo para un char con malloc(sizeof(char));, el puntero letra se sobrescribe con la dirección del literal "Hola!". Esto significa que no hay fugas de memoria en términos de la asignación original, pero sí hay un acceso incorrecto a la memoria, ya que estás intentando almacenar una dirección de cadena en un solo carácter, lo que resulta en comportamiento indefinido.*/
