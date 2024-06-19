/*
Defina uma função em C que, dada uma lista l qualquer, ordene os elementos de l
em uma outra lista de saída. Portanto, a lista de entrada não pode ser alterada. O
protótipo da função desta função é o seguinte: TLDE * ordena (TLDE* l).
*/
#include "stdio.h"
#include "TLDE.c"

TLDE * ordena (TLDE* l){
    TLDE *lc = copia(l), *p =lc, *lr = NULL;
    int tam = 0;
    while (p){
        tam++;
        p=p->prox;
    }
    for(int i=0;i<tam;i++) {
        p=lc;
        int maior = p->info;
        while (p) {
            if (p->info > maior) maior = p->info;
            p = p->prox;
        }
        lr = TLDE_insere(lr,maior);
        lc = TLDE_retira(lc,maior);
    }
    return lr;
}

int main(){
    TLDE *l = NULL, *lr;
    int x;
    do{
        scanf("%d", &x);
        if (x<0) break;
        l = TLDE_insere(l, x);
    }while(1);
    printf("lista og:\n");
    TLDE_imprime(l);
    printf("\n");
    lr = ordena(l);
    printf("lista resposta:\n");
    TLDE_imprime(lr);
    printf("\n");
    printf("lista og apos a alteracao:\n");
    TLDE_imprime(l);
    printf("\n");
    TLDE_libera(l);
    TLDE_libera(lr);
    return 0;
}