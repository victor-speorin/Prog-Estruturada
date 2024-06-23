/*
Implemente uma função em C que, dadas duas listas, faça a concatenação das
mesmas ao final de l1. O protótipo da função é o seguinte:
TLC* junta_listas (TLC*l1, TLC* l2).
*/
#include "TLC.c"
TLC* junta_listas (TLC*l1, TLC* l2){
    TLC *p1 = l1->prox, *p2 = l2->prox;
    while (p1->prox!=l1) p1=p1->prox;
    while (p2->prox!=l2) p2=p2->prox;
    p1->prox = l2;
    while (p1!=p2) p1=p1->prox;
    p1->prox = l1;
    return l1;
}
int main(){
    TLC *l1 = NULL, *l2 = NULL;
    int n;
    printf("l1:\n");
    do{
        scanf("%d", &n);
        if(n < 0) break;
        l1 = TLC_insere(l1, n);
    }while(1);
    printf("l2:\n");
    do{
        scanf("%d", &n);
        if(n < 0) break;
        l2 = TLC_insere(l2, n);
    }while(1);
    printf("lista1 og:\n");
    TLC_imprime(l1);
    printf("\n");
    printf("lista2 og:\n");
    TLC_imprime(l2);
    printf("\n");
    l1=junta_listas(l1,l2);
    printf("lista concatenada:\n");
    TLC_imprime(l1);
    printf("\n");
    TLC_libera(l1);
    TLC_libera(l2);
    return 0;
}