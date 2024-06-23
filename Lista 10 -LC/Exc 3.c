/*
Escreva uma função em C que, dada uma lista l qualquer, desloque uma vez os
elementos de l, de acordo com n. Se n é ímpar, o elemento que está na última posição
passa a ser o primeiro quando a lista é deslocada. Senão, o elemento que está na
primeira posição passa a ser o último. O protótipo desta função é o seguinte:
TLC* desloca (TLC* l, int n).
*/
#include "TLC.c"

TLC* desloca (TLC* l, int n){
    TLC *p = l, *aux = l->prox;
    int t=1;
    while (aux!=p) {
        aux = aux->prox;
        t++;
    }
    if (n%2){
        while (aux->prox!=p) aux=aux->prox;
        int ult = aux->info;
        while (t){
            while (p->prox!=aux) p=p->prox;
            aux ->info = p->info;
            aux=l;
            for (int i=0;i<t-2;i++) aux = aux->prox;
            p=l;
            t--;
        }
        l->info = ult;
    }
    else{
        int pri = p->info;
        while (p->prox!=aux){
            p->info = p->prox->info;
            p=p->prox;
        }
        p->info=pri;
    }
    return l;
}

int main(){
    TLC *l = NULL;
    int n;
    do{
        scanf("%d", &n);
        if(n < 0) break;
        l = TLC_insere(l, n);
    }while(1);
    printf("agora insira o n: ");
    scanf("%d",&n);
    printf("lista og:\n");
    TLC_imprime(l);
    printf("\n");
    l=desloca(l,n);
    printf("lista deslocada:\n");
    TLC_imprime(l);
    printf("\n");
    TLC_libera(l);
    return 0;
}
