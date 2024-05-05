// numeros de catalan
#include "stdio.h"
float rec(float n){
    if (n==0) return 1;
    return ((2*((2*n)-1))/(n+1)) * rec(n-1);
}
int main(){
    float x;
    scanf("%f",&x);
    float z = rec(x);
    printf("%.1f",z);
    return 0;
}