#include "TLC.h"

int main(void){
  TLC *l = NULL;
  int n;
  do{
    scanf("%d", &n);
    if(n < 0) break;
    l = TLC_insere(l, n);
  }while(1);

  TLC_imprime(l);
  TLC_libera(l);
  return 0;
}
