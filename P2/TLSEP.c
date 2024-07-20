#include "TLSEP.h"

TLSEP* TLSEP_ins_ini(TLSEP *l, char *pal, int linha){
  TLSEP *novo = (TLSEP *) malloc(sizeof(TLSEP));
  novo->prox = l;
  strcpy(novo->pal, pal);
  novo->num_vezes = 1;
  novo->linhas = TLSE_ins_fim(NULL, linha);
  return novo;
}

void TLSEP_imprime(TLSEP *l){
  TLSEP *p = l;
  while(p){
    printf("%s (%d): ", p->pal, p->num_vezes);
    TLSE_imprime(p->linhas);
    printf("\n");
    p = p->prox;
  } 
}

void TLSEP_libera(TLSEP *l){
  TLSEP *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    TLSE_libera(q->linhas);
    free(q);
  } 
}

TLSEP* TLSEP_busca(TLSEP *l, char *pal){
  TLSEP *resp = l;
  while((resp) && (strcmp(resp->pal, pal))) resp = resp->prox; 
  return resp;
}
