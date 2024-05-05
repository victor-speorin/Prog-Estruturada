// funçao recursiva que retorna a soma dos elementos de um vetor
#include <stdio.h>
float rec(float *vet, int n) {
    if (n == 1) return vet[0];
    return rec(vet, n-1) + vet[n-1];
}
int main() {
    int n;
    scanf("%d", &n);
    float vet[n];
    for (int i = 0; i < n; i++) scanf("%f", &vet[i]);
    float x = rec(vet, n);
    printf("%.2f", x);
    return 0;
}
