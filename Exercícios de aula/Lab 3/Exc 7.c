/*
dados dois números N1 e N2, a cada par de N1 e N2 (ou N2 e N1),
troque-os de lugar: void troca (TLSE *l, int N1, int N2). (RECURSIVA!!)
*/
#include "TLSE.c"
void troca1 (TLSE *l,int n1, int n2){
    if (!l) return;
    if (l->info==n1){
        TLSE *aux = l->prox, *p = l;
        while (aux->info!=n2){
            aux = aux->prox;
            if (!aux) return;
        }
        int tmp = l->info;
        p->info = aux->info * (-1);
        aux->info = tmp * (-1);
        troca1(p->prox,n1,n2);
    }
    else if (l->info==n2){
        TLSE *aux = l->prox, *p = l;
        while (aux->info!=n1){
            aux = aux->prox;
            if (!aux) return;
        }
        int tmp = l->info;
        p->info = aux->info * (-1);
        aux->info = tmp * (-1);
        troca1(p->prox,n1,n2);
    }
    else troca1(l->prox,n1,n2);
}
void troca (TLSE *l, int n1, int n2) {
    troca1(l,n1,n2);
    TLSE *p=l;
    while (p){
        if (p->info < 0) p->info *= -1; 
        p=p->prox;
    }
}
int main(void){
    TLSE *l = TLSE_inicializa();
    int x,n1,n2;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLSE_ins_fim(l, x);
    }while(1);
    printf("agora digite o N1 e N2: ");
    scanf("%d %d", &n1, &n2 );
    printf("lista og:\n");
    TLSE_imprime(l);
    printf("\n");
    troca(l,n1,n2);
    printf("lista alterada:\n");
    TLSE_imprime(l);
    printf("\n");
    TLSE_lib_rec(l);
    return 0;
}