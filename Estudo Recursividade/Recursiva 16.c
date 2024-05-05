/* O fatorial quádruplo de um número N é dado por (2n)!/n!
Faça uma função recursiva que receba um número inteiro positivo N e retorne o
fatorial quádruplo desse número
 */
#include "stdio.h"
int rec(int n){
    if (n==1) return 1;
    return rec(n-1) * n;
}
int mat(int n){
    int z = rec(2*n)/ rec(n);
    printf("%d",z);
}
int main(){
    int n; scanf("%d", &n);
    mat(n);
    return 0;
}