/*
Refaça a Q1, escrevendo uma função em C que, dada uma lista l qualquer, inverta os
elementos de l em uma outra lista de saída. Portanto, a lista de entrada não pode ser
alterada. O protótipo da função de inversão é o seguinte: TLDE* inverte (TLDE* l).
*/
#include "stdio.h"
#include "TLDE.c"

TLDE* inverte (TLDE* l){
    TLDE *lr = NULL;
    while(l){
        lr = TLDE_insere(lr,l->info);
        l=l->prox;
    }
    return lr;
}

int main(void){
    TLDE *l = NULL, *lr = NULL;
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLDE_insere(l, x);
    }while(1);
    printf("lista og:\n");
    TLDE_imprime(l);
    printf("\n");
    lr = inverte(l);
    printf("lista invertida:\n");
    TLDE_imprime(lr);
    printf("\n");
    printf("lista og apos:\n");
    TLDE_imprime(l);
    printf("\n");
    TLDE_libera(l);
    return 0;
}
