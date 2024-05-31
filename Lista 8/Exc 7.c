/*
Refaça Q6, alterando a lista passada como parâmetro. O protótipo desta função é o
seguinte: void i_p (TLSE *l).
*/
#include "stdio.h"
#include "TLSE.c"
void i_p (TLSE *l){
    TLSE *p =l;
    int tam = 0,pr=0,ip=0;
    for (; p; p = p->prox) { // encontro o tamanho da lse e o numero de impares e pares
        tam++;
        if (p->info%2==0) pr++;
        else ip ++;
    }
    p=l;
    int vet[tam], x=0;
    for (int i=0;i<tam;i++){
        if (p->info%2!=0) {
            vet[x] = p->info; // crio um vetor que vai me auxiliar e coloco primeiro os impares nele
            x++;
        }
        p=p->prox;
    }
    p=l;
    for (int i=0;i<tam;i++) {
        if (p->info % 2 == 0) {
            vet[ip] = p->info; // agora coloco os pares no vetor
            ip++;
        }
        p = p->prox;
    }
    p=l;
    for (int i=0;i<tam;i++){
        p->info = vet[i]; // agora é só colocar o vetor indice a indice na lse
        p=p->prox;
    }
}
int main(){
    TLSE *l = TLSE_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if (x<0) break;
        l = TLSE_ins_ini(l, x);
    }while(1);
    printf("lista og:\n");
    TLSE_imp_rec(l);
    printf("\n");
    i_p(l);
    printf("lista resposta:\n");
    printf("\n");
    TLSE_imp_rec(l);
    TLSE_lib_rec(l);
    return 0;
}