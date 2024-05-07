//Faça uma função recursiva, em linguagem C, que calcule o valor da série S
//descrita a seguir para um valor n>0 a ser fornecido como parâmetro para a mesma.
// S = 2 + 5/2 + 10/3 + (1+n^2)/n
#include "stdio.h"
float rec(float n){
    if (n==1) return 2;
    return rec(n-1) + (1+(n*n))/n;
}
int main(){
    float n; scanf("%f",&n);
    float z = rec(n); printf("%.0f",z);
    return 0;
}