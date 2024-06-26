#include "alm.c"
/*

*/

void misc(TLSE* l, int x){
    if (!l) return;
    if (l->info==x){
        TLSE *p=l->prox;
        for (int i =x-1;i>=1;i--){
            l->prox= TLSE_insere(l->prox,i);
        }
        for (int i=x;i>=2;i--){
            l->prox= TLSE_insere(l->prox,i);
        }
        l->info = 1;
        misc(p,x);
    }
    else misc(l->prox,x);
}

int main(){
    TLSE *l = NULL;
    int n;
    do{
        scanf("%d", &n);
        if(n < 0) break;
        l = TLSE_insere(l, n);
    }while(1);

    scanf("%d", &n);
    misc(l, n);
    TLSE_imprime(l);
    printf("\n");

    TLSE_libera(l);
    return 0;
}