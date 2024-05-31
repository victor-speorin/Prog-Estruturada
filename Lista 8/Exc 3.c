/*
Escreva uma função em C que, dada uma lista l qualquer, desloque uma vez os
elementos de l, de acordo com n. Se n é ímpar, o elemento que está na última posição
passa a ser o primeiro quando a lista é deslocada. Senão, o elemento que está na
primeira posição passa a ser o último. O protótipo desta função é o seguinte: TLSE*
desloca (TLSE* l, int n).
*/
#include "stdio.h"
#include "TLSE.c"
TLSE* desloca (TLSE* l, int n){
    TLSE *p =l;
    if (n%2==0){
        int pri = p->info; // salvando o primeiro
        for (;p && p->prox; p = p->prox){
            p->info = p->prox->info; // o atual recebe o proximo
        }
        p->info = pri; // colocando o primeiro no final (depois das interações p esta no final da lista)
    }
    else{
        int tam = 0, x;
        for (;p && p->prox; p = p->prox) tam++; // tamanho
        int u = p->info; // salvando o ultimo elem
        p=l, x=tam; // voltando p para o inicio de l
        for (int i=0;i<tam;i++){
            for (int j=0;j<x-1;j++){
                p=p->prox; // colocando p primeiro no penultimo, depois antpenul e etc...
            }
            p->prox->info = p->info; // o proximo recebe o atual
            x--; // diminuindo x para o p ir até x--, no caso o antepenultimo e etc..
            p=l; // voltando p para o inicio a cada interação
        }
        p=l;
        p->info = u; // colocando o ultimo na primeira pos
    }
    return l;
}
int main(){
    TLSE *l = TLSE_inicializa();
    TLSE *resp = TLSE_inicializa();
    int x,n;
    printf("insira o n:");
    scanf("%d",&n);
    printf("agora a lista:\n ");
    do{
        scanf("%d", &x);
        if (x<0) break;
        l = TLSE_ins_ini(l, x);
    }while(1);
    printf("lista normal:\n");
    TLSE_imp_rec(l);
    printf("\n");
    resp = desloca(l,n);
    printf("lista deslocada:\n");
    TLSE_imp_rec(resp);
    printf("\n");
    TLSE_lib_rec(resp);
    TLSE_lib_rec(l);
    return 0;
}