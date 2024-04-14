#include <stdio.h>
int main(){
    int x;
    printf("Digite quantos numeros vc quer: ");
    scanf("%d", &x);
    int p = 1, s = 1, t;
    printf("%d\n %d\n", p, s);
    for (int i = 1; i<x-1; i++){
        t = p + s;
        printf("%d\n", t);
        p=s;
        s=t;
    }
    return 0;
}