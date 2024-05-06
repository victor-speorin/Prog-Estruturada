/*
Implemente, usando a linguagem C, a função h definida recursivamente por:
h(m,n){m+1, n=1;
      {n+1, m=1;
      {h(m,n-1)+h(m-1,n), m>1, n>1;
*/
#include "stdio.h"
int rec(int x, int y){
    if (y==1) return x+1;
    if (x==1) return y+1;
    return rec(x,y-1) + rec(x-1,y);
}
int main(){
    int x,y;
    scanf("%d %d", &x, &y);
    int z = rec(x,y);
    printf("%d",z);
    return 0;
}