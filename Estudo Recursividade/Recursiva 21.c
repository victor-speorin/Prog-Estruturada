//Os números tetranacci iniciam com quatro termos pré-determinados e a partir daí
//todos os demais números são obtidos pela soma dos quatro números anteriores. Os
//primeiros números tetranacci são: 0, 0, 0, 1, 1, 2, 4, 8, 15, 29, 56, 108, 208...
//Faça uma função recursiva que receba um número N e retorne o N-ésimo termo da
//sequência de tetranacci.
#include "stdio.h"
int rec(int n){
    if (n==0) return 0; if (n==1) return 0; if (n==2) return 0; if (n==3) return 1;
    return rec(n-1) + rec(n-2) + rec(n-3) + rec(n-4);
}
int main(){
    int x; scanf("%d", &x);
    int z = rec(x);
    printf("%d",z);
    return 0;
}