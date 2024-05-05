#include "stdio.h"
int rec(int x){
    if (x==1) return 1;
    return rec(x-1) + x;
}
int main(void){
    int x;
    scanf("%d", &x);
    int z = rec(x);
    printf("%d", z);
    return 0;
}