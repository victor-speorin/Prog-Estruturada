//Um número a é dito permutação de um número b se os dígitos de a formam uma permutação
//dos dígitos de b. Exemplo: 5412434 é uma permutação de 4321445, mas não é uma permutação
//de 4312455. Faça um programa que receba a e b e responda se a é permutação de b. Obs.:
//Considere que o dígito 0 (zero) não deve aparecer nos números.

#include <stdio.h>
#include "stdlib.h"
int comparar(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}
int main() {
    int n;
    printf("quer comparar numeros de qnts digitos: ");
    scanf("%d", &n);
    char n1[n], n2[n];
    scanf("%s", n1);
    scanf("%s", n2);
    qsort(n1,n, sizeof(char), comparar);
    qsort(n2, n, sizeof(char), comparar);
    int cu=0;
    for (int i=0;i<n;i++) if(n1[i]==n2[i]) cu++;
    if (cu==n) printf("permutacao");
    else printf("nao");
    return 0;
}