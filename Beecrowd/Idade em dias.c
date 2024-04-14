#include <stdio.h>

int main() {
    int dias, anos, meses, cont_dias;
    scanf("%d",&dias);
    anos = dias/365;
    meses = (dias%365)/30;
    cont_dias = (dias%365)%30;
    printf("%d ano(s)", anos);
    printf("\n%d mes(es)", meses);
    printf("\n%d dia(s)", cont_dias);
    printf("\n");


    return 0;
}