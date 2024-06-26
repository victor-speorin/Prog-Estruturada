/*
inserir n vezes o elemento n antes e depois de cada n da
lista duplamente encadeada: void inad2(TLDE *l, int n)
 RECURSIVA!
*/
#include "TLDE.c"
void inad2(TLDE *l, int n){
    if (!l) return;
    if (l->info==n){
        TLDE *q=l->prox;
        for (int i=0;i<(n*2);i++){
            l->prox = TLDE_insere(l->prox,n);
        }
        inad2(q,n);
    }
    else inad2(l->prox,n);
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