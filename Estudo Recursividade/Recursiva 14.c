/*
Faça uma função recursiva que receba um número inteiro positivo par N e imprima
todos os números pares de 0 até N em ordem decrescente.
 */
#include "stdio.h"
void rec(int n){
    if (n==0){
        printf("0 ");
        return;
    }
    if (n%2==0){
        printf("%d ",n);
        rec(n-1);
    }
    else rec(n-1);
}
int main(){
    int n;
    scanf("%d", &n);
    rec(n);
    return 0;
}