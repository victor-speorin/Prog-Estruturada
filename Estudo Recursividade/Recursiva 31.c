//Faça uma função recursiva em C para computar a função de Ackerman.
#include "stdio.h"
int rec(int x, int y){
    if (x==0) return y+1;
    if ((x>0) && (y==0)) return rec(x-1,1);
    return rec(x-1, rec(x,y-1));
}
int main(){
    int x, y;
    scanf("%d %d",&x,&y);
    int z = rec(x,y);
    printf("%d", z);
    return 0;
}