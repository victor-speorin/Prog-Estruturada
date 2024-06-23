/*
Refaça a Q1, escrevendo uma função em C que, dada uma lista l qualquer, inverta os
elementos de l em uma outra lista de saída. Portanto, a lista de entrada não pode ser
alterada. O protótipo da função de inversão é o seguinte: TLC* inverte (TLC* l).
*/
#include "TLC.c"

TLC* inverte (TLC* l){
    TLC *lresp = NULL, *p=l->prox;
    int tam=1;
    while (p!=l){
        p=p->prox;
        tam++;
    }
    while (tam) {
        for (int i = 0; i < tam - 1; i++) p = p->prox;
        lresp = TLC_insere(lresp,p->info);
        p=l;
        tam--;
    }
    return lresp;
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
    TLC *lresp = inverte(l);
    printf("lista invertida:\n");
    TLC_imprime(lresp);
    printf("\n");
    printf("lista og:\n");
    TLC_imprime(l);
    printf("\n");
    TLC_libera(l);
    TLC_libera(lresp);
    return 0;
}
