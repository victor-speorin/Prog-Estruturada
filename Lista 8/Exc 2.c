/*
Refaça a Q1, escrevendo uma função em C que, dada uma lista l qualquer, inverta os
elementos de l em uma outra lista de saída. Portanto, a lista de entrada não pode ser
alterada. O protótipo da função de inversão é o seguinte: TLSE* inverte (TLSE* l).
*/
#include "stdio.h"
#include "TLSE.c"
TLSE* inverte(TLSE *l){
    TLSE* lc = TLSE_inicializa(), *p=l; // criando a lista nova e um ponteiro para a og
    for (;p;p=p->prox){
        lc = TLSE_ins_ini(lc,p->info); // colocando os elementos da og invertidamente na copia
    }
    return lc;
}
int main(){
    TLSE *l = TLSE_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if (x<0) break;
        l = TLSE_ins_ini(l, x);
    }while(1);
    printf("lista og:\n");
    TLSE_imp_rec(l);
    printf("\n");
    TLSE *resp = inverte(l);
    printf("lista nova invertida:\n");
    TLSE_imp_rec(resp);
    printf("\n");
    printf("lista og verficacao:\n");
    TLSE_imp_rec(l);
    printf("\n");
    TLSE_lib_rec(l);
    TLSE_lib_rec(resp);
    return 0;
}