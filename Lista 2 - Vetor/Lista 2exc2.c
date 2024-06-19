//Implemente um programa que, infinitamente, teste se um número é um palíndromo (Dica: se
//uma palavra pode ser lida, indiferentemente, da esquerda para a direita e vice-versa, ela é
//considerada um palíndromo). Você deve passar o número a ser testado. O seu programa deverá
//imprimir as seguintes mensagens “VERDADEIRO” (caso o número seja um palíndromo) ou
//“FALSO” (caso o número não seja um palíndromo) na console. Seu programa para quando o
//número for negativo.

#include "stdio.h"
#include "math.h"
int digitos(int y){
    int cont=0;
    while(y>0){
        y/=10;
        cont++;
    }
    return cont;
}
int palin(int n, int d){
    int copiad=d;
    int resultado=0;
    for(int i=0; i<copiad; i++){
        int x = n%((int)pow(10,copiad-(copiad-1)));
        x=x*((int)pow(10,d-1));
        resultado+=x;
        n/=10;
        d--;
    }
    return resultado;
}
int main(){
    int x;
    do {
        printf("digite o numero: ");
        scanf("%d", &x);
        if (x < 0) return 0;
        else if (x == palin(x, digitos(x))) printf("VERDADEIRO\n");
        else printf("FALSO\n");
    }while(1);
}