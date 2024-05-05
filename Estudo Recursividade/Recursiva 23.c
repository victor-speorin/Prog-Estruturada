// Numeros de Pell
#include "stdio.h"
int rec(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    return 2*(rec(n-1)) + rec(n-2);
}
int main(){
    int x;
    scanf("%d", &x);
    int z = rec(x); printf("%d",z);
    return 0;
}
