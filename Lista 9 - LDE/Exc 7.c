/*
Refaça Q6, alterando a lista passada como parâmetro. O protótipo desta função é o
seguinte: void i_p (TLDE *l).
*/

#include "stdio.h"
#include "TLDE.c"
TLDE* desloca (TLDE* l){
    TLDE *p =l;
    for (;p && p->prox; p = p->prox) p->info = p->prox->info; // o atual recebe o proximo
    return l;
}
void i_p (TLDE *l){
    TLDE *p =l, *pf = l;
    int t=1;
    while (pf->prox){ // descubro o tamanho o coloco um ponteiro no final
        pf=pf->prox;
        t++;
    }
    while (t){
        if (p->info%2==0){ // quando acho um par, coloco ele no final e desloco todos pra esq
            int x = p->info;
            p = desloca(p); // desloco a partir do p somente
            pf->info = x;
            t--;
        } else { // nao acha um par só avança
            t--;
            p=p->prox;
        }
    }
}

int main(){
    TLDE *l = NULL;
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLDE_insere(l, x);
    }while(1);
    printf("lista og:\n");
    TLDE_imprime(l);
    printf("\n");
    i_p(l);
    printf("lista alterada:\n");
    TLDE_imprime(l);
    printf("\n");
    TLDE_libera(l);
    return 0;
}
