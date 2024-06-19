/*(d) escreva uma função que receba uma pilha e retire todos os elementos pares desta pilha.
A função deve obedecer o seguinte protótipo: void retira_pares (TPilha *p);*/

#include"alm.c"

void retira_pares (TP *p){
    TP *paux = TP_inicializa();
    while (!TP_vazia(p)){
        int x = TP_pop(p);
        if (x%2) TP_push(paux,x);
    }
    while (!TP_vazia(paux)) TP_push(p, TP_pop(paux));
    free(paux);
}

int main(){
    TP *p = TP_inicializa();
    printf("p:\n");
    int n;
    while(1){
        scanf("%d", &n);
        if(n < 0) break;
        TP_push(p, n);
    }
    printf("pilha og:\n");
    TP_imprime(p);
    printf("\n");
    retira_pares(p);
    printf("Pilha resposta:\n");
    TP_imprime(p);
    printf("\n");
    TP_libera(p);
    return 0;
}
