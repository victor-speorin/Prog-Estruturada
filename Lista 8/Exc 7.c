/*
Refaça Q6, alterando a lista passada como parâmetro. O protótipo desta função é o
seguinte: void i_p (TLSE *l).
*/
#include "stdio.h"
#include "TLSE.c"
TLSE* desloca (TLSE* l){
    TLSE *p =l;
    for (; p->prox; p = p->prox) p->info = p->prox->info; // o atual recebe o proximo
    return l;
}
void i_p (TLSE *l){
    TLSE *p =l, *pf = l;
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
    TLSE *l = TLSE_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if (x<0) break;
        l = TLSE_ins_ini(l, x);
    }while(1);
    printf("lista og:\n");
    TLSE_imp_rec(l);
    printf("\n");
    i_p(l);
    printf("lista resposta:\n");
    printf("\n");
    TLSE_imp_rec(l);
    printf("\n");
    TLSE_lib_rec(l);
    return 0;
}
