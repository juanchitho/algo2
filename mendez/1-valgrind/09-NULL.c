
#include <stdlib.h>

int main() {
    char* num = NULL;
    return 0;
}

/*
    Nueva palabra clave: NULL. Este valor (que es igual a 0, a false y a \0) se utiliza en el ámbito de punteros para indicar un puntero que no apunta 
    a algo válido. Es decir, este puntero no apunta a memoria válida que se pueda acceder. 
    Por lo tanto, "está libre", se lo puede utilizar para apuntar a algo nuevo.
    Así, distinguimos entre los punteros que apuntan a algo inválido (NULL) y los que apuntan a algo válido y deben liberarse (!= NULL).

    Compilá y ejecutá el código. Pierde memoria? Hay algún problema?
*/
