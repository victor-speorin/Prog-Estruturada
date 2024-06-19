/*
Retirar todos os múltiplos de k:
TLDE* mult_k4(TLDE *l, int k);
*/
#include "TLDE.c"
TLDE* mult_k4(TLDE *l, int k){
    if ((!l)||(k<=1)) return l;
    if (l->info%k==0){
        TLDE *q = l;
        l=l->prox;
        free(q);
        mult_k4(l,k);
    }
    else l->prox= mult_k4(l->prox,k);
    return l;
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
    l=mult_k4(l,k);
    printf("lista alterada:\n");
    TLDE_imprime(l);
    printf("\n");
    TLDE_libera(l);
    return 0;
}