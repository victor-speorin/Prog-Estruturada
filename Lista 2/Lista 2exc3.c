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