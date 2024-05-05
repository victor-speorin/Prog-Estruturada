#include "stdio.h"
void rec(int *vet,int ini, int n){
    if (ini>=n) return;
    int temp;
    temp=vet[n-1];
    vet[n-1]=vet[ini];
    vet[ini]=temp;
    rec(vet,ini+1,n-1);
}
int main(){
    int n;
    scanf("%d", &n);
    int vet[n];
    for (int i=0;i<n;i++) scanf("%d", &vet[i]);
    rec(vet,0,n);
    for (int i=0;i<n;i++) printf("vet[%d]=%d\n", i, vet[i]);
    return 0;
}