/*
inserir n vezes o elem n antes e depois de cada n na lista:
void inad (TLSE *l, int n)
*/
#include "alm.c"

void inad (TLSE *l, int n){
    TLSE *p=l;
    while (p){
        if (p->info==n){
            TLSE *q = p->prox;
            for (int i=0;i<(n*2);i++){
                p->prox = TLSE_insere(p->prox,n);
            }
            p=q;
        }
        else p=p->prox;
    }
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
