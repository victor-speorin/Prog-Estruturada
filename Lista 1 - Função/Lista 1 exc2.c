//Q2) Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
//n e retorne os n primeiros números primos existentes depois de n. Por exemplo, se n = 2, a
//resposta será os primos 3 e 5. É necessário salientar que n não precisa ser primo. Seu programa
//para quando n for menor ou igual a zero.

#include "stdio.h"
int primo(int x){
    int divisor=1, c=0;
    while(divisor<x){
        if (x%divisor==0) c++;
        divisor++;
    }
    if (c==1) return 1;
    else return 0;
}
int main(){
    do {
        int n, x=0, p=1;
        printf("quantos primos? ");
        scanf("%d", &n);
        if (n <= 0) return 0;
        p+=n;
        while (x < n) {
            if (primo(p) == 1) {
                printf("%d\n", p);
                p++;
                x++;
            } else p++;
        }
    }while(1);
    }