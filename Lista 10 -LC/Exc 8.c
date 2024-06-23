/*
Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1
e l2 são iguais. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1 se
as listas são iguais e 0, caso contrário. O protótipo desta função é o seguinte:
int igual (TLC *l1, TLC *l2).
*/
#include "TLC.c"
int igual (TLC *l1, TLC *l2){
    TLC *p1 = l1, *p2=l2;
    int t1=1,t2=1;
    while (p1->prox!=l1){
        t1++;
        p1=p1->prox;
    }
    while (p2->prox!=l2){
        t2++;
        p2=p2->prox;
    }
    if (t1!=t2) return 0; // se o tamanho for != retorno 0
    if (p1->info!=p2->info) return 0;
    TLC *aux1 = p1;
    p1=p1->prox;
    p2=p2->prox;
    while (p1!=aux1){
        if (p1->info!=p2->info) return 0;
        p1=p1->prox;
        p2=p2->prox;
    }
    return 1;
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
    n=igual(l1,l2);
    if (n) printf("iguais!");
    else printf("nao :(");
    TLC_libera(l1);
    TLC_libera(l2);
    return 0;
}