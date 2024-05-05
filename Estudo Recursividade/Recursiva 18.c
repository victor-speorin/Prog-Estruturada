// hiperfatorial
#include "stdio.h"
int exp(int base,int n){
    if (n==0) return 1;
    return base * exp(base,n-1);
}
int rec(int n){
    if (n==1) return 1;
    return rec(n-1)* exp(n,n);
}
int main(){
    int n; scanf("%d", &n);
    int x= rec(n);
    printf("%d",x);
    return 0;
}