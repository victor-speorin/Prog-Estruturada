/*
A multiplicação à Russa consiste em:
1) Escrever os números A e B, que se deseja multiplicar na parte superior das colunas.
2) Dividir A por 2, sucessivamente, ignorando o resto até chegar à unidade, escrever
os resultados da coluna A.
3) Multiplicar B por 2 tantas vezes quantas se haja dividido A por 2, escrever os
resultados sucessivos na coluna B.
4) Somar todos os números da coluna B que estejam ao lado de um número ímpar da
coluna A.
Exemplo: 27 × 82
A B Parcelas
27 82 82
13 164 164
6 328 -
3 656 656
1 1312 1312
Soma: 2214
Programar em C um algoritmo recursivo que permita fazer à multiplicação a russa de 2
entradas;
*/
#include "stdio.h"
int rec(int a, int b, int z){
    if (a==1) {
        z+=b;
        printf("%d\n",z);
        return z;
    }
    if (a%2!=0) {
        z += rec(a/2,b*2,z+b);
    }
    else z =  rec(a/2,b*2,z);
    return z;
}
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    rec(x,y,0);
    return 0;
}