
#include <stdlib.h>

int main() {

    //A primera vista vemos que el malloc estaba abajo del free, y que estamos liberando una variable que no fue inicializada.
    //... esto tiene sentido? Funciona?  
    int* num;
    free(num);
    num = malloc(sizeof(int));
    //free(num); //esto arreglaría el error?//no, no lo arregla
    return 0;
}


//Si intentás compilar, vemos que surge un error de compilación, porque num no está inicializada. Y tiene sentido, 
//no podés liberar lo que no pediste. Esta opción ni siquiera compila, mucho menos pasa valgrind sin errores.
