//  Retirar todos os múltiplos de k: TLSE* mult_k1(TLSE *l, int k);

#include "TLSE.c"
TLSE *mult_k1(TLSE *l, int k){
    if (!l) return l;
    if (l->info%k==0){
        TLSE *t=l;
        l=l->prox;
        free(t);
        l= mult_k1(l,k);
    } else l->prox = mult_k1(l->prox,k);
    return l;
}

int main(void){
    TLSE *l = TLSE_inicializa();
    int x,k;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLSE_ins_fim(l, x);
    }while(1);
    printf("agora digite o k: ");
    scanf("%d", &k);
    printf("lista og:\n");
    TLSE_imprime(l);
    printf("\n");
    l=mult_k1(l,k);
    printf("lista alterada:\n");
    TLSE_imprime(l);
    printf("\n");
    TLSE_lib_rec(l);
    return 0;
}