/*
Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1
é a inversão de l2. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1
se as listas estão invertidas e 0, caso contrário. O protótipo desta função é o seguinte: int
Contrario (TLDE *l1, TLDE *l2).
*/
#include "stdio.h"
#include "TLDE.c"
int Contrario (TLDE *l1, TLDE *l2){
    TLDE *p1 = l1, *p2=l2;
    int t1=1,t2=1;
    while (p1->prox && p2->prox){
        p1=p1->prox;
        p2=p2->prox;
        t1++;
        t2++;
    }
    if (t1!=t2) return 0;
    p1=l1;
    while (p1){
        if (p1->info!=p2->info) return 0;
        p1=p1->prox;
        p2=p2->ant;
    }
    return 1;
}

int main(){
    TLDE *l1 = NULL, *l2 = NULL;
    int x;
    printf("insira a primeira lista:\n ");
    do{
        scanf("%d", &x);
        if (x<0) break;
        l1 = TLDE_insere(l1, x);
    }while(1);
    printf("\ninsira a segunda lista:\n");
    do{
        scanf("%d", &x);
        if (x<0) break;
        l2 = TLDE_insere(l2, x);
    }while(1);
    printf("lista1:\n");
    TLDE_imprime(l1);
    printf("\n");
    printf("lista2:\n");
    TLDE_imprime(l2);
    printf("\n");
    x = Contrario(l1,l2);
    if (x) printf("contrarias\n");
    else printf("nao\n");
    TLDE_libera(l1);
    TLDE_libera(l2);
    return 0;
}


