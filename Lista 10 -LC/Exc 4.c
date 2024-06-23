/*
Implemente uma função que copie uma lista. A lista original deve permanecer
inalterada. O protótipo da função é o seguinte: TLC *copia (TLC *l).
*/
#include "TLC.c"
TLC *copia (TLC *l){
    TLC *p=l->prox, *resp = NULL;
    resp = TLC_insere(resp,l->info);
    while (p!=l){
        resp = TLC_insere(resp,p->info);
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
    TLC *lresp = copia(l);
    printf("lista copia:\n");
    TLC_imprime(lresp);
    printf("\n");
    printf("lista og:\n");
    TLC_imprime(l);
    printf("\n");
    TLC_libera(l);
    TLC_libera(lresp);
    return 0;
}