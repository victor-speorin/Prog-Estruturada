/*
Implemente uma função em C que, dadas duas listas, faça a concatenação das
mesmas ao final de l1. O protótipo da função é o seguinte: TLDE* junta_listas (TLDE*
l1, TLDE* l2).
*/
#include "stdio.h"
#include "TLDE.c"
TLDE* junta_listas (TLDE* l1, TLDE* l2){
    TLDE *p = l1;
    while (p->prox) p = p->prox;
    p->prox = l2;
    return l1;
}
int main(){
    TLDE *l1 = NULL, *l2 = NULL;
    int x;
    printf("insira a primeira lista:\n ");
    do{
        scanf("%d", &x);
        if (x<0) break;
        l1 = TLDE_insere(l1, x);
    }while(1);
    printf("\ninsira a segunda lista:\n");
    do{
        scanf("%d", &x);
        if (x<0) break;
        l2 = TLDE_insere(l2, x);
    }while(1);
    printf("lista1:\n");
    TLDE_imprime(l1);
    printf("\n");
    printf("lista2:\n");
    TLDE_imprime(l2);
    printf("\n");
    l1 = junta_listas(l1,l2);
    printf("lista concatenada:\n");
    TLDE_imprime(l1);
    printf("\n");
    TLDE_libera(l1);
    TLDE_libera(l2);
    return 0;
}
