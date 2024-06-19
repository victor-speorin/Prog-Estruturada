// Implemente um programa que leia “INFINITAMENTE” um número n, e retorne todos os
//divisores dele. Esse programa pára quando n < 2.

#include "stdio.h"
int main(){
    int n;
    do{
        printf("insira um numero: ");
        scanf("%d", &n);
        if (n<2) return 0;
        for (int i = 1; i<=n; i++){
            if (n%i==0) printf("%d\n", i);
        }
    }while(1);
}