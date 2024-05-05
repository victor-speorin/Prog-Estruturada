//fatorial exponencial
#include "stdio.h"
int exp(int base,int n){
    if (n==0) return 1;
    return base * exp(base,n-1);
}
int rec(int n){
    if (n==1) return 1;
    return exp(n, exp(n - 1, n - 2));
}
int main(){
    int n; scanf("%d", &n);
    printf("%d", rec(n));
    return 0;
}