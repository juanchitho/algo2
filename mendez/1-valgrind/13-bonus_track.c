
#include <stdlib.h>

int main() {
    char* letra = malloc(sizeof(char));
    letra = "Hola!";
    free(letra);
    return 0;
}


/*
    Como bonus track, te dejo este ejercicio. Decís que funciona? Salta algún error? Qué está pasando?

    Para resolver este ejercicio, pensá en lo siguiente:
    1. Estás pisando un puntero. Qué pasa con la memoria original?
    2. Dónde vive el literal "Hola!"? En qué zona de memoria? Se le puede hacer free?
    3. Yo reservé memoria para un char, pero el literal "Hola!" son 5 chars. Qué pasará con la memoria?

*/