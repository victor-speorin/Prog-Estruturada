//Escreva um programa que receba duas strings, como parâmetros de entrada, e informe
//qual é a maior substring existente nas duas strings. Por exemplo, se as strings de entrada são
//ACCTGAACTCCCCCC e ACCTAGGACCCCCC, então a maior substring existente entre as duas
//strings será CCCCCC: char * maior_sub (char *str1, char *str2).

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
char * maior_sub (char *str1, char *str2){
    char* resul=(char*) malloc(sizeof(char)*100);
    int parametro;
    int g=0;
    for (int i=0;i< strlen(str1);i++){
        parametro =0;
        for (; parametro < strlen(str2); parametro++) {
                if(str1[i]==str2[parametro]){
                    resul[g]=str1[i];
                    g++;
                    parametro++;
                    break;
                }
            }
            }
    resul[g]='\0';
    return resul;
}
int main(){
    char x[100], y[100];
    printf("primeira string: ");
    scanf("%s",x);
    printf("segunda string: ");
    scanf("%s",y);
    char *j= maior_sub(x,y);
    printf("%s",j);
    free(j);
}
