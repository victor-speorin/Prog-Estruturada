/*
Inserir N vezes o elemento N antes de cada ocorrência de N na lista:
void ins_antes_TLC(TLC *l, int n)
*/
#include "TLC.c"
void ins_antes_TLC(TLC *l, int n){
    TLC *p = l;
    if (p->info==n){
        TLC *aux = p->prox;
        for (int i=0;i<n;i++) {
            TLC *novo = (TLC *) malloc(sizeof(TLC));
            novo ->info = n;
            novo->prox = aux;
            p->prox = novo;
            p = novo;
        }
        p=aux;
    }
    else p=p->prox;
    while (p!=l){
        if (p->info==n){
            TLC *aux = p->prox;
            for (int i=0;i<n;i++) {
                TLC *novo = (TLC *) malloc(sizeof(TLC));
                novo ->info = n;
                novo->prox = aux;
                p->prox = novo;
                p = novo;
            }
            p=aux;
        } else p=p->prox;
    }
}
int main(void){
    printf("insira a lista:\n");
    TLC *l = NULL;
    int x,n;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLC_insere(l, x);
    }while(1);
    printf("agora insira o n: ");
    scanf("%d",&n);
    printf("lista og:\n");
    TLC_imprime(l);
    printf("\n");
    ins_antes_TLC(l,n);
    printf("lista alterada:\n");
    TLC_imprime(l);
    printf("\n");
    TLC_libera(l);
    return 0;
}