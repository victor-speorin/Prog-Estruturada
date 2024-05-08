/*
Escreva uma função recursiva que calcule a soma dos primeiros n cubos:
S(n) = 1^3 + 2^3 + ... + n^3
*/
#include "stdio.h"
int rec(int n){
    if (n==1) return 1;
    return rec(n-1) + (n*n*n);
}
int main(){
    int n; scanf("%d", &n);
    int x = rec(n); printf("%d",x);
    return 0;
}