#include <limits.h>
#include "TP.h"

int menor(TP *p){
  if(TP_vazia(p)) exit(1);
  TP *aux = TP_inicializa();
  int resp = TP_pop(p), prox;
  while(!TP_vazia(p)){
     prox = TP_pop(p);
     if(resp > prox){
       TP_push(aux, resp);
       resp = prox;
     }
    else TP_push(aux, prox);
  }
  while(!TP_vazia(aux))
     TP_push(p, TP_pop(aux));
  TP_libera(aux);
  return resp;
}

void ordena(TP *p){
  if(TP_vazia(p)) return;
  TP *aux = TP_inicializa();
  while(!TP_vazia(p))
      TP_push(aux, menor(p));
  while(!TP_vazia(aux))
      TP_push(p, TP_pop(aux));
  TP_libera(aux);
}

void imprime(TP *p){
  if(TP_vazia(p)) return;
  TP *aux = TP_inicializa();
  while(!TP_vazia(p)){
       int x = TP_pop(p);
       printf("%d ", x);
       TP_push(aux, x);
  }
  printf("\n");
  while(!TP_vazia(aux))
      TP_push(p, TP_pop(aux));
  TP_libera(aux);
}

int main(void){
    TP *p = TP_inicializa();
    printf("p:\n");
    int n;
    while(1){
      scanf("%d", &n);
      if(n < 0) break;
      TP_push(p, n);
    }
    imprime(p);
    printf("\n");
    ordena(p);
    printf("p:\n");
    imprime(p);
    printf("\n");
    TP_libera(p);

  return 0;
}
