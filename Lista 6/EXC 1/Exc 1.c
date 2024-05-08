/*
Desenvolva um procedimento que receba o nome de um arquivo texto e retire deste texto
palavras consecutivas repetidas. O seu programa deve retornar, no arquivo de saída, informado
como parâmetro dessa função, a resposta desta questão. Por exemplo, se o conteúdo de um arquivo
texto for: "Isto e um texto texto repetido repetido repetido . Com as repeticoes
repeticoes fica fica sem sem sentido . Sem elas elas elas melhora melhora um um
pouco .", a saída do seu programa será um arquivo com o seguinte texto: "Isto e um texto
repetido . Com as repeticoes fica sem sentido . Sem elas melhora um um pouco ."
- void RetRepet(char *ArqEnt, char *ArqSaida).
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
void RetRepet(char *ArqEnt, char *ArqSaida){
    FILE* fp1 = fopen(ArqEnt,"r");
    FILE* fp2 = fopen(ArqEnt,"r");
    FILE* fs = fopen(ArqSaida,"w");
    if(!fs || !fp1 || !fp2) exit(1);
    char atual[50], prox[50];
    int v1 = fscanf(fp1,"%s",atual);
    int v2 = fscanf(fp2,"%s",prox);
    v2 = fscanf(fp2,"%s",prox);
    while(v1==1){
        if (v2!=1) {
            fprintf(fs,"%s",atual);
            break;
        }
        if(strcmp(atual,prox) != 0) fprintf(fs,"%s ",atual);
        v1 = fscanf(fp1,"%s",atual);
        v2 = fscanf(fp2,"%s",prox);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fs);
}
int main(){
    RetRepet("entrada.txt","saida.txt");
    return 0;
}