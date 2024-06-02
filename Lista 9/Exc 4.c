/*
Implemente uma função que copie uma lista. A lista original deve permanecer
inalterada. O protótipo da função é o seguinte: TLDE *copia (TLDE *l).
*/
#include "stdio.h"
#include "TLDE.c"

TLDE* copia (TLDE* l){
    TLDE *lr = NULL, *p=l;
    while (p->prox) p=p->prox;
    while(p){
        lr = TLDE_insere(lr,p->info);
        p=p->ant;
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
    lr = copia(l);
    printf("lista copia:\n");
    TLDE_imprime(lr);
    printf("\n");
    printf("lista og apos:\n");
    TLDE_imprime(l);
    printf("\n");
    TLDE_libera(l);
    return 0;
}
