/*
Crie uma função em C que remova todas as ocorrências de um elemento numa lista.
Seu protótipo O protótipo desta função é o seguinte: TLC* rto (TLC* l, int elem).
*/
#include "TLC.c"
TLC* rto (TLC* l, int elem){
    TLC *p=l, *aux = l->prox;
    while (aux!=l){
        if (aux->info==elem){
            p->prox=aux->prox;
            TLC *pop = aux;
            aux = aux ->prox;
            free(pop);
        }
        else {
            p=aux;
            aux =aux->prox;
        }
    }
    p = l;
    aux = l->prox;
    if (l->info == elem) {
        while (aux->prox != p) aux = aux->prox;
        aux->prox = p->prox;
        free(l); // Libera o primeiro elemento (l)
        return aux->prox; // Retorna o próximo elemento como novo início da lista
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
    printf("agora insira o elem: ");
    scanf("%d",&n);
    printf("lista og:\n");
    TLC_imprime(l);
    printf("\n");
    l=rto(l,n);
    printf("lista resposta:\n");
    TLC_imprime(l);
    printf("\n");
    TLC_libera(l);
    return 0;
}