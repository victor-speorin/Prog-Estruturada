/*
Crie uma função em C que remova todas as ocorrências de um elemento numa lista.
Seu protótipo O protótipo desta função é o seguinte: TLDE* rto (TLDE* l, int elem)
*/
#include "stdio.h"
#include "TLDE.c"
TLDE* rto (TLDE* l, int elem){
    TLDE *p=l;
    while (l->info==elem){
        l=l->prox;
        free(l->ant);
    }
    while (p){
        if (p->info==elem){
            if(p->ant) p->ant->prox=p->prox;
            if (p->prox) p->prox->ant=p->ant;
            TLDE *pa = p;
            p=p->prox;
            free(pa);
        }
        else p=p->prox;
    }
    return l;
}
int main(){
    TLDE *l = NULL;
    int x,n;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLDE_insere(l, x);
    }while(1);
    printf("elemento a ser retirado: ");
    scanf("%d",&n);
    printf("lista og:\n");
    TLDE_imprime(l);
    printf("\n");
    l = rto(l,n);
    printf("lista sem o elemento:\n");
    TLDE_imprime(l);
    printf("\n");
    TLDE_libera(l);
    return 0;
}