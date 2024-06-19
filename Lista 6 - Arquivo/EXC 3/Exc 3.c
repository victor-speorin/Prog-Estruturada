/*
Escreva um programa que retire toda a pontuação, passada como parâmetro,
de um arquivo texto, gerando um novo arquivo:
void ret_pont (char *arq_ent, char *arq_saida, char **pontuacao, int n);
*/
#include "stdio.h"
#include "stdlib.h"
void ret_pont (char *arq_ent, char *arq_saida){
    FILE* fp = fopen(arq_ent,"r");
    FILE* fs = fopen(arq_saida,"w");
    if (!fp || !fs) exit(1);
    char atual[50];
    int v1 = fscanf(fp,"%s",atual);
    while(v1==1){
        if ((atual[0] >= 33 && atual[0] <= 47) || (atual[0] >= 58 && atual[0] <= 64)) {
        } else fprintf(fs, "%s ", atual);
        v1 = fscanf(fp,"%s",atual);
    }
    fclose(fp);
    fclose(fs);
}
int main(){
    ret_pont("Entrada.txt", "Saida.txt");
    return 0;
}