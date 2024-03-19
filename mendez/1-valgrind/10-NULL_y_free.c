#include <stdlib.h>

int main() {
    char* num = NULL;
    free(num);
    return 0;
}


/*
    Dijimos que un puntero que apunta a NULL es inválido, que apunta a memoria inválida. Eso es porque el espacio de memoria 0x0 está reservado 
    y no se puede leer ni escribir. Se podrá llamar a free, entonces? Compilá, ejecutá y verificalo.
*/
