/*
Inserir N vezes o elemento N antes de cada ocorrência de N na lista:
void ins_antes_TLSE(TLSE *l, int N)
*/
#include "TLSE.c"

void ins_antes_TLSE(TLSE *l, int n){
    TLSE *p = l, *q = NULL;
    while (p){
        if (p->info==n){
            q = p->prox;
            for (int i=0;i<n;i++) {
                p->prox= TLSE_ins_ini(p->prox,n);
            }
            p = q;
        } else p=p->prox;
    }
}

int main(void){
    printf("insira a lista:\n");
    TLSE *l = TLSE_inicializa();
    int x,n;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLSE_ins_ini(l, x);
    }while(1);
    printf("agora insira o n: ");
    scanf("%d",&n);
    printf("lista og:\n");
    TLSE_imprime(l);
    printf("\n");
    ins_antes_TLSE(l,n);
    printf("lista alterada:\n");
    TLSE_imprime(l);
    printf("\n");
    TLSE_lib_rec(l);
    return 0;
}