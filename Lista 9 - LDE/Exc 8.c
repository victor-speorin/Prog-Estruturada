/*
Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1
e l2 são iguais. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1 se
as listas são iguais e 0, caso contrário. O protótipo desta função é o seguinte: int igual
(TLDE *l1, TLDE *l2).
*/
#include "TLDE.c"
#include "stdio.h"
int igual (TLDE *l1, TLDE *l2){
    TLDE *p1 = l1, *p2 = l2;
    int tm1=1, tm2=1;
    while (p1->prox && p2->prox){
        p1=p1->prox;
        p2=p2->prox;
        tm1++;
        tm2++;
    }
    if (tm1!=tm2) return 0;
    while (p1){
        if (p1->info!=p2->info) return 0;
        p1=p1->ant;
        p2=p2->ant;
    }
    return 1;
}
int main() {
    TLDE *l1 = NULL, *l2 = NULL;
    int x;
    printf("digite a l1:\n");
    do {
        scanf("%d", &x);
        if (x < 0) break;
        l1 = TLDE_insere(l1, x);
    } while (1);
    printf("digite a l2:\n");
    do {
        scanf("%d", &x);
        if (x < 0) break;
        l2 = TLDE_insere(l2, x);
    } while (1);
    printf("lista 1 og:\n");
    TLDE_imprime(l1);
    printf("\n");
    printf("lista 2 og:\n");
    TLDE_imprime(l2);
    printf("\n");
    x = igual(l1,l2);
    if (x) printf("iguais\n");
    else printf("diferentes\n");
    TLDE_libera(l1);
    TLDE_libera(l2);
    return 0;
}

