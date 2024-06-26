/*
inserir n vezes o elemento n antes e depois de cada
n da lista duplamente encadeada: void inad2(TLDE *l, int n)
*/
#include "TLDE.c"
void inad2(TLDE *l, int n){
    TLDE *p = l;
    while (p){
        if (p->info==n){
            TLDE *q=p->prox;
            for (int i=0;i<(n*2);i++){
                p->prox = TLDE_insere(p->prox,n);
            }
            p=q;
        }
        else p=p->prox;
    }
}
int main() {
    TLDE *l = NULL;
    int x;
    do {
        scanf("%d", &x);
        if (x < 0) break;
        l = TLDE_insere(l, x);
    }while(1);
    printf("agora digite o n: ");
    scanf("%d",&x);
    printf("lista og:\n");
    TLDE_imprime(l);
    printf("\n");
    inad2(l,x);
    printf("resposta:\n");
    TLDE_imprime(l);
    TLDE_libera(l);
    return 0;
}