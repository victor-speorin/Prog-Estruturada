#include "alm.c"


TP *merge(TP **vetp, int n) {
    TP **vetcopia = (TP **) malloc(sizeof(TP*) * n), *presp = TP_inicializa();
    int qt=0;
    for(int i = 0; i < n; i++){
        vetcopia[i] = TP_inicializa();
        TP *paux = TP_inicializa();
        while (!TP_vazia(vetp[i])) {
            int x = TP_pop(vetp[i]);
            TP_push(paux, x);
            TP_push(vetcopia[i],x);
            qt++;
        }
        while (!TP_vazia(paux)) TP_push(vetp[i], TP_pop(paux));
        TP_libera(paux);
    }
    int maior,x;
    TP *bckp;
    for (int i=0;i<qt;i++){
        if (!TP_vazia(vetcopia[0])) {
            maior = TP_pop(vetcopia[0]);
            bckp = vetcopia[0];
        }
        else{
           maior = INT_MIN;
           bckp = NULL;
        }
        for (int j=1;j<n;j++){
            if(!TP_vazia(vetcopia[j])) {
                x = TP_pop(vetcopia[j]);
                if (x > maior) {
                    TP_push(bckp, maior);
                    bckp = vetcopia[j];
                    maior = x;
                } else {
                    TP_push(vetcopia[j], x);
                }
            }
        }
        TP_push(presp,maior);
    }

    for (int i=0;i<n;i++) TP_libera(vetcopia[i]);
    free(vetcopia);
    return presp;

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
        printf("Digite a pilha %d em ordem decrescente... Quando for fornecido um elemento fora de ordem, a pilha não receberá mais elementos...\n", i + 1);
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
