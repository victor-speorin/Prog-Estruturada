//Implemente uma função em C que receba uma string como parâmetro e substitua todas as suas
//letras por predecessoras do alfabeto, trocando maiúsculas por minúsculas. Por exemplo, a string
//“Amor” seria alterada para “zLNQ”. Esta função deve obedecer o seguinte protótipo: void
//shift_troca_string (char *str). A letra ‘a’ deve ser substituída por ‘Z’ (e ‘A’ por ‘z’). Caracteres que não
//forem letras devem ser substituídos por ‘!’. Sabe-se que A = 65, Z = 90, a = 97 e z = 122.

#include "stdio.h"
#include "string.h"
void shift_troca_string (char *x){
    int h = strlen(x);
    for (int i=0;i<h;i++){
        if (x[i]==65) x[i]=122;
        else if (x[i]==97) x[i]=90;
        else if (x[i]>65 && x[i]<=90) x[i]+=31;
        else if (x[i]>=97 && x[i]<=122) x[i]-=33;
        else x[i]='!';
    }
}
int main(){
    int n;
    printf("qual o tamanho da palvara a converter: ");
    scanf("%d", &n);
    char x[n+1];
    scanf("%s", x);
    shift_troca_string(x);
    printf("%s", x);
}