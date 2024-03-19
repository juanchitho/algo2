/*

    Ya vimos cómo utilizar la función free para liberar memoria que habíamos reservado con malloc. 
    Vimos que la falta de un free a su correspondiente malloc implicaba que se perdía memoria, que no es liberada correctamente
    y se mostraba un error en Valgrind. Pero vamos a ver que tener demasiados free tampoco es la solución.

*/

#include <stdlib.h>
#include <stdio.h>

int main() {
    //Pedimos memoria
    char* letra = malloc(sizeof(char));

    //Accedamos a ese espacio y escribamos la letra A allí
    *letra = 'A';

    //Para ver si funcionó la asignación, mostremos por pantalla este valor
    printf("\n\n El valor almacenado en el heap es %d \n\n", *letra);

    //Liberamos la memoria reservada en el heap que es apuntada por la dir almacenada en letra
    free(letra);

    //Por las dudas, liberamos de nuevo
    free(letra);

    return 0;
}

/*

    Compilá con la línea
    ```
    gcc -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -o0 -g 02-doble_free.c -o 02-doble_free
    ```

    Notá que lo único que cambió de esta línea con respecto al ejercicio anterior es el .c compilado y el nombre del ejecutable
    resultante. A partir de este ejercicio, no se aclarará la línea de compilación, modificá ésta con el nombre correcto de los
    archivos.

    Ejecutá con esta línea
    ```
    valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=2 --show-leak-kinds=all --trace-children=yes ./02-doble_free
    ```

    Funcionó? Revisemos el log de valgrind



    ==56039== HEAP SUMMARY:
    ==56039==     in use at exit: 0 bytes in 0 blocks
    ==56039==   total heap usage: 2 allocs, 3 frees, 1,025 bytes allocated
    ==56039== 
    ==56039== All heap blocks were freed -- no leaks are possible
    ==56039== 
    ==56039== For lists of detected and suppressed errors, rerun with: -s
    ==56039== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)


    Nuevamente hay un 1 errors from 1 context, así que algo salió mal. Revisamos dónde perdimos memoria, pero dice que "All heap blocks were freed",
    así que en realidad toda la memoria sí fue liberada. Revisamos el ratio de allocs y frees y vemos algo raro: hay más frees que allocs.

    Si vemos un poquito más arriba (sí, los errores de valgrind se leen de abajo para arriba), vemos que aparece el mensaje

    ==56039== Invalid free() / delete / delete[] / realloc()
    ==56039==    at 0x483CA3F: free (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
    ==56039==    by 0x1091DE: main (02-doble_free.c:26)
    ==56039==  Address 0x4a57040 is 0 bytes inside a block of size 1 free'd
    ==56039==    at 0x483CA3F: free (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
    ==56039==    by 0x1091D2: main (02-doble_free.c:23)
    ==56039==  Block was alloc'd at
    ==56039==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
    ==56039==    by 0x10919E: main (02-doble_free.c:14)
    ==56039== 

    Este error nos está indicando que se hizo un free de más. Dice que en main se había pedido memoria (línea 14) y que esa memoria se había liberado 
    correctamente en la línea 23 pero que luego se volvió a intentar liberar, en la línea 26.

    Tener frees de menos es un error. Pero tener frees de más también está mal. Elegimos mantener el free de la 23, eliminando el de la 26. 
    Si compilás y ejecutás nuevamente con valgrind, funciona?

*/