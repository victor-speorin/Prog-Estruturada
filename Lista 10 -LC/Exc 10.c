/*
Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1
é a inversão de l2. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1
se as listas estão invertidas e 0, caso contrário. O protótipo desta função é o seguinte:
int Contrario (TLC *l1, TLC *l2).
*/
#include "TLC.c"
int Contrario (TLC *l1, TLC *l2){
    TLC *p1 = l1, *p2=l2;
    int t=1;
    while (p2->prox!=l2) {
        p2=p2->prox;
        t++;
    }
    while (t){
        if (p1->info!=p2->info) return 0;
        p2=l2;
        for (int i=0;i<t-2;i++) p2=p2->prox;
        p1=p1->prox;
        t--;
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
    n=Contrario(l1,l2);
    if (n) printf("contrarias!");
    else printf("nao :(");
    TLC_libera(l1);
    TLC_libera(l2);
    return 0;
}