//  Retirar todos os múltiplos de k: TLSE* mult_k1(TLSE *l, int k);
#include "TLSE.c"
TLSE * mult_k1(TLSE *l, int k){
    TLSE *p = l, *laux = NULL;
    while (p) {
        if(p->info%k) laux = TLSE_ins_fim(laux,p->info);
        p=p->prox;
    }
    return laux;
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