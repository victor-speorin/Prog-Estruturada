/*Gerador da sequencia:
(a) F(1)=1
(b) F(2)=2
(c) F(n)= 2*F(n-1)+3*F(n-2) <=fórmula Geral
*/
#include "stdio.h"
int rec(int n){
    if (n==1) return 1;
    if (n==2) return 2;
    return ((2*(rec(n-1))) + (3*(rec(n-2))));
}
int main(){
    int x;
    scanf("%d",&x);
    int z= rec(x);
    printf("%d",z);
    return 0;
}