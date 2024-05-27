/*
Considerando as seguintes declarações de lista encadeada:

typedef struct lista{
int info;
struct lista *prox;
}TLSE;

Escreva uma função em C que, dada uma lista l qualquer, inverta os elementos de l.
O protótipo da função de inversão é o seguinte: void inverte (TLSE* l).
*/
#include "stdio.h"
#include "stdlib.h"
typedef struct lista{
    int info;
    struct lista *prox;
}TLSE;

TLSE *TLSE_inicializa(){
    return NULL;
}

void TLSE_imp_rec(TLSE *l) {
    if (l) {
        TLSE_imp_rec(l->prox);
        printf("%d\n", l->info);
    }
}

TLSE *TLSE_ins(TLSE *l,int x){
    TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
    novo -> info = x;
    novo -> prox = l;
    return novo;
}

void inverte (TLSE* l){

}

void TLSE_lib_rec(TLSE *l){
    if (l){
        TLSE_lib_rec(l->prox);
        free(l);
    }
}

int main(){
    TLSE *l = TLSE_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if (x<0) break;
        l = TLSE_ins(l, x);
    }while(1);
    printf("lista normal:\n");
    TLSE_imp_rec(l);
    printf("\n");
    inverte(l);
    printf("lista invertida:\n");
    TLSE_imp_rec(l);
    TLSE_lib_rec(l);
    return 0;
}