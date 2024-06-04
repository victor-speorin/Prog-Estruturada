/*
A questão passava um arquivo de entrada e um vetor preenchido com as palavras que aparecem no arquivo,
e pedia que ordenassemos o vetor conforme o numero de vezes que cada palavra aparecia no arquivo.
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int *preenche(char* arq_ent, char** palavra, int n){
    int *vetin = (int*) malloc(sizeof (int)*n);
    FILE *fp = fopen(arq_ent,"r");
    for (int i=0;i<n;i++){
        char agora[50];
        int c=0, y = fscanf(fp,"%s", agora);
        while(y==1){
            if(strcmp(agora,palavra[i])==0) c++;
            y = fscanf(fp,"%s",agora);
        }
        vetin[i] = c;
        rewind(fp);
    }
    fclose(fp);
    return vetin;
}

char **funcao(int n, char **vet, char*arq_ent){
    int *vetaux = preenche(arq_ent,vet,n);
    vetaux = preenche(arq_ent,vet,n);
    int i, j, menor;
    for(i = 0; i < n; i++){
        menor = i;
        for(j = i + 1; j < n; j++) {
            if (vetaux[menor] < vetaux[j]) {
                menor = j;
            } else if (vetaux[menor] == vetaux[j] && strcmp(vet[menor], vet[j]) > 0) {
                // Se as palavras aparecem a mesma quantidade de vezes, ordena em ordem alfabética
                menor = j;
            }
        }
        if(menor != i){
            int tmp = vetaux[i];
            vetaux[i] = vetaux[menor];
            vetaux[menor] = tmp;
            char jorge[30];
            strcpy(jorge,vet[i]);
            strcpy(vet[i],vet[menor]);
            strcpy(vet[menor],jorge);
        }
    }
    for (int h=0;h<n;h++) printf("%d ",vetaux[h]);
    free(vetaux);
    return vet;
}

int main(void) {
    char** lista_str = (char**)malloc(sizeof(char*)* 6);
    for(int i = 0; i < 6; i++) lista_str[i] = (char*)malloc(sizeof(char)* 30);
    for(int j = 0; j < 6; j++) scanf("%s", lista_str[j]);
    lista_str = funcao(6, lista_str, "Entrada.txt");
    for(int m = 0; m < 6; m++) printf("%s ", lista_str[m]);
    for(int k = 0; k < 6; k++) free(lista_str[k]);
    free(lista_str);
    return 0;
}