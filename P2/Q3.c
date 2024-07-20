/*
a questão pedia que fizessemos uma lista com os elementos em comum entre uma l1 e l2, ordenadas
de forma cresecente. A questão deveria ser recursiva.
*/

#include "TLSE.c"
TLSE* f2(TLSE *l1, TLSE *l2, TLSE *resp){ // alterei de void para TLSE
    if (!l1 || !l2) return resp; // aqui retorno resp por ser TLSE, antes era só "return".
    if (l1->info==l2->info){
        resp = TLSE_ins_fim(resp,l1->info);
        f2(l1->prox,l2->prox,resp);
    }
    else if (l1->info>l2->info){
        f2(l1,l2->prox,resp);
    }
    else f2(l1->prox,l2,resp);
}
TLSE *f(TLSE *l1,TLSE *l2){
    TLSE *respo = NULL;
    respo=f2(l1,l2,respo); // aqui por ser TLSE, fiz a respo receber o retorno da função.
    return respo;
}
int main(){
    TLSE *l1 = NULL, *l2= NULL;
    int x;
    printf("l1:\n");
    do{
        scanf("%d",&x);
        if (x<0) break;
        l1 = TLSE_ins_fim(l1,x);
    } while (1);
    printf("l2:\n");
    do{
        scanf("%d",&x);
        if (x<0) break;
        l2 = TLSE_ins_fim(l2,x);
    } while (1);
    printf("l1:\n");
    TLSE_imprime(l1);
    printf("\n");
    printf("l2:\n");
    TLSE_imprime(l2);
    printf("\n");
    TLSE *r= f(l1,l2);
    printf("r:\n");
    TLSE_imprime(r);
    printf("\nl1:\n");
    TLSE_imprime(l1);
    printf("\nl2:\n");
    TLSE_imprime(l2);
    TLSE_libera(l1);
    TLSE_libera(r);
    TLSE_libera(l2);
    return 0;
}