//Entrada: a primeira linha da entrada contém um único inteiro N (1 ≤ N ≤ 3000), indicando o
//número de casos de teste. Cada caso de teste contém 2 inteiros F1 (1 ≤ F1 ≤ 1000) e F2 (1
//≤ F2 ≤ 1000) indicando, respectivamente, a quantidade de figurinhas que Ricardo e Vicente
//têm para trocar.
//
//Saída: para cada caso de teste de entrada haverá um valor na saída, representando o tamanho
//máximo da pilha de figurinhas que poderia ser trocada entre dois jogadores.

#include "stdio.h"
int mdc(int a, int b) {
    while (b != 0) {
        int resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}
int main(){
    do{
        int x,y;
        printf("figurinhas: ");
        scanf("%d %d", &x, &y);
        if (x<=0 || y<=1) return 0;
        printf("a pilha eh %d\n", mdc(x, y));
    }while(1);
}
