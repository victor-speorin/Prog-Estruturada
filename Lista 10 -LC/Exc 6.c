/*
Defina uma função em C que, dada uma lista l qualquer, retorne, numa lista de saída,
os elementos ímpares e os elementos pares da lista l, na ordem em que os elementos
aparecem em l. Ao final da execução desta função, a lista resultante terá todos os
elementos da lista l (primeiro os ímpares, depois os pares, na ordem em que eles
aparecem em l), e a lista l continuará contendo os seus elementos. O protótipo da função
é o seguinte: TLC* i_p (TLC *l).
*/
#include "TLC.c"
TLC* i_p (TLC *l){
    TLC *resp= NULL, *p=l->prox;
    int x=0;
    if (l->info%2) resp=TLC_insere(resp,l->info);
    else {
        x = l->info;
    }
    while (p!=l){
        if (p->info%2) resp = TLC_insere(resp,p->info);
        p=p->prox;
    }
    p=p->prox;
    if (x) resp = TLC_insere(resp,x);
    while (p!=l){
        if (!(p->info%2)) resp = TLC_insere(resp,p->info);
        p=p->prox;
    }
    return resp;
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
    TLC *lresp = i_p(l);
    printf("lista resposta:\n");
    TLC_imprime(lresp);
    printf("\n");
    printf("lista og:\n");
    TLC_imprime(l);
    printf("\n");
    TLC_libera(l);
    TLC_libera(lresp);
    return 0;
}