#include "stdio.h"
#include "string.h"
void retira_fim_n (char *str, int n){
    str[strlen(str)-n]='\0';
}
int main(){
    char x[100]; int n;
    printf("digite sua string: ");
    scanf("%s", x);
    printf("quer tirar quantos elementos? ");
    scanf("%d", &n);
    if (n> strlen(x)) printf("error");
    else{
        retira_fim_n(x,n);
        printf("%s", x);
    }
    return 0;
}