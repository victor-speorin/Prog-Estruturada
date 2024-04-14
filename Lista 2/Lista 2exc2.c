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