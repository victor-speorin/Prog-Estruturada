//Escreva, usando a linguagem C, uma função recursiva, ImprimeSerie(i,j,k: inteiro),
//que imprime na tela a série de valores do intervalo [i,j], com incremento k.
#include "stdio.h"
void rec(int i, int j, int k){
    if (i>j) return;
    printf("%d ",i);
    rec(i+k,j,k);
}
int main(){
    int i,j,k;
    printf("digite o intervalo: ");
    scanf("%d %d", &i, &j);
    printf("incremento: ");
    scanf("%d",&k);
    rec(i,j,k);
    return 0;
}