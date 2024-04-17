//Escreva uma função que receba, como entrada, uma cadeia de caracteres s e um inteiro n, e, em
//seguida, retire o "prefixo" da cadeia s de tamanho n (isto é, retire os n primeiros caracteres). Se a
//cadeia não tiver pelo menos n caracteres, deve ser impressa a mensagem "erro". Por exemplo, se s
//= "abcdefghi" e n = 3, então a cadeia "defghi" deve ser impressa; com a mesma cadeia s e n = 17,
//deve ser impresso "erro". O protótipo desta função é o seguinte: void retira_inicio_n (char *str, int
//n).

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