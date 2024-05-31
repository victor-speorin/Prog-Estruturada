/*
Defina uma função em C que, dada uma lista l qualquer, retorne, numa lista de saída,
os elementos ímpares e os elementos pares da lista l, na ordem em que os elementos
aparecem em l. Ao final da execução desta função, a lista resultante terá todos os
elementos da lista l (primeiro os ímpares, depois os pares, na ordem em que eles
aparecem em l), e a lista l continuará contendo os seus elementos. O protótipo da função
é o seguinte: TLSE* i_p (TLSE *l).
*/
#include "stdio.h"
#include "TLSE.c"
TLSE* i_p (TLSE *l){
    TLSE* lc = TLSE_inicializa(), *p=l; // criando a lista nova e um ponteiro para a og
    int tam = 0,y,x;
    for (; p; p = p->prox) tam++; // tamanho
    p=l; // voltando p para o inicio de l
    //colocando os impares
    for (;p;p=p->prox){
        if ((p->info) % 2 != 0){
            lc = TLSE_ins_ini(lc,p->info);
        }
    }
    p=l; // voltando p
    //colocando os pares
    for (;p;p=p->prox){
        if (p->info % 2 == 0){
            lc = TLSE_ins_ini(lc,p->info);
        }
    }
    //invertendo pois a lista sai aqui de cima trocada
    TLSE *q = lc, *pp; // dois ponteiros para lc
    x = tam;
    for (int i=0;i<tam/2;i++){
        pp=q;
        for (int j=0;j<x-1;j++){
            pp=pp->prox; //colocando pp no final
        }
        //trocando:
        y = q->info;
        q->info = pp->info;
        pp->info = y;
        q=q->prox; // colocando o q uma pra frente
        x-=2;
    }
    return lc;
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
    l = i_p(l);
    printf("lista resposta:\n");
    TLSE_imp_rec(l);
    printf("\n");
    TLSE_lib_rec(l);
    return 0;
}