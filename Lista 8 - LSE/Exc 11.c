/*
Defina uma função em C que, dada uma lista l qualquer, ordene os elementos de l
em uma outra lista de saída. Portanto, a lista de entrada não pode ser alterada. O
protótipo da função desta função é o seguinte: TLSE * ordena (TLSE* l)
*/
#include "stdio.h"
#include "TLSE.c"
TLSE* copia(TLSE *l){
    TLSE* lc = TLSE_inicializa(), *p=l;
    int tam = 0, x;
    for (; p; p = p->prox) tam++;
    p=l, x=tam;
    for (int i=0;i<tam;i++){
        for (int j=0;j<x-1;j++){
            p=p->prox;
        }
        lc = TLSE_ins_ini(lc,p->info);
        x--;
        p=l;
    }
    return lc;
}
TLSE * ordena (TLSE* l){
    TLSE *lc = copia(l), *p =lc, *lr = TLSE_inicializa();
    int tam = 0;
    for (; p; p = p->prox) tam++;
    for(int i=0;i<tam;i++) {
        p=lc;
        int maior = p->info;
        while (p) {
            if (p->info > maior) maior = p->info;
            p = p->prox;
        }
        lr = TLSE_ins_ini(lr,maior);
        lc = TLSE_retira(lc,maior);
    }
    return lr;
}
int main(){
    TLSE *l = TLSE_inicializa(), *lr;
    int x;
    do{
        scanf("%d", &x);
        if (x<0) break;
        l = TLSE_ins_ini(l, x);
    }while(1);
    printf("lista og:\n");
    TLSE_imp_rec(l);
    printf("\n");
    lr = ordena(l);
    printf("lista resposta:\n");
    TLSE_imp_rec(lr);
    printf("\n");
    printf("lista og apos a alteracao:\n");
    TLSE_imp_rec(l);
    printf("\n");
    TLSE_lib_rec(l);
    TLSE_lib_rec(lr);
    return 0;
}