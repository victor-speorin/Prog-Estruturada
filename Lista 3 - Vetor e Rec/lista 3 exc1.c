//Uma forma simples e eficiente de calcular todos os números primos até um certo valor n é o
//método da Peneira de Eratosthenes. O processo é simples: escrevem-se todos os valores entre 2
// e n (limite máximo). Em seguida, faz-se um círculo em volta do 2, marcando como primo e riscam-
//se todos os seus múltiplos. Continua-se a fazer círculos em volta do menor inteiro que se
//cencontra, eliminando todos os seus múltiplos. Quando não restarem números sem terem círculos
//à volta ou traços por cima, os números com círculos à volta representam todos os primos até n. A
//figura seguinte apresenta o método para n = 40.
//Escreva um programa que implemente a Peneira de Eratosthenes. Você deve ler o valor n e
//mostrar todos os números primos encontrados.

#include "stdio.h"
int main(){
    int n;
    do{ scanf("%d", &n); }while(n<=1);
    int vet[n-1];
    int p = 0;
    for (int u=2; u<=n; u++){
        vet[p]=u;
        p++;
    }
    for (int d=0; d<n-1; d++) {
        for (int i = d+1; i < n - 1; i++) {
            if (vet[d]==-1 || vet[i]==-1) continue;
            else if (vet[i] % vet[d]  == 0) vet[i] = -1;
        }
    }
    for (int h=0; h<n-1; h++){
        if (vet[h]!=-1) printf("%d\n", vet[h]);
    }
}