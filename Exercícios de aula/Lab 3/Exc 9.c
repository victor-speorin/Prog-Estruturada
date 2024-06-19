/*
Retirar todos os múltiplos de k:
void mult_k1(TLSE *l, int k);
*/
#include "TLSE.c"
void mult_k1(TLSE *l, int k){
    if (!l) return;
    TLSE *p=l;
    while (p){
        if (p->info%k==0){
            if (!p->prox){
                free(p);
                return;
            }
            TLSE *t = p->prox;
            p->info=t->info;
            p->prox=t->prox;
            free(t);
        }
        else p=p->prox;
    }
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