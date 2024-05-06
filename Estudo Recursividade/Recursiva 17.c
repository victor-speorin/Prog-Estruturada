/*
O superfatorial de um número N é definida pelo produto dos N primeiros fatoriais
de N. Assim, o superfatorial de 4 é
sf(4) = 1! * 2! * 3! * 4! = 288
Faça uma função recursiva que receba um número inteiro positivo N e retorne o
superfatorial desse número
*/
#include "stdio.h"
int fat(int n){
    if (n==1) return 1;
    return fat(n-1) * n;
}
int rec(int n){
    if (n==1) return 1;
    int x = fat(n) * rec(n-1);
    return x;
}
int sup(int n){
    printf("%d", rec(n));
}
int main(){
    int n; scanf("%d", &n);
    sup(n);
}