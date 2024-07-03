/*
Escreva uma função em C que receba uma lista simplesmente encadeada l e
um inteiro x, e se x for par, insira x  - 1 antes de cada ocorrência de x.
Senão, se x for ímpar, insere x + 1 depois de cada ocorrência de x.
O prótotipo deste método é o seguinte: void misc(TLSE* l, int x)
*/
#include "TLSE.c"
void misc(TLSE* l, int x){
    TLSE *p = l, *a=NULL;
    if (x%2==0){
        while (p){
            if (p->info==x){
                if (!a) p = TLSE_insere(p,x-1);
                else{
                    TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
                    novo ->info = x-1;
                    a->prox = novo;
                    novo ->prox = p;
                }
            }
            a=p;
            p=p->prox;
        }
    }
    else {
        while (p){
            if (p->info==x){
                if (!a) p->prox = TLSE_insere(p->prox,x+1);
                else{
                    TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
                    novo ->info = x+1;
                    if (p->prox) {
                        TLSE *q = p->prox;
                        p->prox = novo;
                        novo->prox = q;
                    }
                    else {
                        p->prox = novo;
                        novo->prox = NULL;
                    }
                }
            }
            a=p;
            p=p->prox;
        }
    }
}
int main(){
    TLSE *l = NULL;
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLSE_insere(l, x);
    }while(1);
    TLSE_imprime(l);
    printf("\n");
    scanf("%d", &x);
    misc(l, x);
    printf("\n");
    TLSE_imprime(l);
    TLSE_libera(l);
    return 0;

}