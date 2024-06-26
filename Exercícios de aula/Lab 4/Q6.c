/*
retirar todos os múltiplos de k:
TF* mult_k2(TF *f, int k); //f deve manter os mesmos elementos originais
*/
#include "alm.c"
TF* mult_k2(TF *f, int k){
    TF *fresp = TF_inicializa(), *aux = TF_inicializa();
    while (!TF_vazia(f)){
        int x = TF_retira(f);
        if (x%k) TF_insere(fresp,x);
        TF_insere(aux,x);
    }
    while (!TF_vazia(aux)){
        TF_insere(f, TF_retira(aux));
    }
    TF_libera(aux);
    return fresp;
}
int main(){
    TF *f = TF_inicializa();
    int x;
    do{
        scanf("%d",&x);
        if (x<0) break;
        TF_insere(f,x);
    } while (1);
    printf("agora digite o k: ");
    scanf("%d",&x);
    printf("fila og:\n");
    TF_imprime(f);
    TF *fresp = mult_k2(f,x);
    printf("\n lista alterada:\n");
    TF_imprime(fresp);
    printf("\n lista og apos:\n");
    TF_imprime(f);
    TF_libera(f);
    TF_libera(fresp);
}