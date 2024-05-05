/*
 Faça uma função recursiva que receba um número inteiro positivo N e imprima
 todos os números naturais de 0 até N em ordem crescente.
*/
#include "stdio.h"
void rec(int n){
    if (n==0) {
        printf("0 ");
        return;
    }
    rec(n-1);
    printf("%d ", n);
}
int main(){
    int x;
    scanf("%d", &x);
    rec(x);
    return 0;
}