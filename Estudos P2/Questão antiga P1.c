/*
A questão se baseava em receber um vetor de ponteiro na função TP *retira_k(TP **vet,int k, int n)
na qual cada um dos ponteiros destre vetor aponta para uma struct.
A struct padrão tem os campos char data_nasc, char nome e int ins,
e devemos retornar para a main a k-ésima pessoa deste vetor caso ele estivesse ordenado
com os seguintes parâmetros:
1- Mais velhos primeiros
2- Ordem crescente de nome
3- Número de ins no SUS

OBS: O vetor em si não pode ser ordenado e o elemento k no vetor ORIGINAL
deve ser retirado (mete NULL no lugar)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// resolver o problema da impressão

//Definindo a struct
typedef  struct paciente{
    char nome[11];
    char data_nasc[9];
    int insc;
} TP;

int compara(const void *a, const void *b){
    TP **pa = (TP**)a, **pb = (TP**)b; // afirmação
    TP *x = (*pa), *y=(*pb); // simplificação

    if (strcmp(&x->data_nasc[4],&y->data_nasc[4])>0) return 1;
    if (strcmp(&x->data_nasc[4],&y->data_nasc[4])<0) return -1;

    if (strcmp(&x->data_nasc[2],&y->data_nasc[2])>0) return 1;
    if (strcmp(&x->data_nasc[2],&y->data_nasc[2])<0) return -1;

    if (strcmp(x->data_nasc,y->data_nasc)>0) return 1;
    if (strcmp(x->data_nasc,y->data_nasc)<0) return -1;

    if (strcmp(x->nome,y->nome)>0) return 1;
    if (strcmp(x->nome,y->nome)<0) return -1;

    if (x->insc > y->insc) return 1;
    return -1;
}

TP *retira_k(TP **vet,int k, int n){
    // copiei
    TP **vet_ord = (TP**)malloc(sizeof(TP*)*n);
    for(int i = 0; i < n; i++){
        vet_ord[i] = (TP*)malloc(sizeof(TP));
        strcpy(vet_ord[i]->nome,vet[i]->nome); // Copia o nome
        strcpy(vet_ord[i]->data_nasc,vet[i]->data_nasc); // Copia a data
        vet_ord[i]->insc = vet[i]->insc; // Copia a inscrição
    }

    // ordenei
    qsort(vet_ord,n,sizeof(TP*),compara);
    // achando o k-esimo
    TP *resp = vet_ord[k];
    for (int i=0;i<n;i++){
        if (vet[i]==vet_ord[k]){
            vet[i] = NULL;
            break;
        }
    }

    //só conferindo
    printf("vetor ordenado:\n");
    for (int i=0;i<n;i++){
        printf("paciente %d:\n %s",i, vet_ord[i]->data_nasc);
        printf("\n");
        printf("%s", vet_ord[i]->nome);
        printf("\n");
        printf("%d", vet_ord[i]->insc);
        printf("\n");
    }

    for (int i=0;i<n;i++){
        free(vet_ord[i]);
    }
    free(vet_ord);

    // só conferindo
    printf("%s",resp->nome);
    printf("%s",resp->data_nasc);
    printf("%d",resp->insc);

    return resp;

}


int main(void){
    //Inicializando e recebendo as variáveis que serão usadas
    int n, k;
    printf("Digite a quantidade de pacientes: ");
    scanf("%d", &n);

    printf("Digite o k-esimo paciente que deseja vacinar: ");
    scanf("%d", &k);

    //Criando o vetor que será preenchido com os ponteiros de structs
    TP **vet = (TP**)malloc(sizeof(TP*)*n);

    //Criando cada ponteiro e preenchendo as suas structs respectivas
    for(int i = 0; i < n; i++){
        vet[i] = (TP*)malloc(sizeof(TP));
        printf("Digite o nome do paciente %d: ", i);
        scanf("%s", vet[i]->nome);

        printf("Digite a data de nascimento(ddmmaaaa) do paciente %d: ", i);
        scanf("%s", vet[i]->data_nasc);

        printf("Digite o numero de insc do paciente %d: ", i);
        scanf("%d", &vet[i]->insc);

        printf("\n");
    }

    //Com o banco de dados feito, vamos chamar a função para pegar o k-ésimo paciente ordenado
    TP * paciente_k = retira_k(vet,k,n);

    //Printando o paciente_k que será vacinado
    printf("O paciente %d eh o: %s, nascido em: %s, com numero de ins: %d ",k,paciente_k->nome,paciente_k->data_nasc,paciente_k->insc);

    //Vamos desalocar os vetores utilizados
    for(int i = 0; i < n; i++){
        free(vet[i]);
    }
    free(vet);

    return 0;
}
