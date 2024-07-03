/*
Escreva uma função em C que receba uma lista simplesmente encadeada l e
um inteiro x, e se x for par, insira x  - 1 antes de cada ocorrência de x.
Senão, se x for ímpar, insere x + 1 depois de cada ocorrência de x.
O prótotipo deste método é o seguinte: void misc(TLC* l, int x)
*/
#include "TLC.c"
void misc(TLC*l,int x){
    TLC*p=l;
    if (l->info==x){
        if (x%2==0){
            TLC *novo = (TLC*) malloc(sizeof(TLC));
            novo->info=x-1;
            novo->prox = p->prox;
            p->prox=novo;
            int tmp = p->info;
            p->info=novo->info;
            novo->info=tmp;
            p=novo->prox;
        }
        else {
            TLC *novo = (TLC*) malloc(sizeof(TLC));
            novo->info=x+1;
            novo->prox = p->prox;
            p->prox=novo;
            p=novo->prox;
        }
    }

    while (p!=l){
        if(p->info==x) {
            if (x % 2 == 0) {
                TLC *novo = (TLC *) malloc(sizeof(TLC));
                novo->info = x - 1;
                novo->prox = p->prox;
                p->prox = novo;
                int tmp = p->info;
                p->info = novo->info;
                novo->info = tmp;
                p = novo->prox;
            } else {
                TLC *novo = (TLC *) malloc(sizeof(TLC));
                novo->info = x + 1;
                novo->prox = p->prox;
                p->prox = novo;
                p = novo->prox;
            }
        }
        else p=p->prox;
    }
}
int main(){
    TLC *l = NULL;
    int x;
    do {
        scanf("%d", &x);
        if (x < 0) break;
        l = TLC_insere(l, x);
    } while (1);
    TLC_imprime(l);
    printf("\n");
    scanf("%d", &x);
    misc(l, x);
    printf("\n");
    TLC_imprime(l);
    TLC_libera(l);
    return 0;
}

