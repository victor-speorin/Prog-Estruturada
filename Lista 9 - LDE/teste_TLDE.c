#include "TLDE.h"

int main(void){
  TLDE *l = NULL;
  int x;
  do{
    scanf("%d", &x);
    if(x < 0) break;
    l = TLDE_insere(l, x);
  }while(1);
  TLDE_imprime(l);
  printf("\n");

  TLDE_libera(l);
  return 0;
}

