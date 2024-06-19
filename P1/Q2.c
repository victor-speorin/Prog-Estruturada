/*
Essa era a questão mais simples da prova, pedia que fizessemos uma função que recebesse um vetor e
ordenasse ele conforme as aparições dos numeros impares e depois dos pares, e nao poderiamos usar
metodos de ordenação ou vetores auxiliares.
*/

#include <stdlib.h>
#include "stdio.h"

void impar_par(int *vet, int n){
    int indimpar, impar, ver=0;
    while (vet[ver]%2!=0){ // apenas adicionei esse while para caso os primeiros termos sejam impares, só "pular" eles.
        ver++;
    }
    indimpar = ver;
    for (int i=ver;i<n;i++){
        if (vet[i]%2!=0){
            impar = vet[i];
            for (int j=i;j>indimpar;j--) vet[j] = vet[j-1];
            vet[indimpar] = impar;
            indimpar ++;
        }
    }
}

int main(void){
    int n;
    do{
        scanf("%d", &n);
        if(n > 0)break;
    }while(1);
    int vet[n], i;
    for(i = 0; i < n; i++)scanf("%d", &vet[i]);
    for(i = 0; i < n; i++) printf("vet[%d] = %d\n", i, vet[i]);
    impar_par(vet, n);
    printf("Depois de impar_par...\n");
    for(i = 0; i < n; i++) printf("vet[%d] = %d\n", i, vet[i]);
    return 0;
}