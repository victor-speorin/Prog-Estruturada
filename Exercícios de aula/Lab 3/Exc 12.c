/*
Retirar todos os múltiplos de k:
TLC* mult_k5(TLC *l, int k);
*/
#include "TLC.c"

void rec(TLC *l, int k, TLC *p){
    if (l==p) return;
    if (l->info%k==0){
        l->info=l->prox->info;
        TLC *x = l->prox;
        l->prox = x->prox;
        free(x);
        rec(l,k,p);
    } else rec(l->prox,k,p);
}


void mult_k5(TLC *l, int k){
    TLC *q = l;
    if(l->info%k==0){
        while (q->info%k==0){
            q=q->prox;
        }
        int tmp = q->info;
        q->info=l->info;
        l->info=tmp;
    }
    q=l;
    rec(l->prox,k,q);
}

int main(){
    TLC *l = NULL;
    int x,k;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLC_insere(l,x);
    }while(1);
    printf("agora digite o k: ");
    scanf("%d", &k);
    printf("lista og:\n");
    TLC_imprime(l);
    printf("\n");
    mult_k5(l,k);
    printf("lista alterada:\n");
    TLC_imprime(l);
    printf("\n");
    TLC_libera(l);
    return 0;
}