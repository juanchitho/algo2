/*

    El código presentado pierde memoria. Libérela. Puede asumir que los alloc no fallan.

*/


#include <stdlib.h>

int main() {
    int **vector = malloc(sizeof(int *));
    *vector = malloc(sizeof(int));
    **vector = 18;

    vector = realloc(vector, sizeof(int*) * 2);
    //qué hay ahora en `**vector` ?

    return 0;
}
