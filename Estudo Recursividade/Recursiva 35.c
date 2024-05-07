/*
Crie um programa em C, que contenha uma função recursiva para encontrar o
menor elemento em um vetor. A leitura dos elementos do vetor e impressão do menor
elemento devem ser feitas no programa principal.
*/
#include "stdio.h"
int rec(int *vet,int n,int ini, int menor){
    if (ini>=n-1) {
        return menor;
    }
    if (vet[menor] < vet[ini+1]) return rec(vet,n,ini+1,menor);
    return rec(vet,n,ini+1,ini+1);
}
int main(){
    int n;
    scanf("%d", &n);
    int vet[n];
    for (int i=0;i<n;i++) scanf("%d", &vet[i]);
    int c = rec(vet,n,0, 0);
    printf("%d",c);
    return 0;
}