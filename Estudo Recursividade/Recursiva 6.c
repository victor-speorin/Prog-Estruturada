#include "stdio.h"
void rec(int n){
    if (n==0) return;
    else{
        rec(n/2);
        printf("%d", n%2);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    rec(n);
    return 0;
}