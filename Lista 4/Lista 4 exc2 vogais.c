#include "stdio.h"
#include "stdlib.h"
#include "string.h"
char * codifica (char *x) {
    char *nova = (char*)malloc(sizeof(char)*(strlen(x)+1));
    for (int i=0;i<strlen(x);i++) nova[i]=x[i];
    for (int j=0;j<strlen(x);j++){
        if(nova[j]=='A' || nova[j]== 'a' || nova[j]== 'E' || nova[j]== 'e' || nova[j]== 'I' || nova[j]== 'i' || nova[j]== 'O' || nova[j]=='o' || nova[j]=='U' || nova[j]=='u') nova[j]='?';
    }
    nova[strlen(x)] = '\0'; //ajustando pra o último caractere da nova não ser impresso
    return nova;
}
int main(){
    int n;
    printf("qual tamanho da coisa a converter: ");
    scanf("%d", &n);
    char x[n+1];
    scanf("%s", x);
    char *copia = codifica(x);
    printf("og: %s\n",x);
    printf("novo: %s", copia);
    free(copia);
    return 0;
}