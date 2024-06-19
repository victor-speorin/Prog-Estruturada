#include "TLSE.h"

TLSE* TLSE_inicializa(void){
  return NULL;
}

TLSE* copia(TLSE *l){
    TLSE* lc = TLSE_inicializa(), *p=l;
    int tam = 0, x;
    for (; p; p = p->prox) tam++;
    p=l, x=tam;
    for (int i=0;i<tam;i++){
        for (int j=0;j<x-1;j++){
            p=p->prox;
        }
        lc = TLSE_ins_ini(lc,p->info);
        x--;
        p=l;
    }
    return lc;
}

TLSE* desloca_esq (TLSE* l){
    TLSE *p =l;
    for (;p && p->prox; p = p->prox) p->info = p->prox->info; // o atual recebe o proximo
    return l;
}

TLSE* TLSE_ins_fim(TLSE *l, int info){
    TLSE *novo = (TLSE*)malloc(sizeof(TLSE));
    novo->info = info;
    novo->prox = NULL;
    if(!l) return novo;
    TLSE *p = l;
    while(p->prox) p = p->prox;
    p->prox = novo;
    return l;
}

TLSE* TLSE_ins_ini(TLSE *l, int elem){
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->prox = l;
  novo->info = elem;
  return novo;
}

void TLSE_imprime(TLSE *l){
  TLSE *p = l;
  while(p){
    printf("%d ", p->info);
    p = p->prox;
  } 
}

void TLSE_imp_rec(TLSE *l){
  if(l){
    printf("%d ", l->info);
    TLSE_imp_rec(l->prox);
  }
}

void TLSE_imp_rec_rev(TLSE *l){
  if(l){
    TLSE_imp_rec_rev(l->prox);
    printf("%d ", l->info);
  }
}

void TLSE_libera(TLSE *l){
  TLSE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q);
  } 
}

void TLSE_lib_rec(TLSE *l){
  if(l){
    TLSE_lib_rec(l->prox);
    printf("liberando o elemento %d...\n", l->info);
    free(l);
  }
}

TLSE* TLSE_retira(TLSE *l, int elem){
  TLSE *p = l, *ant = NULL;
  while((p) && (p->info != elem)){
    ant = p;
    p = p->prox;
  }
  if(!p) return l;
  if(!ant) l = l->prox;
  else ant->prox = p->prox;
  free(p);
  return l;
}

TLSE* TLSE_retira_rec(TLSE *l, int elem){
  if(!l) return l;
  if(l->info == elem){
    TLSE *p = l;
    l = l->prox;
    free(p);
  }
  else l->prox = TLSE_retira_rec(l->prox, elem);
  return l;
}

TLSE* TLSE_busca(TLSE *l, int elem){
  TLSE *p = l;
  while((p) && (p->info != elem)) p = p->prox; 
  return p;
}

TLSE* TLSE_busca_rec(TLSE *l, int elem){
  if((!l) || (l->info == elem)) return l;
  return TLSE_busca_rec(l->prox, elem);
}

