/*

    El código presentado pierde memoria. Libérela. Puede asumir que el malloc no falla.

*/


#include <stdlib.h>

int main() {
    int *num = malloc(sizeof(int));
    int *vector = malloc(sizeof(int) * 8);

    return 0;
}
