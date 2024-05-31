/*
Implemente uma função que copie uma lista. A lista original deve permanecer
inalterada. O protótipo da função é o seguinte: TLSE *copia (TLSE *l).
*/
#include "stdio.h"
#include "TLSE.c"
TLSE* copia(TLSE *l){
    TLSE* lc = TLSE_inicializa(), *p=l; // criando a lista nova e um ponteiro para a og
    int tam = 0, x;
    for (; p; p = p->prox) tam++; // tamanho
    p=l, x=tam; // voltando p para o inicio de l
    for (int i=0;i<tam;i++){
        for (int j=0;j<x-1;j++){
            p=p->prox; // colocando p primeiro no final, depois no penultimo, e assim vai...
        }
        lc = TLSE_ins_ini(lc,p->info); // colocando o ultimo de l no começo de lc
        x--; // diminuindo x para o p ir até x--, no caso o penultimo, antepenultimo e etc..
        p=l; // voltando p para o inicio a cada interação
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
    TLSE *resp = copia(l);
    printf("lista nova:\n");
    TLSE_imp_rec(resp);
    printf("\n");
    printf("lista og verficacao:\n");
    TLSE_imp_rec(l);
    printf("\n");
    TLSE_lib_rec(l);
    TLSE_lib_rec(resp);
    return 0;
}