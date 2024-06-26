/*
retirar todos os múltiplos de k:
TP* mult_k1(TP *p, int k); //p deve manter os mesmos elementos originais
*/
#include "alm.c"
TP* mult_k1(TP *p, int k){
    TP *prespaux = TP_inicializa(), *paux = TP_inicializa(), *presp = TP_inicializa();
    while (!TP_vazia(p)){
        int x = TP_pop(p);
        if (x%k) TP_push(prespaux,x);
        TP_push(paux,x);
    }
    while (!TP_vazia(paux)){
        TP_push(p, TP_pop(paux));
    }
    while (!TP_vazia(prespaux)){
        TP_push(presp, TP_pop(prespaux));
    }
    free(prespaux);
    free(paux);
    return presp;
}
int main(){
    TP *p = TP_inicializa();
    printf("p:\n");
    int n;
    while (1) {
        scanf("%d", &n);
        if (n < 0) break;
        TP_push(p, n);
    }
    printf("digite o n: ");
    scanf("%d",&n);
    printf("pilha og:\n");
    TP_imprime(p);
    printf("\n");
    TP *presp = mult_k1(p,n);
    printf("pilha resposta:\n");
    TP_imprime(presp);
    printf("\n");
    printf("pilha og apos alteracao:\n");
    TP_imprime(p);
    TP_libera(p);
    TP_libera(presp);
    return 0;
}