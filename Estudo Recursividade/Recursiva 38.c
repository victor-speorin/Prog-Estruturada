/*
Uma matriz maze de 0s e 1s, de 10X10, representa um labirinto no qual um viajante
precisa encontrar um caminho de maze[0][0] a maze[9][9]. O viajante pode passar de
um quadrado para qualquer outro adjacente na mesma fileira ou coluna, mas não pode
saltar quadrados nem se movimentar na diagonal. Além disso, o viajante não pode
entrar num quadrado contendo um 1. maze[0][0] e maze[9][9] contêm 0s. Escreva uma
rotina recursiva que aceite este labirinto maze e imprima uma mensagem informando a
inexistência de um caminho através do labirinto, ou que imprima uma lista de posições
representando um caminho de [0][0] a [9][9].
OBS: estou considerando um labirinto perfeito.
*/
#include "stdio.h"
void lab(int **mat, int lin, int col){
    if (lin==9 && col==9) {
        printf("mat[9][9]");
        return;
    }
    if (mat[lin+1][col]==0){
        printf("mat[%d][%d]",lin+1,col);
        lab(mat,lin+1,col);
    }
    else if (mat[lin][col+1]==0){
        printf("mat[%d][%d]",lin,col+1);
        lab(mat,lin,col+1);
    }
    else {
        (printf("nao tem caminho"));
        return;
    }
}
int main(){
    int mat[10][10];
    printf("digite o labirinto: \n");
    for (int i = 0;i<10;i++){
        for(int j=0;j<10;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    lab((int **) mat, 0, 0);
    return 0;
}