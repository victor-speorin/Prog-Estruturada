/*
Defina uma função em C que, dada uma lista l qualquer, ordene os elementos de l
em uma outra lista de saída. Portanto, a lista de entrada não pode ser alterada. O
protótipo da função desta função é o seguinte: TLC * ordena (TLC* l).
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

TLC * ordena (TLC* l){
    TLC *resp = NULL, *aux = copia(l), *paux = aux, *pult=aux;
    int maior, t=1;
    while (paux->prox!=aux){
        t++;
        paux=paux->prox;
    }
    paux=aux;
    while (t){
        maior = paux->info;
        while (pult->prox!=aux) pult=pult->prox;
        while(paux->prox!=aux){
            if (paux->info < maior) maior = paux->info;
            paux=paux->prox;
        }
        if (pult->info<maior) maior = pult->info;
        resp = TLC_insere(resp,maior);
        aux = TLC_retira(aux,maior);
        t--;
        paux=aux;
        pult = aux;
    }
    free(aux);
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
    TLC *lresp = ordena(l);
    printf("lista ordenada:\n");
    TLC_imprime(lresp);
    printf("\n");
    printf("lista og:\n");
    TLC_imprime(l);
    printf("\n");
    TLC_libera(l);
    TLC_libera(lresp);
    return 0;
}