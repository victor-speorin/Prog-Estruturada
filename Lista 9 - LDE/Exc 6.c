/*
Defina uma função em C que, dada uma lista l qualquer, retorne, numa lista de saída,
os elementos ímpares e os elementos pares da lista l, na ordem em que os elementos
aparecem em l. Ao final da execução desta função, a lista resultante terá todos os
elementos da lista l (primeiro os ímpares, depois os pares, na ordem em que eles
aparecem em l), e a lista l continuará contendo os seus elementos. O protótipo da função
é o seguinte: TLDE* i_p (TLDE *l).
*/
#include "stdio.h"
#include "TLDE.c"
TLDE* i_p (TLDE *l){
    TLDE *lr=NULL, *p=l;
    int tam=0,x;
    while (p){
        if (p->info%2!=0) lr = TLDE_insere(lr,p->info);
        p=p->prox;
        tam++;
    }
    p=l;
    while (p){
        if (p->info%2==0) lr = TLDE_insere(lr,p->info);
        p=p->prox;
    }
    TLDE *pf = lr;
    p=lr;
    while (pf->prox) pf = pf->prox;
    for (int i=0;i<tam/2;i++){
        x = p->info;
        p->info = pf ->info;
        pf->info = x;
        p=p->prox;
        pf=pf->ant;
    }
    return lr;
}
int main(){
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
    lr = i_p(l);
    printf("lista resposta:\n");
    TLDE_imprime(lr);
    printf("\n");
    printf("lista og apos alteracao:\n");
    TLDE_imprime(l);
    printf("\n");
    TLDE_libera(lr);
    TLDE_libera(l);
    return 0;
}