//Escreva, usando a linguagem C, uma função recursiva, SomaSerie(i,j,k: inteiro),
// que devolva a soma da série de valores do intervalo [i,j], com incremento k.
#include "stdio.h"
int rec(int x, int y, int k){
    if (x==y) return y;
    if (x>y) return 0;
    return rec(x+k,y,k) + x;
}
int main(){
    int x,y; printf("digite o intervalo (fechado): "); scanf("%d %d",&x,&y);
    int k; printf("qual sera o incremento: "); scanf("%d", &k);
    int z = rec(x,y,k); printf("%d",z);
    return 0;
}