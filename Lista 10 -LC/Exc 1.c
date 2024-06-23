/*
Escreva uma função em C que, dada uma lista l qualquer, inverta os elementos de l. O
protótipo da função de inversão é o seguinte: void inverte (TLC* l).
*/
#include "TLC.c"

void inverte (TLC* l){
    TLC *p=l,*q=l->prox;
    int tmp,t=1,x;
    while(q!=l){
      t++;
      q=q->prox;
    }
    x=t/2;
    while (x){
        for (int i=0;i<t-1;i++) q=q->prox;
        tmp = p->info;
        p->info=q->info;
        q->info=tmp;
        p=p->prox;
        q=l;
        t--;
        x--;
    }
}

int main(){
    TLC *l = NULL;
    int n;
    do{
        scanf("%d", &n);
        if(n < 0) break;
        l = TLC_insere(l, n);
    }while(1);
    printf("lista og:\n");
    TLC_imprime(l);
    printf("\n");
    inverte(l);
    printf("lista invertida:\n");
    TLC_imprime(l);
    printf("\n");
    TLC_libera(l);
    return 0;
}
