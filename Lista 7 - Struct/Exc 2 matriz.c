/*
Dada a estrutura que representa o cadastro de um aluno numa disciplina:

typedef struct aluno{
char nome[31];
char mat[10], turma[3];
float p1, p2;
}TALUNO;

Escreva uma função que imprima os nomes dos alunos aprovados por média em cada uma das
turmas. O aluno será considerado aprovado se a média aritmética das notas das suas provas for
maior ou igual a SEIS. O protótipo desta função é o seguinte: void imprime (TALUNO **mat,
int n).
*/
#include "stdio.h"
#include "stdlib.h"
typedef struct aluno{
    char nome[31];
    char mat[10], turma[3];
    float p1, p2;
}TALUNO;

void imprime (TALUNO **mat, int lin,int col){
    for (int i=0;i<lin;i++){
        for (int j=0;j<col;j++){
            if (((mat[i][j].p1 + mat[i][j].p2) / 2) >= 6.0) printf("%s da turma %d\n", mat[i][j].nome, i);
        }
    }
}

int main(){
    int na, nt;
    printf("digite o numero de turmas: ");
    scanf("%d",&nt);
    printf("digite o numero de alunos de cada turma: ");
    scanf("%d",&na);
    TALUNO **matriz = (TALUNO**)malloc(sizeof(TALUNO*) * (nt));
    for (int i=0;i<nt;i++) {
        matriz[i] = (TALUNO *) malloc(sizeof(TALUNO) * (na));
    }
    for (int i=0;i<nt;i++){
        for (int j=0;j<na;j++){
            matriz[i][j].turma[0] = i;
            printf("digite o nome da turma %d: ",i);
            scanf("%s", matriz[i][j].nome);
            printf("p1 e p2: ");
            scanf("%f %f", &matriz[i][j].p1, &matriz[i][j].p2);
        }
    }
    imprime(matriz,nt,na);
    for (int i=0;i<nt;i++){
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}