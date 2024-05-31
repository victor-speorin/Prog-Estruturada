/*
Crie uma função em C que remova todas as ocorrências de um elemento numa lista.
Seu protótipo O protótipo desta função é o seguinte: TLSE* rto (TLSE* l, int elem).
*/
#include "stdio.h"
#include "TLSE.c"
TLSE* rto (TLSE* l, int elem){
    TLSE *p = l;
    int tam=0;
    for (; p; p = p->prox) tam++; // tamanho
    for (int i=0;i<tam;i++){
        l = TLSE_retira(l,elem);
    }
    return l;
}
int main(){
    TLSE *l = TLSE_inicializa();
    int x, n;
    do{
        scanf("%d", &x);
        if (x<0) break;
        l = TLSE_ins_ini(l, x);
    }while(1);
    printf("agora insira o elem a ser retirado: ");
    scanf("%d",&n);
    printf("lista og:\n");
    TLSE_imp_rec(l);
    printf("\n");
    l = rto(l,n);
    printf("lista resposta:\n");
    TLSE_imp_rec(l);
    printf("\n");
    TLSE_lib_rec(l);
    return 0;
}