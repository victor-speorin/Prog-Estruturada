/*(b) uma função que, dada uma fila f, retorne uma nova fila, com todos os elementos de f,
porém invertida em relação a fila f. Não é possível alterar a ordem dos elementos da fila de
entrada. A função deve obedecer o seguinte protótipo: TFila* inv_fila (TFila *f);*/

#include"alm.c"

TF* inv_fila (TF *f){
    TF *fresp = TF_inicializa();
    TP *paux = TP_inicializa();
    while (!TF_vazia(f)) TP_push(paux, TF_retira(f));
    while (!TP_vazia(paux)) TF_insere(fresp, TP_pop(paux));
    TP_libera(paux);
    return fresp;
}

int main(){
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
    f=inv_fila(f);
    printf("fila resposta:\n");
    TF_imprime(f);
    printf("\n");
    TF_libera(f);
    return 0;
}

