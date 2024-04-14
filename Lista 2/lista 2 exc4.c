#include <stdio.h>
void vet_leit(int *vet, int n){
    for(int i = 0; i < n; i++) scanf("%d", &vet[i]);
}
void copia_vet(int *copia ,int *vet, int n){
    for(int i = 0; i < n; i++) copia[i] = vet[i];
}
void vet_bs(int *vet, int n){
    int i, j;
    for(j = n - 1; j > 0; j--)
        for(i = 0; i < j; i++)
            if(vet[i] > vet[i + 1]){
                int tmp = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = tmp;
            }
}
int main(){
    int n, vet[n], copia[n];
    do{
        scanf("%d", &n);
        vet_leit(vet, n);
        copia_vet(copia,vet,n);
        vet_bs(copia,n);
        for (int i=0; i<n; i++){
            if (copia[n-2] == vet[i]) printf("%d\n", i+1);
        }
    }while(n != 0);
    return 0;
}