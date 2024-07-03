/*
Escreva uma função em C que receba uma lista simplesmente encadeada l e
um inteiro x, e se x for par, insira x  - 1 antes de cada ocorrência de x.
Senão, se x for ímpar, insere x + 1 depois de cada ocorrência de x.
O prótotipo deste método é o seguinte: void misc(TLDE* l, int x)
 RECURSIVA
*/
#include "TLDE.c"
void misc(TLDE* l, int x){
   if (!l) return;
   if (l->info==x){
       if (x%2){
           TLDE *p=l;
           TLDE *novo = (TLDE*)malloc(sizeof(TLDE));
           novo->info = x+1;
           if(p->prox){
               novo->prox = p->prox;
               p->prox->ant = novo;
               p->prox = novo;
               novo->ant = p;
               misc(novo->prox, x);
           }
           else {
               p->prox = novo;
               novo ->ant = p;
               novo ->prox = NULL;
               return;
           }
       }
       else {
           TLDE *p=l;
           TLDE *novo = (TLDE*) malloc(sizeof (TLDE));
           novo ->info=x-1;
           if (p->prox) {
               novo->prox = p->prox;
               p->prox->ant = novo;
               p->prox = novo;
               novo->ant = p;
               int tmp = novo->info;
               novo->info = p->info;
               p->info = tmp;
               misc(novo->prox, x);
           }
           else{
               p->prox = novo;
               novo ->ant = p;
               novo ->prox = NULL;
               int tmp = novo->info;
               novo->info=p->info;
               p->info=tmp;
               return;
           }
       }
   }
   else misc(l->prox,x);
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