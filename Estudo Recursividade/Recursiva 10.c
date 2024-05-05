/*
A multiplicação de dois números inteiros pode ser feita através de somas
sucessivas. Proponha um algoritmo recursivo Multip_Rec(n1,n2) que calcule a
multiplicação de dois inteiros
*/
#include "stdio.h"
int rec(int x, int y){
    if (y==1) return x;
    return rec(x,y-1)+x;
}
int main(){
    int x,y;
    scanf("%d %d", &x, &y);
    int z = rec(x,y);
    printf("%d", z);
    return 0;
}