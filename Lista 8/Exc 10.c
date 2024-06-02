/*
Escreva uma função em C que, dadas duas listas l1 e l2 encadeadas, verifique se l1
é a inversão de l2. As listas l1 e l2 devem permanecer inalteradas. Esta função retorna 1
se as listas estão invertidas e 0, caso contrário. O protótipo desta função é o seguinte:
int Contrario (TLSE *l1, TLSE *l2).
*/
#include "stdio.h"
#include "TLSE.c"
int Contrario (TLSE *l1, TLSE *l2){
    TLSE *p1 = l1, *p2 = l2;
    int tam1=0, tam2=0;
    for (; p1; p1 = p1->prox) tam1++;
    for (; p2; p2 = p2->prox) tam2++;
    p1=l1,p2=l2;
    if (tam1!=tam2) return 0;
    for (int i=0;i<tam1;i++){
        for (int j=0;j<tam2-1;j++){
            p2 = p2->prox;
        }
        if (p2->info!=p1->info) return 0; // vou fazendo as verificações do primeiro de l1 com ultimo de l2 e etc
        p1=p1->prox;
        p2=l2;
        tam2--;
    }
    return 1;
}

int main(){
    TLSE *l1 = TLSE_inicializa();
    TLSE *l2 = TLSE_inicializa();
    int x;
    printf("insira a primeira lista:\n ");
    do{
        scanf("%d", &x);
        if (x<0) break;
        l1 = TLSE_ins_ini(l1, x);
    }while(1);
    printf("\ninsira a segunda lista:\n");
    do{
        scanf("%d", &x);
        if (x<0) break;
        l2 = TLSE_ins_ini(l2, x);
    }while(1);
    printf("lista1:\n");
    TLSE_imp_rec(l1);
    printf("\n");
    printf("lista2:\n");
    TLSE_imp_rec(l2);
    printf("\n");
    x = Contrario(l1,l2);
    if (x) printf("contrarias\n");
    else printf("nao\n");
    TLSE_lib_rec(l1);
    TLSE_lib_rec(l2);
    return 0;
}

