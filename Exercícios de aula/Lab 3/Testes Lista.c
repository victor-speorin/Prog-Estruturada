#include "stdio.h"
#include "stdlib.h"

typedef struct lse{
    int info;
    struct lse *prox;
}TLSE;

TLSE *TLSE_inicializa(){
    return NULL;
}

TLSE *TLSE_ins_ini(TLSE *l,int x){
    TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
    novo -> info = x;
    novo -> prox = l;
    return novo;
}

void TLSE_imprime(TLSE *l){
    TLSE *p=l;
    while (p){
        printf("%d\n",p->info);
        p = p->prox;
    }
}

void TLSE_imp_rec(TLSE *l) {
    if (l) {
        printf("%d\n", l->info);
        TLSE_imp_rec(l->prox);
    }
}

void TLSE_imp_rec_dec(TLSE *l){
    if (l){
        TLSE_imp_rec_dec(l->prox);
        printf("%d\n",l->info);
    }
}

void TLSE_libera(TLSE *l){
    TLSE *p = l, *t;
    while (p){
        t=p;
        p=p->prox;
        free(t);
    }
}

void TLSE_lib_rec(TLSE *l){
    if (l){
        TLSE_lib_rec(l->prox);
        free(l);
    }
}

int main(){
    TLSE *l=NULL, *l1=TLSE_inicializa();
    l= TLSE_ins_ini(l,1);
    l= TLSE_ins_ini(l,2);
    l= TLSE_ins_ini(l,0);
    TLSE_imp_rec(l);
    printf("\n");
    TLSE_imprime(l);
    printf("\n");
    TLSE_imp_rec_dec(l);
    printf("\n");
    TLSE_lib_rec(l);
    l=NULL;
    return 0;
}