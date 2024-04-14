#include "stdio.h"
void vet_leitura(int *vet, int n){
    int i;
    for(i = 0; i < n; i++) scanf("%d", &vet[i]);
}
int main(){
    int x,y;
    do{
        scanf("%d %d", &x, &y);
        if ((x==0) && (y==0)) return 0;
        int lista[y];
        vet_leitura(lista, y);
        int c=0;
        while (x>=1){
            int resp=0;
            for (int i=0; i<y; i++){
                if (lista[i] == x) resp++;
                if (resp>1){
                    c++;
                    resp=0;
                }
                }
            x--;
        }
        printf("%d\n", c);
        }while(1);
    }