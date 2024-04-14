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