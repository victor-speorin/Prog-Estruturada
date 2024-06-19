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
#include "TLSE.c"

void inverte (TLSE* l) {
    TLSE *p = l, *pp; // dois ponteiros para l
    int tam = 0, x, y;
    for (; p; p = p->prox) tam++; // tamanho
    p = l, x = tam; // voltando com p e declarando um fim
    for (int i=0;i<tam/2;i++){
        pp=p; // colocando pp onde o p estiver
        for (int j=0;j<x-1;j++){
            pp=pp->prox; //colocando pp no final
        }
        //trocando:
        y = p->info;
        p->info = pp->info;
        pp->info = y;
        p=p->prox; // colocando o p uma pra frente
        x-=2; // fazendo o fim ser -2 por conta do for
    }
}
int main(){
    TLSE *l = TLSE_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if (x<0) break;
        l = TLSE_ins_ini(l, x);
    }while(1);
    printf("lista normal:\n");
    TLSE_imp_rec(l);
    printf("\n");
    inverte(l);
    printf("lista invertida:\n");
    TLSE_imp_rec(l);
    printf("\n");
    TLSE_lib_rec(l);
    return 0;
}