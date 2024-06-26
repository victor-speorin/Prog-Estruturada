/*
retirar todos os múltiplos de k:
TLSE* mult_k3(TLSE *l, int k); //l deve perder elementos
*/
#include "alm.c"
TLSE* mult_k3(TLSE *l, int k){
    TLSE *p = l;
    while (p) {
        if (!(p->info % k)) {
            if (p->prox) {
                p->info = p->prox->info;
                TLSE *q = p->prox;
                p->prox = q->prox;
                free(q);
            }else{
                TLSE *q=p;
                free(q);
            }
        }else p=p->prox;
    }
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