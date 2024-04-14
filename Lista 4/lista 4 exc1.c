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