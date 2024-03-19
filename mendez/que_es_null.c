#include <stdlib.h>

int main()
{
  //int *memoria = 0;
  //memoria[1] = 3;
  //return memoria[0];
  int *memoria = malloc(10000);
  if(memoria == NULL){
    return -1;
  }
  return 0;
}
