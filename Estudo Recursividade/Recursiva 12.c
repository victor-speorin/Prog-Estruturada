/*
Faça uma função recursiva que receba um número inteiro positivo N e imprima
todos os números naturais de 0 até N em ordem decrescente
*/
#include "stdio.h"
void rec(int n){
    if (n==0){
        printf("0");
        return ;
    }
    printf("%d ",n);
    rec(n-1);
}
int main(){
    int x; scanf("%d", &x); rec(x);
}