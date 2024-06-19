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

void imprime (TALUNO **mat, int n){
    for (int i=0;i<n;i++){
        if (((mat[i]->p1 + mat[i]->p2) / 2) >= 6.0) printf("%s da turma %s esta aprovado(a) com media %.1f\n", mat[i]->nome, mat[i]->turma, ((mat[i]->p1 + mat[i]->p2) / 2));
        else printf("%s da turma %s esta reprovado(a) com media %.1f\n", mat[i]->nome, mat[i]->turma, ((mat[i]->p1 + mat[i]->p2) / 2));
    }
}

int main(){
    int n;
    printf("digite o numero de alunos: ");
    scanf("%d",&n);
    printf("\n");
    TALUNO **alunos = (TALUNO**) malloc(sizeof(TALUNO*) *n );
    for (int i=0;i<n;i++){
        alunos[i] = (TALUNO*) malloc(sizeof(TALUNO));
        printf("digite a turma do aluno %d: ",i+1);
        scanf("%s", alunos[i]->turma);
        printf("digite o nome do aluno %d:", i+1);
        scanf(" %31[^\n]",alunos[i]->nome);
        printf("p1 e p2 de %s: ", alunos[i]->nome);
        scanf("%f %f", &alunos[i]->p1, &alunos[i]->p2);
        printf("\n");
    }
    imprime(alunos,n);
    for (int i=0;i<n;i++){
        free(alunos[i]);
    }
    free(alunos);
    return 0;
}