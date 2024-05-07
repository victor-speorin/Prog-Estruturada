//Escreva uma função recursiva em C que exibe todos os elementos em um array de
//inteiros, separados por espaço.
#include "stdio.h"
void rec(int *vet,int n, int ini){
    if (ini == n-1){
        printf("%d " ,vet[ini]);
        return;
    }
    else {
        printf("%d " ,vet[ini]);
        rec(vet,n,ini+1);
    }
}
int main(){
    int x;
    scanf("%d",&x);
    int vet[x];
    for (int i=0; i<x;i++) scanf("%d", &vet[i]);
    rec(vet,x,0);
    return 0;
}