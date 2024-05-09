/*
A questão era simples, e pedia para que fizessemos uma função(portanto uma main)
que recebesse um valor n, e então uma sequência de n valores, para que retornassemos
o "tamanho"da maior sequência de números crescente. Contudo não poderiamos utilizar
vetores nem nada além dos tipos primitivos(int,char,float,double) e seus operadores.
*/
#include "stdio.h"
int main() {
    int n, maior1 = 1, maior2 = 1, atual, ant;
    printf("digite o tamanho da sequencia: ");
    scanf("%d", &n);
    scanf("%d", &ant);
    for (int i = 0; i < n-1; i++) {
        scanf("%d", &atual);
        if (atual <= ant) maior1 = 0;
        maior1++;
        ant = atual;
        if (maior1 >= maior2) maior2 = maior1;
    }
    printf("a maior sequencia eh: %d", maior2);
    return 0;
}
