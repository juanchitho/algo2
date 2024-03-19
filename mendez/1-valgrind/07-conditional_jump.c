
#include <stdlib.h>

int main() {
    char* letra = malloc(sizeof(char));
    int num;
    if (*letra == 'A')
        num = 0;
    else
        num = 8;
    num++; //esta línea es para que no chillen los flags del compilador
    free(letra);
    return 0;
}

/*

    Vuelvo a llamar a malloc, y libero luego de acceder, así que no debería haber problemas, no? Compilá y ejecutá para averiguarlo.

    ... Salió un error?

    ==56814== Conditional jump or move depends on uninitialised value(s)
    ==56814==    at 0x10918C: main (07-conditional_jump.c:7)
    ==56814==  Uninitialised value was created by a heap allocation
    ==56814==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
    ==56814==    by 0x10917E: main (07-conditional_jump.c:5)
    ==56814== 
    ==56814== 
    ==56814== HEAP SUMMARY:
    ==56814==     in use at exit: 0 bytes in 0 blocks
    ==56814==   total heap usage: 1 allocs, 1 frees, 1 bytes allocated
    ==56814== 
    ==56814== All heap blocks were freed -- no leaks are possible
    ==56814== 
    ==56814== For lists of detected and suppressed errors, rerun with: -s
    ==56814== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

    Sí, saltó un error. Vemos que la memoria sí fue liberada, pero que hubo un nuevo tipo de error: Conditional jump depends on uninitialised value(s).
    Este error nos dice que estamos intentando tomar una decisión (en este caso, es el chequeo del if de la línea 7) con una variable que tiene basura, 
    que no fue inicializada. De hecho, nos reporta que la variable que intento leer que no fue inicializada fue creada en la línea 5.

    Este es un warning, fijate que el programa no se detuvo abruptamente, terminó de ejecutarse. 
    Pero no debería ocurrir, es un potencial bug y el propio valgrind te lo está avisando.
*/

