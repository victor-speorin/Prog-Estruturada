// receba uma matriz e ordene ela.

#include "stdio.h"
#include "stdlib.h"
int compara(const void *a, const void *b){
    int *px=(int*)a, *py=(int*)b;
    int x=(*px), y=(*py);
    if (x<y) return -1;
    if (x>y) return 1;
    return 0;
}
int *mat_vet(int **mat,int lin,int col){
    int tam=lin*col, x=0;
    int *vet= (int*) malloc(sizeof(int)*tam );
    for (int i=0;i<lin;i++){
        for (int j=0;j<col;j++){
            vet[x]=mat[i][j];
            x++;
        }
    }
    return vet;
}
int main(){
    int l,c;
    printf("insira linhas e colunas: ");
    scanf("%d %d", &l,&c);
    int **mat= (int **) malloc(sizeof(int*)*l );
    for (int i=0;i<c;i++){
        mat[i]= (int *) malloc(sizeof(int)*c );
    }
    for (int i=0;i<l;i++){
        for (int j=0;j<c;j++){
            scanf("%d", &mat[i][j]);
        }
    }
    int *vet= mat_vet(mat,l,c);
    qsort(vet,(l*c),sizeof(int),compara);
    int x=0;
    for(int i=0;i<l;i++){
        for (int j=0;j<c;j++){
            mat[i][j]=vet[x];
            x++;
        }
    }
    for(int i=0;i<l;i++){
        for (int j=0;j<c;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    free(vet);
    for (int i=0;i<l;i++) free(mat[i]);
    free(mat);
}