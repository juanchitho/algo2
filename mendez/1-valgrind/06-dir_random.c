
#include <stdlib.h>

int main() {
    int* num = (int*)0xDEADBEEF; //... y esto qué es? Funciona?
    *num = 18;
    free(num);
    return 0;
}


/*
    Sabemos que los punteros almacenan direcciones de memoria. 0xDEADBEEF es un número en hexadecimal, el 3735928559 en decimal, por si tenías curiosidad. 
    Creé un nuevo puntero que apuntase a un lugar arbitrario de memoria, que yo elegí, no que malloc me diese. Intento modificar esa memoria que elegí al azar,
    funcionará?

    Lo compilamos, ejecutamos y vemos esto

    ==56625== Invalid write of size 4
    ==56625==    at 0x109162: main (06-dir_random.c:6)
    ==56625==  Address 0xdeadbeef is not stack'd, malloc'd or (recently) free'd
    ==56625== 
    ==56625== 
    ==56625== Process terminating with default action of signal 11 (SIGSEGV)
    ==56625==  Access not within mapped region at address 0xDEADBEEF
    ==56625==    at 0x109162: main (06-dir_random.c:6)
    ==56625==  If you believe this happened as a result of a stack
    ==56625==  overflow in your program's main thread (unlikely but
    ==56625==  possible), you can try to increase the size of the
    ==56625==  main thread stack using the --main-stacksize= flag.
    ==56625==  The main thread stack size used in this run was 8388608.
    ==56625== 
    ==56625== HEAP SUMMARY:
    ==56625==     in use at exit: 0 bytes in 0 blocks
    ==56625==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
    ==56625== 
    ==56625== All heap blocks were freed -- no leaks are possible
    ==56625== 
    ==56625== For lists of detected and suppressed errors, rerun with: -s
    ==56625== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
    Segmentation fault (core dumped)

    Otro invalid write. Te imaginás por qué?
    Pero claro, elegimos esa memoria al azar. Y quién me dio permiso a mí para escribir ahí? Nadie! Normalmente es malloc quien me da permiso para 
    escribir y leer la memoria del heap, pero acá yo escribí una dir random para acceder. Por supuesto que el sistema operativo no me va a dejar 
    modificar cualquier espacio de memoria.
    
    De hecho, lo dice clarito: "Access not within mapped region at address 0xDEADBEEF". No tengo permisos, saltó una señal del sisop para terminar el programa.

    Fijate que no perdí memoria porque nunca reservé nada. Pero aún así tengo un error, y un segmentation fault.

    Intentá ejecutar este error sin valgrind. Sale el error igual?

    Algunos errores, como éste, se mostrarán aunque no se ejecute el programa con valgrind. Pero otros, como los leaks de memoria, sólo los reporta valgrind. 
    Es cierto que ejecutar con valgrind es más costoso que ejecutar sin él, pero siempre que puedas, ejecutá con valgrind.

*/