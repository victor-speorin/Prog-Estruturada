//[Problema 1533 do URI Online Judge] John Watson, mesmo após anos trabalhando ao lado
//de Sherlock Holmes, nunca conseguiu entender como ele consegue descobrir quem é o assassino
//com tanta facilidade. Em uma certa noite, porém, Sherlock bebeu mais do que devia e acabou
//contando o segredo a John. “Elementar, meu caro Watson”, disse Sherlock Holmes. “Nunca é o
//mais suspeito, mas sim o segundo mais suspeito”. Após descobrir o segredo, John decidiu
//resolver um crime por conta própria, só para testar se aquilo fazia sentido ou se era apenas
//conversa de bêbado. Dada uma lista com N inteiros, representando o quanto cada pessoa é
//suspeita, ajude John Watson a decidir quem é o assassino, de acordo com o método citado.
//Haverá diversos casos de teste. Cada caso de teste inicia com um inteiro N (2 ≤ N ≤ 1000),
//representando o número de suspeitos. Em seguida haverá N inteiros distintos, onde o i-ésimo
//inteiro, para todo 1 ≤ i ≤ N, representa o quão suspeita a i-ésima pessoa é, de acordo com a
//classificação dada por John Watson. Seja V o valor do i-ésimo inteiro, 1 ≤ V ≤ 10000. O último
//caso de teste é indicado quando N = 0, o qual não deverá ser processado. Para cada caso de
//teste imprima uma linha, contendo um inteiro, representando o indice do assassino, de acordo
//com o método citado.

#include <stdio.h>
void vet_leit(int *vet, int n){
    for(int i = 0; i < n; i++) scanf("%d", &vet[i]);
}
void copia_vet(int *copia ,int *vet, int n){
    for(int i = 0; i < n; i++) copia[i] = vet[i];
}
void vet_bs(int *vet, int n){
    int i, j;
    for(j = n - 1; j > 0; j--)
        for(i = 0; i < j; i++)
            if(vet[i] > vet[i + 1]){
                int tmp = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = tmp;
            }
}
int main(){
    int n, vet[n], copia[n];
    do{
        scanf("%d", &n);
        vet_leit(vet, n);
        copia_vet(copia,vet,n);
        vet_bs(copia,n);
        for (int i=0; i<n; i++){
            if (copia[n-2] == vet[i]) printf("%d\n", i+1);
        }
    }while(n != 0);
    return 0;
}