// função recursiva que retorne a quantidade de vezes que um numero n aparece num numero k
#include "stdio.h"
int rec(int n, int k){
    if (k<1) return 0;
    if (k%10==n) return rec(n,k/10) + 1;
    return rec(n,(k/10));
}
int main(){
   int n, k;
    scanf("%d %d", &n, &k);
    int resp = rec(n,k);
    printf("%d", resp);
    return 0;
}