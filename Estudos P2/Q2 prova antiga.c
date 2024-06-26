#include "alm.c"

void ret_nao_mult_N(TLSE *l, int n){
    if ((!l)||(n<=1)) return;
    if (l->info%n){
        l->info=l->prox->info;
        TLSE *t = l->prox;
        l->prox=t->prox;
        free(t);
        ret_nao_mult_N(l,n);
    }
    else ret_nao_mult_N(l->prox,n);
}

int main(void){
    TLSE *l = NULL;
    int n;
    do{
        scanf("%d", &n);
        if(n < 0) break;
        l = TLSE_insere(l, n);
    }while(1);

    scanf("%d", &n);
    ret_nao_mult_N(l, n);
    TLSE_imprime(l);
    printf("\n");
    TLSE_libera(l);
    return 0;
}