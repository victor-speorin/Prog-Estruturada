/*
a questão pedia que retirassemos o elemento anterior e o posterior a um x em uma pilha,
mantendo a pilha original inalterada.
*/
#include "alm.c"
TP * radx(TP *p, int x){
    TP *copia = TP_inicializa(), *aux = TP_inicializa(), *resp= TP_inicializa(), *lixo = TP_inicializa();
    while(!TP_vazia(p)) TP_push(aux, TP_pop(p));
    while (!TP_vazia(aux)){
        int y = TP_pop(aux);
        TP_push(p,y);
        TP_push(copia,y);
    }
    while (!TP_vazia(copia)){
        int z = TP_pop(copia);
        if (z==x){
            if (!TP_vazia(resp)) TP_push(lixo, TP_pop(resp));
            TP_push(resp,z);
            if (!TP_vazia(copia)) TP_push(lixo, TP_pop(copia));
            int q = TP_pop(resp);
            q*=-1;
            TP_push(copia,q);
        }
        else TP_push(resp, z);
    }
    while (!TP_vazia(resp)){
        int k = TP_pop(resp);
        if (k<0) k*=-1;
        TP_push(copia,k);
    }
    TP_libera(aux);
    TP_libera(resp);
    TP_libera(lixo);
    return copia;
}
int main(void){
    TP *p = TP_inicializa();
    printf("p:\n");
    int n;
    while(1){
        scanf("%d", &n);
        if(n < 0) break;
        TP_push(p, n);
    }
    printf("digite o n: ");
    scanf("%d",&n);
    TP_imprime(p);
    printf("\n");
    TP *resp = radx(p,n);
    printf("p:\n");
    TP_imprime(p);
    printf("\n");
    TP_imprime(resp);
    printf("\n");
    TP_libera(p);
    TP_libera(resp);
    return 0;
}
