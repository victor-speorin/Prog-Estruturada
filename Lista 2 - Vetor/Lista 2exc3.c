//Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
//n e retorne a representação binária de n. Por exemplo, se n é igual a 12, a resposta deste
//programa deve ser “1100”. Seu programa para quando n for menor que zero.

#include "stdio.h"
void binario(int n){
    if(n<2) printf("%d", n);
    else{
        binario(n/2);
        printf("%d", n%2);
    }
}
int main(){
    int x;
    do{
    printf("insira o numero a ser convertido: ");
    scanf("%d", &x);
    if (x<0) return 0;
    else {binario(x);
        printf("\n");}
        } while (1);
}