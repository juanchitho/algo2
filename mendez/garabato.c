#include <stdio.h>
/*
int main() {
  void* a;
  char* b = a;
  char** c = a;

  b[0] = 'l';//si se puede
  c[0][10] = 'm';//si se puede
  //a[1] = 2;// no se puede, tampoco se puede c=a+1(puntero de tipo void usado en aritmetica (esta mal))

  return 0;
}
*/

int main()
{
  unsigned int a = 900;
  unsigned int* p_a = &a;

  unsigned char* cp_a = (unsigned char*)&a;
  unsigned char b = cp_a[1];

  printf("Valor de b: %i \n",b);

  return 0;
}
