//Escreva um programa que ordena uma turma de alunos: void ordena (char** turma, int n);
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int compara(const void *a, const void *b){
    char **px=(char**)a, **py=(char**)b;
    char *x=(*px), *y=(*py);
    int resp = strcmp(x, y);
    if(resp == 0) return 0;
    if(resp>0) return 1;
    return -1;
}
void ordena (char** turma, int n){
    qsort(turma,n,sizeof (char *),compara);
    for (int i=0;i<n;i++) printf("%s\n",turma[i]);
}
int main(){
    int n;
    scanf("%d", &n);
    char **turma;
    turma = (char **)malloc(sizeof (char *)*n);
    for (int i=0;i<n;i++) turma[i]=(char*) malloc(sizeof (char)*31);
    for (int i=0;i<n;i++) scanf(" %30[^\n]", turma[i]);
    ordena(turma,n);
    for(int i=0;i<n;i++){
        free(turma[i]);
    }
    free(turma);
    return 0;
}
