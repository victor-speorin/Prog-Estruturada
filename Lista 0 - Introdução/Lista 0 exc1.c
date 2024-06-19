// Q1) Escreva um programa que leia “INFINITAMENTE” dois números x e y, e retorne o MDC entre
//eles. Esse programa pára quando x, y ≤ 1.

#include "stdio.h"
int mdc(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}
int main(){
    do{
        int x,y;
        printf("Digite dois numeros para calcular o MDC:");
        scanf("%d %d", &x, &y);
        if (x<=0 || y<=1) return 0;
        printf("o mdc eh %d\n", mdc(x, y));
    }while(1);
}
