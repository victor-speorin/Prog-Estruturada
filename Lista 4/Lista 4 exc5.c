//Escreva uma função que dadas duas strings, retorne UM se a primeira contém a segunda,
//ignorando maiúsculas e minúsculas, e ZERO, caso contrário. O protótipo da função é o seguinte: int
//cic (char *str1, char *str2).

#include <stdio.h>
#include "string.h"
void conversor (char *x){
    for (int i=0;i< strlen(x); i++){
        if (x[i] >= 65 && x[i]<=90) x[i]+=32;
    }
}
int cic (char *str1, char *str2){
    int c=0;
    for (int i=0;i< strlen(str1);i++){
        if (str1[i]==str2[0]) {
            for (int u = 0; u < strlen(str2); u++) {
                if (str1[i] == str2[u]) {
                    c++;
                    i++;
                }
            }
        }
        if (c!= strlen(str2)) c=0;
        else break;
    }
    if (c== strlen(str2)) return 1;
    return 0;
}
int main(){
    char x[100], y[100];
    printf("primeira string: ");
    scanf("%s",x);
    printf("segunda string: ");
    scanf("%s", y);
    conversor(x);
    conversor(y);
    int resultado= cic(x,y);
    if (resultado){
        printf("%d", resultado);
        return 0;
    }
    printf("%d", resultado);
    return 0;
}