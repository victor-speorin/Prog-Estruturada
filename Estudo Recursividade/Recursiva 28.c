/*
Busca sequencial em um veto desordenado que retorna a posição da primeira
ocorrência de um elemento procurado usando uma estratégia similar a da busca
binaria.
*/
#include "stdio.h"
int rec(int *vet, int x, int ini, int fim){
    if (ini > fim) return -1;
    int meio = ini + (fim - ini) / 2;
    if (vet[meio] == x) {
        int esq = rec(vet, x, ini, meio - 1);
        if (esq != -1) return esq;
        return meio;
    } else {
        int esq = rec(vet, x, ini, meio - 1);
        int dir = rec(vet, x, meio + 1, fim);
        if (esq!=-1) return esq;
        return dir;
    }
}
int main(){
    int x, n;
    printf("digite o tamanho do vetor: "); scanf("%d",&n);
    printf("qual elemento quer procurar: "); scanf("%d", &x);
    int vet[n]; printf("vetor: ");
    for (int i=0;i<n;i++) scanf("%d", &vet[i]);
    int resp = rec(vet,x,0,n);
    if (resp<0) printf("nao tem");
    else printf("posicao %d",resp+1);
    return 0;
}