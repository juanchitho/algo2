/* 

    El código presentado pierde memoria. Libérela. Puede asumir que el malloc no falla.

*/

#include <stdlib.h>

const size_t MAX_LARGO = 5;


int main() {
    int** vector = malloc(MAX_LARGO * sizeof(int*));
   
    for (int i = 0; i < MAX_LARGO; i++)
        vector[i] = malloc(sizeof(int));

    for (int j = 0; i < MAX_LARGO; i++){
        int* numero = i+j;
        vector[i] = numero;
    }

    return 0;
}

