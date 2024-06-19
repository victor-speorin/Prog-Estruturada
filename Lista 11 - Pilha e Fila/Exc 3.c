/*(c) escreva uma função que, dadas duas filas f1 e f2, retorne uma fila, contendo todos os
elementos de f1 seguidos pelos elementos de f2, e obedecendo a ordem de entrada dos
inteiros nas filas de entrada. Além disso, as filas de entrada devem permanecer inalteradas. A
função deve obedecer ao seguinte protótipo: TFila* Junta_Filas (TFila *f1, TFila *f2);*/

#include"alm.c"

TF* Junta_Filas (TF *f1, TF *f2){
    TF *f1aux = TF_inicializa(), *f2aux = TF_inicializa(), *fresp = TF_inicializa();
    while (!TF_vazia(f1)){
        int x = TF_retira(f1);
        TF_insere(f1aux, x);
        TF_insere(fresp,x);
    }
    while (!TF_vazia(f2)){
        int x = TF_retira(f2);
        TF_insere(f2aux, x);
        TF_insere(fresp,x);
    }
    while (!TF_vazia(f1aux)) TF_insere(f1, TF_retira(f1aux));
    while (!TF_vazia(f2aux)) TF_insere(f2, TF_retira(f2aux));
    TF_libera(f1aux);
    TF_libera(f2aux);
    return fresp;
}

int main(){
    TF *f1 = TF_inicializa();
    TF *f2 = TF_inicializa();
    printf("f1:\n");
    int n;
    while(1){
        scanf("%d", &n);
        if(n < 0) break;
        TF_insere(f1, n);
    }
    printf("f2:\n");
    while(1){
        scanf("%d", &n);
        if(n < 0) break;
        TF_insere(f2, n);
    }
    printf("fila1 og:\n");
    TF_imprime(f1);
    printf("\n");
    printf("fila2 og:\n");
    TF_imprime(f2);
    printf("\n");
    TF* fresp=Junta_Filas(f1,f2);
    printf("fila resposta:\n");
    TF_imprime(fresp);
    printf("\n");
    printf("fila1 apos juntar:\n");
    TF_imprime(f1);
    printf("\n");
    printf("fila2 apos juntar:\n");
    TF_imprime(f2);
    printf("\n");
    TF_libera(f2);
    TF_libera(f1);
    TF_libera(fresp);
    return 0;
}
