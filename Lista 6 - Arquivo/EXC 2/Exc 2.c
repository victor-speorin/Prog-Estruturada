/*
Escreva um procedimento que receba o nome de um arquivo texto, cujo conteúdo são valores
inteiros positivo, onde o maior elemento deste arquivo é 1000, e imprima na tela o número de vezes
que cada elemento aparece – void resumo(char *Arq).
*/
#include "stdio.h"
#include "stdlib.h"
void resumo(char *Arq){
    FILE* fp = fopen(Arq, "r");
    if (!fp) exit(1);
    int n, x = 0;
    int v1 = fscanf(fp,"%d",&n);
    while(v1==1){
        v1 = fscanf(fp,"%d",&n);
        x++;
    }
    rewind(fp);
    int vet[x];
    for (int i=0;i<x;i++){
        fscanf(fp,"%d",&n);
        vet[i]=n;
    }
    int c , h = x, j=0;
    while(h>0) {
        c=0;
        for (int i = 0; i < x; i++) {
            if (vet[j] == vet[i]) c++;
        }
        printf("o numero %d aparece %d vezes\n ",vet[j],c);
        h--;
        j++;
    }
    fclose(fp);
}
int main(){
    resumo("Entrada.txt");
    return 0;
}