// printar a maior sequencia crescente de numeros de um arquivo.
#include "stdio.h"
#include "stdlib.h"
void crescente(char *arq){
    FILE* fp = fopen(arq,"r");
    FILE* fp2 = fopen(arq,"r");
    if (!fp || !fp2) exit(1);
    int atual, prox, maior1, maior2=0;
    int v1 = fscanf(fp,"%d",&atual);
    int v2 = fscanf(fp2,"%d",&prox);
    v2 = fscanf(fp2,"%d",&prox);
    while (v1==1){
        if (prox > atual) maior1 ++;
        else maior1 = 1;
        if (maior1 >= maior2) maior2 = maior1;
        v1 = fscanf(fp,"%d",&atual);
        v2 = fscanf(fp2,"%d",&prox);
    }
    printf("%d",maior2);
    fclose(fp);
    fclose(fp2);
}
int main(){
    crescente("Entrada.txt");
    return 0;
}