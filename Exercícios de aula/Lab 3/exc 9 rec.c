/*
Retirar todos os múltiplos de k:
void mult_k1(TLSE *l, int k);
*/
#include "TLSE.c"
void mult_k1(TLSE *l, int k){
    if ((!l)||(!l->prox)) return;
    if (l->info%k==0){
        l->info=l->prox->info;
        TLSE *t = l->prox;
        l->prox=t->prox;
        free(t);
        mult_k1(l,k);
    }
    else mult_k1(l->prox,k);
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
    mult_k1(l,k);
    printf("lista alterada:\n");
    TLSE_imprime(l);
    printf("\n");
    TLSE_lib_rec(l);
    return 0;
}