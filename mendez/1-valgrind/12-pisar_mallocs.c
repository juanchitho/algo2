
#include <stdlib.h>

int main() {
    char* letra = malloc(sizeof(char));
    letra = malloc(sizeof(char));
    free(letra);
    return 0;
}

/*

    Otro error muy común, lo creas o no. Qué error decís que salte? Invalid read? Segfault? Compilá, ejecutá y averigualo.

    ==57471== HEAP SUMMARY:
    ==57471==     in use at exit: 1 bytes in 1 blocks
    ==57471==   total heap usage: 2 allocs, 1 frees, 2 bytes allocated
    ==57471== 
    ==57471== 1 bytes in 1 blocks are definitely lost in loss record 1 of 1
    ==57471==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
    ==57471==    by 0x10917E: main (12-pisar_mallocs.c:5)
    ==57471== 
    ==57471== LEAK SUMMARY:
    ==57471==    definitely lost: 1 bytes in 1 blocks
    ==57471==    indirectly lost: 0 bytes in 0 blocks
    ==57471==      possibly lost: 0 bytes in 0 blocks
    ==57471==    still reachable: 0 bytes in 0 blocks
    ==57471==         suppressed: 0 bytes in 0 blocks
    ==57471== 
    ==57471== For lists of detected and suppressed errors, rerun with: -s
    ==57471== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

    Vemos que no saltó ningún seg fault, así que el programa se ejecutó en su totalidad. También vemos que hay dos allocs para un free. 
    Exactamente, nos faltaron frees.
    
    Este ejercicio parece tonto, pero revela un detalle muy importante: uno no hace frees de punteros. Hace frees de memoria.

    Fijate que primero pedimos memoria en la línea 5. Ese bloque de memoria es válido y debe ser liberado. Luego volvemos a pedir memoria, en la 6, 
    y almacenamos la dir de memoria en la misma variable. Este es otro bloque de memoria, igual de válido y que también debe ser liberado. 
    En la línea 7 liberamos uno de los bloques, el último reservado, ya que tenemos esa dirección en la variable. Pero, qué pasó con el primer bloque?
    Cómo accedemos a él? Lamentablemente ya no es posible, la única referencia que teníamos estaba en la variable `letra`, que pisamos con otra dirección.
    Esta memoria no puede ser recuperada. Cuidado con pisar punteros, asegurate de no perder referencias a memoria.

*/
