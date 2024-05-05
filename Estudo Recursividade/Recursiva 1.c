#include "stdio.h"
int rec(int base,int n){
    if (n==0) return 1;
    return base * rec(base,n-1);
}
int main(){
    int base,n;
    scanf("%d %d", &base, &n);
    int resul = rec(base,n);
    printf("%d", resul);
    return 0;
}