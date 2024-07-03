/*
 Escreva uma função em C que, dadas duas listas l1 e l2 duplamente encadeadas,
 verifique se l1 e l2 possuem  um elemento N em comum. Se elas não possuem N,
 as listas permanecem inalteradas. Se elas possuem, l1 ficará com todos os
 elementos de l2 que aparecem depois de N, e l2 ficará com todos os elementos
 de l1 que aparecem após N. Esse procedimento deve ser realizado para todas as
 ocorrências do elemento N nas listas supracitadas. O protótipo desta função
 é o seguinte: void cross(TLDE *l1, TLDE *l2, int N);
*/
#include "TLSE.c"
void cross(TLSE *l1, TLSE *l2, int n){
    TLSE *p1 = l1, *p2 = l2, *tmp;
    while((p1) && (p2)){
        while ((p1) && (p1->info != n)) p1=p1->prox;
        while ((p2) && (p2->info != n)) p2=p2->prox;
        if ((p1)&&(p2)&&(p1->info==n)&&(p2->info==n)){
            tmp = p1->prox;
            p1->prox = p2->prox;
            p2->prox = tmp;
            p1=p1->prox;
            p2=p2->prox;
        }
    }
}
int main(){
    TLSE *l = NULL, *l2 = NULL;
    int x;
    printf("lista 1:\n");
    do {
        scanf("%d", &x);
        if (x < 0) break;
        l = TLSE_insere(l, x);
    } while (1);
    printf("lista 2:\n");
    do {
        scanf("%d", &x);
        if (x < 0) break;
        l2 = TLSE_insere(l2, x);
    } while (1);
    printf("agora digite o n:");
    scanf("%d",&x);
    printf("lista 1 og:\n");
    TLSE_imprime(l);
    printf("\n");
    printf("lista 2 og:\n");
    TLSE_imprime(l2);
    printf("\n");
    cross(l,l2, x);
    printf("lista 1 alterada:\n");
    TLSE_imprime(l);
    printf("\n");
    printf("lista 2 alterada:\n");
    TLSE_imprime(l2);
    TLSE_libera(l);
    TLSE_libera(l2);
    return 0;
}
