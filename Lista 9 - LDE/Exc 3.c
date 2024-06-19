/*
Escreva uma função em C que, dada uma lista l qualquer, desloque uma vez os
elementos de l, de acordo com n. Se n é ímpar, o elemento que está na última posição
passa a ser o primeiro quando a lista é deslocada. Senão, o elemento que está na
primeira posição passa a ser o último. O protótipo desta função é o seguinte: TLDE*
desloca (TLDE* l, int n).
*/
#include "stdio.h"
#include "TLDE.c"
// n impar direita / n par esquerda
TLDE* desloca (TLDE* l,int n){
    TLDE *p = l;
    if(n%2==0){
        int x=p->info;
        while (p->prox){
            p->info = p->prox->info;
            p=p->prox;
        }
        p->info = x;
    }
    else {
        while (p->prox) p=p->prox;
        int x = p->info;
        while (p->ant){
            p->info = p->ant->info;
            p=p->ant;
        }
        p->info=x;
    }
    return l;
}

int main(void){
    TLDE *l = NULL;
    int x,n;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLDE_insere(l, x);
    }while(1);
    printf("agora digite o n: ");
    scanf("%d",&n);
    printf("lista og:\n");
    TLDE_imprime(l);
    printf("\n");
    l = desloca(l,n);
    printf("lista deslocada:\n");
    TLDE_imprime(l);
    printf("\n");
    TLDE_libera(l);
    return 0;
}
