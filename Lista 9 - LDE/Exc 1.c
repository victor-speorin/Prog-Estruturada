/*
Escreva uma função em C que, dada uma lista l qualquer, inverta os elementos de l. O
protótipo da função de inversão é o seguinte: void inverte (TLDE* l).
*/
#include "stdio.h"
#include "TLDE.c"
void inverte (TLDE* l){
    TLDE *p = l, *pf = l;
    int t=1, x;
    while (pf->prox){
        t++;
        pf=pf->prox;
    }
    for (int i=0;i<t/2;i++){
        x = p->info;
        p->info = pf ->info;
        pf->info = x;
        p=p->prox;
        pf=pf->ant;
    }
}
int main(void){
    TLDE *l = NULL;
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLDE_insere(l, x);
    }while(1);
    printf("lista og:\n");
    TLDE_imprime(l);
    printf("\n");
    inverte(l);
    printf("lista invertida:\n");
    TLDE_imprime(l);
    printf("\n");
    TLDE_libera(l);
    return 0;
}
