/*

Decidimos que el stack no es suficiente, y queremos usar el heap. Aprendamos cómo usarlo, y qué herramientas
nos ayudan a programar mejor con él.


Pidamos memoria para un entero utilizando la función `malloc`.
*/

#include <stdlib.h>
#include <stdio.h>

int main() {
    //Aquí pedimos memoria con malloc al heap. El tamaño de la memoria pedida es la de un entero. 
    //La dirección de memoria la almacenamos en la variable `numero`.
    int* numero = malloc(sizeof(int));

    //A esta altura del código, `numero` tiene una dirección de memoria que apunta a un espacio de memoria
    //reservado, así que `numero` no tiene basura. Pero la memoria que es apuntada por `numero` sí tiene basura,
    //no está inicializada.

    //Accedamos a ese espacio y escribamos el número 2024 allí.
    *numero = 2024;

    //Para ver si funcionó la asignación, mostremos por pantalla este valor
    printf("\n\n El valor almacenado en el heap es %i \n\n", *numero);

    //??
    free(numero);


    return 0;
}

/*

    1. Intentá compilar este código con la línea
    ```
    gcc -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -o0 -g 01-malloc.c -o 01-malloc
    ```

    2. Ejecutalo con la línea
    ```
    ./01-malloc
    ```

    Se mostró bien el número, anda!

    3. Ahora ejecutalo con esta línea
    ```
    valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=2 --show-leak-kinds=all --trace-children=yes ./01-malloc
    ```

    ... Funcionó? Arriba de todo, el mensaje se imprimió, pero aparte salió un mensaje extra, y abajo de todo dice esto

    
    ==55587== 
    ==55587== HEAP SUMMARY:
    ==55587==     in use at exit: 4 bytes in 1 blocks
    ==55587==   total heap usage: 2 allocs, 1 frees, 1,028 bytes allocated
    ==55587== 
    ==55587== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
    ==55587==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
    ==55587==    by 0x10917E: main (01-malloc.c:16)
    ==55587== 
    ==55587== LEAK SUMMARY:
    ==55587==    definitely lost: 4 bytes in 1 blocks
    ==55587==    indirectly lost: 0 bytes in 0 blocks
    ==55587==      possibly lost: 0 bytes in 0 blocks
    ==55587==    still reachable: 0 bytes in 0 blocks
    ==55587==         suppressed: 0 bytes in 0 blocks
    ==55587== 
    ==55587== For lists of detected and suppressed errors, rerun with: -s
    ==55587== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

    Dice que hay un error... así que no funcionó?

    La línea utilizada es un comando del programa Valgrind, que se utiliza para verificar, entre muchas cosas, pérdidas de referencia
    a memoria. En este caso, nos está remarcando que perdimos 4 bytes en un bloque . Es decir, perdimos 4 bytes de memoria. También nos 
    dice que hay dos allocs y un solo free, y que un bloque de 4 bytes fue "definitely lost".

    Si volvés al código original, verás que hay un malloc pero ningún free. Como regla general, por cada malloc, tiene que haber un free.
    Sabemos que lo bueno de la memoria dinámica es que podemos pedirla en tiempo de ejecución, por lo que podemos decidir cuánto y cuándo
    pedimos con variables en nuestro programa, que van cambiando según la situación lo requiera (el usuario decidiendo por consola el tamaño, por ejemplo).
    Pero lo malo es que la memoria la pedimos y la liberamos nosotros. No lo hace el programa por su cuenta, como con el stack, debemos 
    nosotros pedirle al sistema operativo que libere la memoria cuando ya no la queremos usar.

    Agregá en la línea 28 el código
    ```
    free(numero);
    ```

    y ejecutá nuevamente con valgrind.

    Ahora qué aparece? Funcionó?

    Si ejecutás de nuevo, verás que no funcionó, aunque cambiamos el código...

    No te olvides, estamos trabajando en C. Si modificás el código fuente, tenés que volver a compilar el código y luego ejecutarlo nuevamente. 
    Estábamos ejecutando una versión vieja, desactualizada.

    Compilá de nuevo y ejecutá con valgrind. Ahora sí funcionó?


    Así se ve un mensaje sin errores de valgrind

    ==55747== 
    ==55747== HEAP SUMMARY:
    ==55747==     in use at exit: 0 bytes in 0 blocks
    ==55747==   total heap usage: 2 allocs, 2 frees, 1,028 bytes allocated
    ==55747== 
    ==55747== All heap blocks were freed -- no leaks are possible
    ==55747== 
    ==55747== For lists of detected and suppressed errors, rerun with: -s
    ==55747== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


    Nada de memoria reservada a la hora de terminar el programa, hay tantos allocs como frees y todo el heap fue liberado. 0 errores de 0.
    Éxito.
    
    Si hay un mensaje diferente en tu reporte de Valgrind, es que hubo algún error. En esta guía, vamos a repasar los más comúnes.
*/
