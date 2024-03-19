/*

    Vimos que sí o sí necesitamos un único free para cada malloc realizado. Pero, cuándo libero? Da lo mismo?

    Veamos diferentes momentos donde liberar la memoria solicitada y analicemos los errores de valgrind.

    Empecemos estableciendo un ejemplo del orden correcto para solicitar y liberar memoria del heap.

*/


#include <stdlib.h>

int main() {
    //Esta opción es la que venimos viendo hasta ahora que funciona.
    //Primero llamar a malloc y luego a un único free funciona.
    
    int* num = malloc(sizeof(int));
    *num = 18;
    free(num);
    return 0;
}
