/*
receber um vetor de palavras, criar uma LSE com cada elemento sendo: a palavra, o numero de
vezes que ela aparece no vetor, e um ultimo campo sendo uma outra LSE que contém cada posição
que a palavra aparece. Ordenar essa LSE primeiro descrescentemente pelo numero de vezes que cada
palavra aparece e depois por ordem alfabetica.
 */
#include "TLSEP.h"
#include "TLSE.c"

int compara (const void *a, const void *b){
    TLSEP **pa = (TLSEP**)a, **pb = (TLSEP**)b;

    if ((*pa)->num_vezes>(*pb)->num_vezes) return -1;
    if ((*pa)->num_vezes<(*pb)->num_vezes) return 1;

    if (strcmp((*pa)->pal,(*pb)->pal)>0) return 1;
    if (strcmp((*pa)->pal,(*pb)->pal)<0) return -1;

}

TLSEP *ordena (char **palavras, int n){
    if (!n) return NULL;
    TLSEP *listona = NULL;
    int tam=0;
    // insiro os elementos na LSEP
    for (int i=0;i<n;i++){
        TLSEP *ver = TLSEP_busca(listona,palavras[i]);
        // se eu busquei e não achei, insiro normal
        if (!ver) {
            listona= TLSEP_ins_ini(listona,palavras[i],i);
            tam++;
        }
        // caso contrario vou no ponteiro e atualizo as informações
        else{
            ver->num_vezes+=1;
            ver->linhas= TLSE_ins_fim(ver->linhas,i);
        }
    }
    TLSEP **vet = (TLSEP**) malloc(sizeof(TLSEP*)*tam);
    // coloco todos num vetor
    for (int i=0;i<tam;i++){
        vet[i] = listona;
        listona=listona->prox;
    }
    // ordeno o vetor por numero de ocorrencias e depois ordem alfabetica
    qsort(vet,tam,sizeof(TLSEP*),compara);
    TLSEP *l = vet[0];
    TLSEP*p=l;
    // coloco l no começo e conecto nos proximos
    for (int i=1;i<tam;i++){
        p->prox=vet[i];
        p=p->prox;
    }
    // conecto o ultimo em NULL
    p->prox=NULL;
    TLSEP_libera(listona);
    free(vet);
    return l;
}

int main(int argc, char **argv){
    if(argc == 1) printf("ERRO: <./nome_exec> <palavras a serem ordenadas separadas por espacos em branco\n");
    else{
        int n = argc - 2, i;
        char **pal = (char **)malloc(sizeof(char *) * n);
        for(i = 0; i < n; i++){
            pal[i] = (char *) malloc(sizeof(char) * 31);
            strcpy(pal[i], argv[i + 2]);
        }
        printf("Depois de ordena...\n");
        /*
        TLSEP *l = NULL;
        l = ordena(pal, n);
        TLSEP_imprime(l);
        TLSEP_libera(l);
        */
        for(i = 0; i < n; i++) free(pal[i]);
        free(pal);
    }
    return 0;
}
