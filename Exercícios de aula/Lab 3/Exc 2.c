/*
Inserir N vezes o elemento N antes de cada ocorrência de N na lista:
void ins_antes_TLDE(TLDE *l, int N);
*/
#include "TLDE.c"
void ins_antes_TLDE(TLDE *l, int n){
    TLDE *p=l;
    while (p){
        if (p->info==n){
            TLDE *q = p->prox;
            for (int i=0;i<n;i++){
                p->prox = TLDE_insere(p->prox,n);
            }
            p -> prox-> ant = p; // apenas arrumando os ponteiros por burocracia
            p=q;
        }else p=p->prox;
    }
}
int main(void){
    printf("insira a lista:\n");
    TLDE *l = NULL;
    int x,n;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLDE_insere(l, x);
    }while(1);
    printf("agora insira o n: ");
    scanf("%d",&n);
    printf("lista og:\n");
    TLDE_imprime(l);
    printf("\n");
    ins_antes_TLDE(l,n);
    printf("lista alterada:\n");
    TLDE_imprime(l);
    printf("\n");
    TLDE_libera(l);
    return 0;
}