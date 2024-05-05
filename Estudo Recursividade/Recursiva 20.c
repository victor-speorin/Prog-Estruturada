//Faça uma função recursiva que receba um número N e retorne o N-ésimo termo da
//sequência de tribonacci
#include "stdio.h"
int rec(int n){
    if (n==0) return 0;
    if (n==1) return 0;
    if (n==2) return 1;
    return rec(n-2) + rec(n-1) + rec(n-3);
}
int main(){
    int x; scanf("%d",&x);
    int y = rec(x);
    printf("%d", y);
    return 0;
}