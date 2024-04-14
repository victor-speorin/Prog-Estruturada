#include <stdio.h>
int main(){
    int qtd;
    int loop = 0;
    printf("Digite a qtd de numeros: ");
    scanf("%d", &qtd);
    int soma = 0;
    while (loop<qtd) {
        int cont = 0;
        int y = 1;
        int x;
        printf("numero: ");
        scanf("%d", &x); // escolhendo o numero
        while (y < x) {    // vai dividir por todos os numeros até o anterior dele
            if (x % y == 0) {
                cont++;
            }
            y++;
        }
        if (cont == 1)
            soma = soma + x;
        loop ++;
    }
    printf("soma dos primos = %d", soma);
    return 0;
}