/*
Retirar todos os múltiplos de k:
void mult_k3(TLDE *l, int k);
*/
#include "TLDE.c"
void mult_k3(TLDE *l, int k){
    if ((!l) || (!l->prox)) return;
    if(l->info%k==0){
        l->info=l->prox->info;
        TLDE *q = l->prox;
        l->prox=q->prox;
        if (q->prox) q->prox->ant = l;
        free(q);
        mult_k3(l,k);
    }
    else mult_k3(l->prox,k);
}
int main(){
    TLDE *l = NULL;
    int x,k;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLDE_insere(l, x);
    }while(1);
    printf("agora digite o k: ");
    scanf("%d", &k);
    printf("lista og:\n");
    TLDE_imprime(l);
    printf("\n");
    mult_k3(l,k);
    printf("lista alterada:\n");
    TLDE_imprime(l);
    printf("\n");
    TLDE_libera(l);
    return 0;
}