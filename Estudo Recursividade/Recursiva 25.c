// Palavra de Fibonacci. Faça uma função recursiva que receba um número N e retorne a N-ésima
// palavra de Fibonacci
#include "stdio.h"
void rec(int n) {
    if (!n) printf("b");
    else if (n == 1) printf("a");
    else {
        rec(n-1);
        rec(n-2);
    }
}
int main(){
    int n; scanf("%d", &n);
    rec(n);
    return 0;
}