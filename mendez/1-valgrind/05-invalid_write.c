

//Ahora el malloc está antes del free y el puntero fue inicializado correctamente.
//Esto funciona? Hay algún error?

#include <stdlib.h>

int main() {
    int* num = malloc(sizeof(int));
    *num = 18;
    free(num);
    *num = 20;
    return 0;
}

/*

    Lo compilamos, ejecutamos... y tenemos un nuevo error de valgrind: Invalid write

    ==56398== Invalid write of size 4
    ==56398==    at 0x10919D: main (05-invalid_write.c:12)
    ==56398==  Address 0x4a57040 is 0 bytes inside a block of size 4 free'd
    ==56398==    at 0x483CA3F: free (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
    ==56398==    by 0x109198: main (05-invalid_write.c:11)
    ==56398==  Block was alloc'd at
    ==56398==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
    ==56398==    by 0x10917E: main (05-invalid_write.c:9)
    ==56398== 
    ==56398== 
    ==56398== HEAP SUMMARY:
    ==56398==     in use at exit: 0 bytes in 0 blocks
    ==56398==   total heap usage: 1 allocs, 1 frees, 4 bytes allocated
    ==56398== 
    ==56398== All heap blocks were freed -- no leaks are possible
    ==56398== 
    ==56398== For lists of detected and suppressed errors, rerun with: -s
    ==56398== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)

    Este error surge cuando intentamos modificar memoria a la que no podemos acceder, porque no tenemos permisos. En este caso, 
    es a la memoria que la variable `num` apunta. Pero por qué no podemos acceder? Si lo pedimos con malloc...

    `malloc` como función reserva un espacio de memoria con el tamaño solicitado y devuelve la dir de memoria del primer byte de ese espacio.
    Ahora sólo esta variable (y cualquier copia de ella) pueden acceder a esta memoria. Nadie más puede hacerlo, está reservada para el valor de num.
    `free` como función libera esa memoria. Es decir, hace que la memoria ya no esté reservada sólo para tu variable, ahora cualquiera 
    (otra variable, otro programa...) puede reservarla y utilizarla.

    Cuando en la línea 11 liberamos esa memoria, ya no es nuestra. No podemos acceder a ese espacio de memoria, porque no nos corresponde. Es como si 
    te mudases de tu casa y al año quisieses volver a entrar. Sí, hace tiempo vivías ahí y era tuya, pero te mudaste. Sin importar si hay un nuevo 
    inquilino o si está vacía, la casa ya no es tuya, no podés entrar. Una vez que liberaste memoria, ya no podés accederla nuevamente.

    Que es exactamente lo que explicita el error. Dice que un bloque fue allocado en la línea 9 y que se liberó en la línea 11, 
    pero que en la línea 12 se intentó modificar.

*/
