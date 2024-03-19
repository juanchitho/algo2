#include <stdio.h>

int sumar_dos(int n,char* m)
{
  return n+2;
}
int multiplicar_dos(int n,char* m)
{
  return n*2;
}

int multiplicar_tres(int n,char* m)
{
  return n*3;
}
int realizar_operacion(int n,int (*funcion)(int,char*))
{
  //if(strcmp(operacion,"sumar_dos")==0){
    //return sumar_dos(n);
  //}
  return funcion(n,"");
}
int main()
{
  int n= 1;
  //asi declaro un puntero a funcion
  //int (*puntero)(int);
  //se puede tener tambien un vector de funciones:
  int(*funciones[3])(int,char*);

  //puntero[0]=sumar_dos;
  funciones[0]=sumar_dos;
  funciones[1]=multiplicar_dos;
  funciones[2]=multiplicar_tres;
  n = realizar_operacion(n, funciones[1]);
  printf("n = %i\n",n);
  return 0;
}
