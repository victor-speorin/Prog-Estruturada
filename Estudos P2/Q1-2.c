#include "alm.c"

// fazer do jeito q o miguel disse

TP *merge(TP **vetp, int n) {

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
