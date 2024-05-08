/*
Escreva um programa que retire toda a pontuação, passada como parâmetro,
de um arquivo texto, gerando um novo arquivo:
void ret_pont (char *arq_ent, char *arq_saida, char **pontuacao, int n);
*/
#include "stdio.h"
#include "stdlib.h"
void ret_pont (char *arq_ent, char *arq_saida, char **pontuacao, int n){
    FILE* fp = fopen(arq_ent,"r");
    if (!fp) exit(1);
    char atual[50];
    int v1 = fscanf(fp,"%s",atual);
    while(v1==1){
        v1 = fscanf(fp,"%s",atual);
        if ((atual >= 33 && atual <= 47 ) || (atual >= 58 && atual <= 64 )){
            
        }
    }
}
int main(){

}