#include <stdlib.h>

int main() {
    char* ptr_letra = malloc(sizeof(char));
    *ptr_letra = 'A'; //inicializo la memoria
    char letra = *(ptr_letra+1);
    letra++; //no te preocupes por esta línea, es para que el compilador no chille
    free(ptr_letra);
}


/*

    Decís que esto funciona sin errores? Qué valor se le debería asignar a `letra`?

    Compilamos, ejecutamos y obtenemos

    ==57019== Invalid read of size 1
    ==57019==    at 0x10918E: main (08-invalid_read.c:6)
    ==57019==  Address 0x4a57041 is 0 bytes after a block of size 1 alloc'd
    ==57019==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
    ==57019==    by 0x10917E: main (08-invalid_read.c:4)
    ==57019== 
    ==57019== 
    ==57019== HEAP SUMMARY:
    ==57019==     in use at exit: 0 bytes in 0 blocks
    ==57019==   total heap usage: 1 allocs, 1 frees, 1 bytes allocated
    ==57019== 
    ==57019== All heap blocks were freed -- no leaks are possible
    ==57019== 
    ==57019== For lists of detected and suppressed errors, rerun with: -s
    ==57019== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)


    De nuevo la memoria se libera bien, pero tenemos un error nuevo. Éste es el primo de invalid write, invalid read. 
    Si invalid write nos dice que estamos queriendo escribir en memoria que no nos pertenece, invalid read nos indica que 
    estamos queriendo leer de memoria que no nos pertenece.
    En este caso, logramos este error en la línea 6, con aritmética de punteros; desreferenciamos lo que estaba al lado en la memoria reservada, 
    no la memoria reservada en sí. Tal vez en este código parece obvio el problema, pero te sorprenderías cuántas veces cometemos este
    tipo de errores de +-1, sobre todo en vectores.
*/