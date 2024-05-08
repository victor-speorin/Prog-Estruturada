// Faça uma função recursiva que permita calcular a média um vetor de tamanho N
#include "stdio.h"
void rec_aux(int *vet, int n, int *soma){
    if(n == 0) return;
    *soma += vet[n - 1];
    rec_aux(vet, n - 1, soma);
}

int rec(int *vet,int n){
  int soma = 0;
  rec_aux(vet, n, &soma);
  return soma/n;
}
int main(){
    int n;
    scanf("%d",&n);
    int vet[n];
    for (int i=0;i<n;i++) scanf("%d",&vet[i]);
    int x = rec(vet,n);
    printf("%d",x);
    return 0;
}