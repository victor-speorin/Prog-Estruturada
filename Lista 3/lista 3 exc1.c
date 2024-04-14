#include "stdio.h"
int main(){
    int n;
    do{ scanf("%d", &n); }while(n<=1);
    int vet[n-1];
    int p = 0;
    for (int u=2; u<=n; u++){
        vet[p]=u;
        p++;
    }
    for (int d=0; d<n-1; d++) {
        for (int i = d+1; i < n - 1; i++) {
            if (vet[d]==-1 || vet[i]==-1) continue;
            else if (vet[i] % vet[d]  == 0) vet[i] = -1;
        }
    }
    for (int h=0; h<n-1; h++){
        if (vet[h]!=-1) printf("%d\n", vet[h]);
    }
}