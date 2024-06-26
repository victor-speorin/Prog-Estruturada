/*
 *
*/
#include "alm.c"

TLSE *meio (TLSE *l, int *pos) {
    if (!l->prox) return l;
    int x=0;
    TLSE *rapido = l->prox, *meio = l;
    while (rapido->prox){
        if (rapido->prox->prox) rapido = rapido->prox->prox;
        else rapido=rapido->prox;
        meio = meio->prox;
        x++;
    }
    (*pos) = x;
    return meio;
}

int main(){
    TLSE *l = NULL;
    int n;
    do{
        scanf("%d", &n);
        if(n < 0) break;
        l = TLSE_insere(l, n);
    }while(1);
    int pos;
    TLSE_imprime(l);
    printf("\n");
    TLSE *resp = meio(l, &pos);
    if(resp)
        printf("O elemento do meio da lista (info: %d) esta na pos %d\n", resp->info, pos);
    TLSE_libera(l);
    return 0;
}