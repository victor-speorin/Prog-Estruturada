/*
A questão pedia que, em uma passada só, retornassemos uma lista que
seria a segunda metade de uma LDE, e a lista original viraria a primeira metade.
se fossem impares elementos, a lista original ficaria com um a mais.
*/
#include "TLDE.c"
TLDE *f(TLDE *l){
    if (!l) return NULL; // adicionei apenas isso
    TLDE *rapido = l, *meio = l;
    if (!l->prox) return meio;
    while (rapido){
        if (rapido->prox) rapido=rapido->prox->prox;
        else rapido=rapido->prox;
        meio=meio->prox;
    }
    meio->ant->prox=NULL;
    meio->ant=NULL;
    return meio;
}

int main(){
    TLDE *l = NULL;
    int x;
    do{
        scanf("%d",&x);
        if (x<0) break;
        l = TLDE_insere(l,x);
    } while (1);
    printf("l:\n");
    TLDE_imprime(l);
    printf("\n");
    TLDE *r= f(l);
    TLDE_imprime(l);
    printf("\n");
    TLDE_imprime(r);
    TLDE_libera(l);
    TLDE_libera(r);
    return 0;
}