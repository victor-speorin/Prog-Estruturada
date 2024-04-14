#include "stdio.h"
#include "string.h"
void retira_inicio_n (char *x, int n){
    int c=0;
    for (int i=0;i<strlen(x); i++){
        if(i>=n){
            x[c]=x[i];
            c++;
        }
    }
    x[strlen(x)-n]='\0';
}
int main(){
    char x[100]; int n;
    printf("digite sua string: ");
    scanf("%s", x);
    printf("quer tirar quantos elementos? ");
    scanf("%d", &n);
    if (n> strlen(x)) printf("error");
    else{
        retira_inicio_n(x,n);
        printf("%s", x);
    }
    return 0;
}