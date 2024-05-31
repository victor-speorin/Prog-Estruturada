/*
Refaça Q6, alterando a lista passada como parâmetro. O protótipo desta função é o
seguinte: void i_p (TLSE *l).
*/
#include "stdio.h"
#include "TLSE.c"
void i_p (TLSE *l){

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
    TLSE_imp_rec(l);
    TLSE_lib_rec(l);
    return 0;
}