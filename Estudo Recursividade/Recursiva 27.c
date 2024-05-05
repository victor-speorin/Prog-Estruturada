// Verificar se uma palavra é palindromo
#include "stdio.h"
#include "string.h"
void palindromo(char *x,int ini, int fim){
    if (ini>=fim){
        printf("palindromo :)");
        return;
    }
    if (x[ini]==x[fim]) {
        palindromo(x,ini+1, fim-1);
    }
    else{
        printf("nao eh");
        return;
    }
}
int main(){
    char p[100];
    scanf("%s",p);
    palindromo(p,0, strlen(p)-1);
    return 0;
}