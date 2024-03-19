#include <stdlib.h>

int main() {
    int* letra = malloc(sizeof(int));

    char* ptr_null = NULL;
    *ptr_null = 10;

    free(letra);
    return 0;
}

/*
    Vimos recién que sí es posible llamar a free con un ptr que apunta a NULL. Se podrá escribir ese espacio de memoria? Pista, no, pero es muy
    probable que a lo largo de la cursada intentes hacer justamente esto, así que aprovechemos y veamoslo.

    ==57275== Invalid write of size 1
    ==57275==    at 0x10918F: main (11-desreferenciar_NULL.c:7)
    ==57275==  Address 0x0 is not stack'd, malloc'd or (recently) free'd
    ==57275== 
    ==57275== 
    ==57275== Process terminating with default action of signal 11 (SIGSEGV)
    ==57275==  Access not within mapped region at address 0x0
    ==57275==    at 0x10918F: main (11-desreferenciar_NULL.c:7)
    ==57275==  If you believe this happened as a result of a stack
    ==57275==  overflow in your program's main thread (unlikely but
    ==57275==  possible), you can try to increase the size of the
    ==57275==  main thread stack using the --main-stacksize= flag.
    ==57275==  The main thread stack size used in this run was 8388608.
    ==57275== 
    ==57275== HEAP SUMMARY:
    ==57275==     in use at exit: 4 bytes in 1 blocks
    ==57275==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
    ==57275== 
    ==57275== 4 bytes in 1 blocks are still reachable in loss record 1 of 1
    ==57275==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
    ==57275==    by 0x10917E: main (11-desreferenciar_NULL.c:4)
    ==57275== 
    ==57275== LEAK SUMMARY:
    ==57275==    definitely lost: 0 bytes in 0 blocks
    ==57275==    indirectly lost: 0 bytes in 0 blocks
    ==57275==      possibly lost: 0 bytes in 0 blocks
    ==57275==    still reachable: 4 bytes in 1 blocks
    ==57275==         suppressed: 0 bytes in 0 blocks
    ==57275== 
    ==57275== For lists of detected and suppressed errors, rerun with: -s
    ==57275== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
    Segmentation fault (core dumped)

    Empezamos de abajo para arriba. Primero, vemos que tenemos un segmentation fault, lo que nos indica que el programa cortó de manera abrupta. 
    Así que el error que encontró, no lo pudo sobrellevar y dejó de ejecutarse; todo lo que estaba después de esa línea defectuosa, no lo ejecutó, 
    esto es importante.
    
    Vemos que hay memoria que se perdió, que hay un alloc (el de `letra`) pero ningún free... aunque sí hay un free(letra) en el código...
    
    Seguimos subiendo y llegamos al Invalid read, donde dice que "Address 0x0 is not stack'd, malloc'd or (recently) free'd".
    Así que confirmamos que no. No podemos leer ni escribir en la dirección de memoria NULL.

    Pero, por qué perdimos memoria? Si los NULL no hay que liberarlos y a la `letra` la liberamos, qué pasó? 
    Lo que pasó es que ocurrió un seg fault. Este tipo de señales, como mencioné más arriba, cortan la ejecución del programa en el momento que 
    se lanzó la señal. Todo lo demás no se ejecuta. Nunca se llegó a ejecutar el free de la `linea`, por lo que a fines prácticos, esa memoria se perdió.

    De este ejercicio, llevate estos dos puntos:
    1. NO se puede desreferenciar un ptr que apunte a NULL. Por lo tanto, cada vez que te llegue un ptr de una función pública, deberás verificarlo,
        no vaya a ser que te mandaron un NULL y vos intentás desreferenciarlo. También deberíamos chequear que los allocs no devuelvan NULL, 
        pero para simplificar el ejercicio, en esta guía asumimos que  no falla nunca.
    
    2. Que se haya perdido memoria NO QUIERE DECIR NECESARIAMENTE que faltan frees. Normalmente sí, faltan. Pero si el programa se corta a mitad de ejecución
        por causa de un segfault, por ejemplo, los frees no se llegarán a ejecutar y Valgrind reportará una pérdida de memoria. Antes de decidir que falta 
        liberar memoria y plagar el código con frees, revisá si el programa llegó a ejecutarse en su totalidad. Si fue así y aún así perdés memoria, sí, 
        faltan frees. Si no se llegó a completar la ejecución, a priori no sabés si faltan frees o no, porque los que estaban después de la línea 
        problemática no se ejecutaron. Resolvé esa línea primero y después fijate si se libera toda la memoria.
*/
