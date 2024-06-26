#include "alm.c"

// falta fazer a copia do vetor

TP *merge(TP **vetp, int n) {
    TP *pilha1 = TP_inicializa(), *pilha2 = TP_inicializa(), *pilha3 =TP_inicializa();
    int maior;
    // crio a copia:
    TP **vetcopia = (TP **) malloc(sizeof(TP*) * n);
    for(int i = 0; i < n; i++){
        vetcopia[i] = TP_inicializa();
        TP *paux = TP_inicializa();
        while (!TP_vazia(vetp[i])){
            TP_push(paux, TP_pop(vetp[i]));
        }
        while (!TP_vazia(paux)){
            int x = TP_pop(paux);
            TP_push(vetp[i],x);
            TP_push(vetcopia[i],x);
        }
        TP_libera(paux);
    }

    // coloco todos numa pilha só
    for (int i=0;i<n;i++){
        while (!TP_vazia(vetcopia[i])){
            TP_push(pilha1, TP_pop(vetcopia[i]));
        }
    }

    // operações
    while ((!TP_vazia(pilha1)) || (!TP_vazia(pilha2))){
        if (!TP_vazia(pilha1)){
            maior = TP_pop(pilha1);
            TP_push(pilha2,maior);
            while (!TP_vazia(pilha1)){
                int x = TP_pop(pilha1);
                TP_push(pilha2,x);
                if (x>maior) maior = x;
            }
            while (!TP_vazia(pilha2)){
                int x = TP_pop(pilha2);
                if (x==maior){
                    while (!TP_vazia(pilha2)){
                        TP_push(pilha1, TP_pop(pilha2));
                    }
                }
                else TP_push(pilha1,x);
            }
        }
        else if (!(TP_vazia(pilha2))){
            maior = TP_pop(pilha2);
            TP_push(pilha1,maior);
            while (!TP_vazia(pilha2)){
                int x = TP_pop(pilha2);
                TP_push(pilha1,x);
                if (x>maior) maior = x;
            }
            while (!TP_vazia(pilha1)){
                int x = TP_pop(pilha1);
                if (x==maior){
                    while (!TP_vazia(pilha1)){
                        TP_push(pilha2, TP_pop(pilha1));
                    }
                }
                else TP_push(pilha2,x);
            }
        }
        TP_push(pilha3,maior);
    }

    TP_libera(pilha1);
    TP_libera(pilha2);
    for (int i=0;i<n;i++){
        free(vetcopia[i]);
    }
    free(vetcopia);
    return pilha3;
}

int main(void){
    int n;
    printf("Digite o numero de pilhas... ");
    scanf("%d", &n);
    if(n <= 0) return 0;

    TP **vetp = (TP **) malloc(sizeof(TP*) * n);
    int i;
    for(i = 0; i < n; i++) vetp[i] = TP_inicializa();

    i = 0;
    while(i < n){
        printf("Digite a pilha %d em ordem decrescente... Quando for fornecido um elemento fora de ordem, a pilha nao recebera mais elementos...\n", i + 1);
        int ant;
        scanf("%d", &ant);
        TP_push(vetp[i], ant);
        while(1){
            int aux;
            scanf("%d", &aux);
            if(aux > ant) break;
            TP_push(vetp[i], aux);
            ant = aux;
        }
        i++;
    }

    TP *resp = merge(vetp, n);
    TP_imprime(resp);
    TP_libera(resp);
    for(i = 0; i < n; i++) TP_libera(vetp[i]);
    free(vetp);
    return 0;
}