/*
retirar todos os múltiplos de k:
TLSE* mult_k3(TLSE *l, int k); //l deve perder elementos
recursiva
*/
#include "alm.c"
TLSE* mult_k3(TLSE *l, int k){
    if (!l) return l;
    if (k<=1) return NULL;
    if (!(l->info%k)){
        l->info = l->prox->info;
        TLSE *p = l->prox;
        l->prox = p->prox;
        free(p);
        l = mult_k3(l,k);
    }
    else l->prox = mult_k3(l->prox,k);
    return l;
}
int main(){
    TLSE *l = NULL;
    int x;
    do{
        scanf("%d", &x);
        if (x<0) break;
        l = TLSE_insere(l, x);
    }while(1);
    printf("agora digite o k: ");
    scanf("%d",&x);
    printf("lista normal:\n");
    TLSE_imprime(l);
    printf("\n");
    l = mult_k3(l,x);
    printf("lista alterada:\n");
    TLSE_imprime(l);
    printf("\n");
    TLSE_libera(l);
    return 0;
}