/*(a) uma função que, dada uma fila f, retorne uma pilha, contendo todos os elementos de f, e
obedecendo a ordem de entrada dos inteiros na fila f, isto é, o primeiro inteiro que sair da fila f
deve ser o primeiro inteiro a sair da pilha. Não é possível alterar a ordem dos elementos da fila
de entrada. A função deve obedecer o seguinte protótipo: TPilha* f2p (TFila *f);*/

#include <limits.h>
#include "alm.c"

TP* f2p (TF *f){
    TP *paux = TP_inicializa(), *presp = TP_inicializa();
    while (!TF_vazia(f)){
        TP_push(paux, TF_retira(f));
    }
    while (!TP_vazia(paux)){
        TP_push(presp, TP_pop(paux));
    }
    TP_libera(paux);
    return presp;
}

int main(){
    TP *p = TP_inicializa();
    TF *f = TF_inicializa();
    printf("f:\n");
    int n;
    while(1){
        scanf("%d", &n);
        if(n < 0) break;
        TF_insere(f, n);
    }
    printf("fila og:\n");
    TF_imprime(f);
    printf("\n");
    p=f2p(f);
    printf("Pilha resposta:\n");
    TP_imprime(p);
    printf("\n");
    TP_libera(p);
    TF_libera(f);
    return 0;
}
