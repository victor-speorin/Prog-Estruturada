// MDC de dois numeros
#include "stdio.h"
int rec(int x, int y){
    if (x==y) return x;
    if (x<y) return rec(y,x);
    return rec(x-y,y);
}
int main(){
    int x,y;
    scanf("%d %d", &x, &y);
    int z= rec(x,y);
    printf("%d", z);
    return 0;
}