#include "stdio.h"
int rec(int x){
    if (x==0) return 0;
    if (x==1) return 1;
    return rec(x-1) + rec(x-2);
}
int main(){
    int x,y;
    scanf("%d", &x);
    int z = rec(x);
    printf("%d", z);
    return 0;
}