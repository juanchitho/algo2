#include <stdio.h>

#define MAX_NOMBRE 20

void saludar()
{
  char nombre[20];
  char i = 100;
  char j = 50;
  nombre[0] = 76; //en la tabla ascii L=76
  nombre[1] = 'u';
  nombre[2] = 'c';
  nombre[3] = 'a';
  nombre[4] = 's';
  nombre[5] = 0;

  //printf("ingresar nombre:");
  //scanf("%c",&nombre)

  //asignacion en c, es de tipado statico ->significa que:
  //cuando una variable se crea de un tipo , ese tipo perdura por todo el programa
  //la regla seria ->igualdad de la asignacion en los dos lados, ejemplo que rompe con la regla
  //nombre = "Lucas";
  //char[20] != char*

  //un puntero es una variable que guarda una direccion de memoria nada mas (definicion key)
  //char* nombre2 = "Lucas";// los strings con comillas dobles se los conoce como strings literales
  //char* nombre2 = nombre;//"Lucas" si lo defino asi se guarda en un lugar llamado roData; es un lugar en la memoria distinto que solo tiene formato de lectura
  //  si lo asigno como nombre si se puede modificaar porque lo estoy asignando a un lugar en la memoria en el cual se donde esta , esta definido de lectura y escritura y esta definido en el stack
  //nombre2[2]= 'C';

  printf("%s\n",nombre);
  //printf("%s\n",nombre2);

  char* nombre2 = nombre;
  char** nombre3 = &nombre2;//busca la posicion de memoria donde esta alojado , no el contenido (uso del &)
  //estas dos asignaciones son equivalentes
  //nombre2[5]= 'x';
  //(nombre3[0])[5]= 'x';
  char* apuntado = nombre3[0];
  //desferenciar significado:
  char* otro_puntero = nombre3[2];
  int a = 0;//cosa a;
  int *b = &a;//cosa *b;
  int **c = &b;//cosa **c;
  int ***d = &c;
  //c[0][0] = 10; //a => 10
  //**c = 10; //es lo mismo que lo de arriba y abajo pero con otra anotacion
  //*c[0] = 10;
  //(*c)[0] = 10;
  
  //b[5] == *(b+5)
  
  void* memoria;

  (*nombre3)[2] = 'C';
  printf("nombre -->%p\n",nombre);
  printf("nombre2 -->%p\n",nombre2);
  printf("nombre3 -->%p\n",nombre3);
  //printf("i= %c , j = %c \n",i,j);
  //
  //&
  //mismas formas de escribir 
  if(b[0] == a){
    printf("OK");
  }
  if (*(b+0) == a) {
    printf("OK");
  }
  if (*b == a) {
    printf("OK");
  }
}

int main()
{
  saludar();
  return 0;
}
