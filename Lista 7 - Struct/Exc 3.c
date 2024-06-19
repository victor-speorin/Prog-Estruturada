/*
Considerando a definição de TALUNO da (Q2), escreva uma função que retorne a média
geral de uma determinada turma. O protótipo desta função é o seguinte: float media_geral
(TALUNO **mat, int n, char *turma).
*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct aluno{
    char nome[31];
    char mat[10], turma[3];
    float p1, p2;
}TALUNO;

float media_geral(TALUNO **mat, int n, char *turma){
    float notas = 0, alunos = 0;
    for (int i=0;i<n;i++){
        if (strcmp(mat[i]->turma,turma)==0){
            alunos ++;
            notas += ((mat[i]->p1 + mat[i]->p2) / 2);
        }
    }
    return notas / alunos;
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
    char turma[3];
    printf("digite a turma que voce quer tirar a media: ");
    scanf("%s",turma);
    float resp = media_geral(alunos,n,turma);
    printf("a media geral da turma %s eh %.2f",turma,resp);
    for (int i=0;i<n;i++){
        free(alunos[i]);
    }
    free(alunos);
    return 0;
}