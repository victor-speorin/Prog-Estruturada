/*
inserir n vezes o elem n antes e depois de cada n na lista:
void inad (TLSE *l, int n)
 RECURSIVA!
*/
#include "alm.c"

void inad (TLSE *l, int n){
    if (!l) return;
    if (l->info==n){
        TLSE *q=l->prox, *p=l;
        for (int i=0;i<(n*2);i++){
            p->prox = TLSE_insere(p->prox,n);
        }
        inad(q,n);
    }
    else inad(l->prox,n);
}
int main(){
    TLSE *l = NULL;
    int x;
    do{
        scanf("%d", &x);
        if (x<0) break;
        l = TLSE_insere(l, x);
    }while(1);
    printf("agora digite o n: ");
    scanf("%d",&x);
    printf("lista normal:\n");
    TLSE_imprime(l);
    printf("\n");
    inad(l,x);
    printf("lista invertida:\n");
    TLSE_imprime(l);
    printf("\n");
    TLSE_libera(l);
    return 0;
}
