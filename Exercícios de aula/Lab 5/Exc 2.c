/*
Escreva uma função em C que receba uma lista simplesmente encadeada l e
um inteiro x, e se x for par, insira x  - 1 antes de cada ocorrência de x.
Senão, se x for ímpar, insere x + 1 depois de cada ocorrência de x.
O prótotipo deste método é o seguinte: void misc(TLSE* l, int x)
RECURSIVA
*/
#include "TLSE.c"
void misc(TLSE* l, int x){
   if (!l) return;
   if (l->info==x){
       if (x%2==0){
           TLSE *p = l;
           TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
           novo->info = x-1;
           novo ->prox = p->prox;
           p->prox = novo;
           int tmp = novo->info;
           novo->info = p->info;
           p->info = tmp;
           misc(novo->prox,x);
       }
       else{
           TLSE *p=l;
           TLSE *novo = (TLSE*) malloc(sizeof(TLSE));
           novo->info=x+1;
           novo ->prox = p->prox;
           p->prox = novo;
           misc(novo->prox,x);
       }
   }
   else misc(l->prox,x);
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