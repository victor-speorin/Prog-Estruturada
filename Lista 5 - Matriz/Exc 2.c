//Considere duas matrizes de inteiros de dimensões m1xn1 e m2xn2, onde m1 e n1
//representam, respectivamente, o número de linhas e o número de colunas da primeira matriz, e
//m2 e n2 representam, respectivamente, o número de linhas e o número de colunas da segunda
//matriz. Escreva uma função que realize a multiplicação destas duas matrizes sem alterar nem a
//primeira e nem a segunda matriz: int** mult (int m1, int n1, int **mat1, int m2, int n2, int
//**mat2)
#include "stdio.h"
#include "stdlib.h"
void libera(int **mat, int lin) {
    for(int i = 0; i < lin; i++)
        free(mat[i]);
    free(mat);
}
void mat_leit(int **mat, int lin, int col) {
    int i, j;
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}
int** mult (int m1, int n1, int **mat1, int m2, int n2, int
**mat2){
    int **rep = (int **)malloc(sizeof(int*) * m1);
    for (int i = 0; i < n2; i++){
        rep[i] = (int *) malloc(sizeof(int) * n2);
    }
    for (int i=0;i<m1;i++){
        for(int j=0;j<n2;j++) {
            rep[i][j] = 0;
            for(int k = 0; k < n1; k++){
                rep[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
    return rep;
}
int main(){
    int l1,c1,l2,c2;
    printf("insira as linhas e colunas da primeira matriz: ");
    scanf("%d %d", &l1, &c1);
    printf("insira as linhas e colunas da segunda matriz: ");
    scanf("%d %d", &l2, &c2);
    if (c1 == l2){
        int **mat1 = (int **)malloc(sizeof(int*) * l1);
        for (int i = 0; i < c1; i++){
            mat1[i] = (int *) malloc(sizeof(int) * c1);
        }
        int **mat2 = (int **)malloc(sizeof(int*) * l2);
        for (int i = 0; i < c2; i++){
            mat2[i] = (int *) malloc(sizeof(int) * c2);
        }
        mat_leit((int **) mat1, l1, c1);
        mat_leit((int **) mat2, l2, c2);
        int **resp = mult(l1, c1, (int **) mat1, l2, c2, (int **) mat2);
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < c2; j++) {
                printf("%d ", resp[i][j]);
            }
            printf("\n");
        }
        libera(mat1,l1);
        libera(mat2,l2);
        libera(resp,l1);

    }
    else printf("nao da");
    return 0;
}