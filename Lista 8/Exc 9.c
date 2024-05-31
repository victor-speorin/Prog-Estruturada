/*
Implemente uma função em C que, dadas duas listas, faça a concatenação das
mesmas ao final de l1. O protótipo da função é o seguinte: TLSE* junta_listas (TLSE*
l1, TLSE* l2).
*/
#include "stdio.h"
#include "TLSE.c"
TLSE* junta_listas (TLSE* l1, TLSE* l2){
    TLSE *p1 = l1;
    for (;p1->prox ;p1=p1->prox);
    p1->prox=l2;
    return l1;
}
int main(){
    TLSE *l1 = TLSE_inicializa();
    TLSE *l2 = TLSE_inicializa();
    int x;
    printf("insira a primeira lista:\n ");
    do{
        scanf("%d", &x);
        if (x<0) break;
        l1 = TLSE_ins_ini(l1, x);
    }while(1);
    printf("\ninsira a segunda lista:\n");
    do{
        scanf("%d", &x);
        if (x<0) break;
        l2 = TLSE_ins_ini(l2, x);
    }while(1);
    printf("lista1:\n");
    TLSE_imp_rec(l1);
    printf("\n");
    printf("lista2:\n");
    TLSE_imp_rec(l2);
    printf("\n");
    l1 = junta_listas(l1,l2);
    printf("lista concatenada:\n");
    TLSE_imp_rec(l1);
    printf("\n");
    TLSE_lib_rec(l1);
    TLSE_lib_rec(l2);
    return 0;
}
