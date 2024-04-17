//Retirar todos os múltiplos de k de um vetor de inteiros. Se o seu
// vetor é composto por {2, 3, 5, 4, 6, 8, 7, 9, 1}, com tamanho 9,
// e k = 2, seu vetor deve se transformar em {3, 5, 7, 9, 1}, com tamanho
// igual a 5.  O protótipo dessa função é o que segue: void
// retira_mult_k(int *vet, int *novo_tam_vet, int k).
// NÃO PODEMOS CRIAR VETORES AUXILIARES PRA RESOLVER ESSA QUESTÃO: USE SOMENTE ÍNDICES!!!

#include <stdio.h>
void retira_mult_k(int *vet, int *novo_tam_vet, int k){
    for (int i=0;i<*novo_tam_vet;i++){
        if (vet[i]%k==0 ) {
            for (int p=i+1; p<*novo_tam_vet; p++){
                vet[p-1] = vet[p];
            }
            (*novo_tam_vet)--;
            i--;
        }
    }
}
int main(void){
    int n;
    do{
        scanf("%d", &n);
        if(n > 0)break;
    }while(1);
    int vet[n], i, k;
    for(i = 0; i < n; i++)scanf("%d", &vet[i]);
    scanf("%d", &k);
    retira_mult_k(vet, &n, k);
    for(i = 0; i < n; i++) printf("%d\n", vet[i]);
    return 0;
}
