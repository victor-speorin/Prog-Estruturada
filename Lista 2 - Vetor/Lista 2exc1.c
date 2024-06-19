//Alguns números possuem uma propriedade interessante: se você recuperar seus dois
//primeiros dı́gitos e seus dois últimos dı́gitos e elevar ao quadrado a soma deles, você obterá a
//concatenação desses quatro dı́gitos. Por exemplo, o número 203125 possui essa propriedade,
//pois (20 + 25)2 = 2025. Por outro lado, o mesmo não é observado para 20326, pois (20 + 26)2
//= 2116 != 2026  . Escreva uma função que informa se um número possui essa propriedade – int
//teste(int n) – retornando UM se o número satisfaz a essa propriedade, e ZERO caso contrário.

#include "stdio.h"
int teste( int n){
    int doisultimos = n%100;
    int doisprimeiros;
    while (n/100!=0){
        n/=10;
    }
    doisprimeiros=n;
    int pn = (doisprimeiros+doisultimos)*(doisprimeiros+doisultimos);
    int condicao = (100*doisprimeiros) + doisultimos;
    if (pn == condicao) return 1;
    else return 0;
}
int main(){
    int x;
    do {
        printf("insira o numero: ");
        scanf("%d", &x);
        if (x<0) return 0;
        else if (teste(x) == 1) printf("1\n");
        else (printf("0\n"));
    }while(1);
}