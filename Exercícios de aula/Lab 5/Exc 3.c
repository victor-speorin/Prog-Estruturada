/*
Escreva uma função em C que receba uma lista simplesmente encadeada l e
um inteiro x, e se x for par, insira x  - 1 antes de cada ocorrência de x.
Senão, se x for ímpar, insere x + 1 depois de cada ocorrência de x.
O prótotipo deste método é o seguinte: void misc(TLDE* l, int x)
*/
#include "TLDE.c"
void misc(TLDE* l, int x){
    TLDE *p = l;
    if (x%2==0){
        while (p){
            if (p->info==x){
                if (!p->ant) p = TLDE_insere(p,x-1);
                else{
                    TLDE *novo = (TLDE*) malloc(sizeof(TLDE));
                    novo ->info = x-1;
                    p->ant->prox = novo;
                    novo ->ant = p->ant;
                    novo ->prox = p;
                    p->ant = novo;

                }
            }
            p=p->prox;
        }
    }
    else {
        while (p){
            if (p->info==x){
                if (!p->ant) p->prox = TLDE_insere(p->prox,x+1);
                else{
                    TLDE *novo = (TLDE*) malloc(sizeof(TLDE));
                    novo ->info = x+1;
                    if (p->prox) {
                        TLDE *q = p->prox;
                        p->prox = novo;
                        novo ->ant = p;
                        novo->prox = q;
                        q->ant = novo;
                    }
                    else {
                        p->prox = novo;
                        novo->prox = NULL;
                    }
                }
            }
            p=p->prox;
        }
    }
}

int main() {
    TLDE *l = NULL;
    int x;
    do {
        scanf("%d", &x);
        if (x < 0) break;
        l = TLDE_insere(l, x);
    } while (1);
    TLDE_imprime(l);
    printf("\n");
    scanf("%d", &x);
    misc(l, x);
    printf("\n");
    TLDE_imprime(l);
    TLDE_libera(l);
    return 0;

}