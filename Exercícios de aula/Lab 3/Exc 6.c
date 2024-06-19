/*
dados dois números N1 e N2, a cada par de N1 e N2 (ou N2 e N1),
troque-os de lugar: void troca (TLSE *l, int N1, int N2)
*/
#include "TLSE.c"
void troca (TLSE *l, int n1, int n2){
    TLSE *p1=l, *p2=l;
    int tmp;
    while (p1){
        if (p1->info==n1){ // procuro o elemento
            p2=p1->prox;
            if (!p2) break;
            while (p2->info!=n2){ // faço o auxiliar andar até o proximo elemento
                p2=p2->prox;
                if (!p2) break;
            }
            if (p2) { // se o p2 achar o elemento, troco eles e multiplico por -1 pra n achar o elemento ja trocado
                tmp = p1->info;
                p1->info = p2->info * (-1);
                p2->info = tmp * (-1);
            }
        }
        if (p1->info==n2){
            p2=p1->prox;
            if (!p2) break;
            while (p2->info!=n1){
                p2=p2->prox;
                if (!p2) break;
            }
            if (p2) {
                tmp = p1->info;
                p1->info = p2->info * (-1);
                p2->info = tmp * (-1);
            }
        }
        p1=p1->prox;
    }
    p1=l;
    while (p1){
        if (p1->info < 0) p1->info *= -1; // quem eu multipliquei por -1, multiplico de novo.
        p1=p1->prox;
    }
}
int main(void){
    TLSE *l = TLSE_inicializa();
    int x,n1,n2;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLSE_ins_fim(l, x);
    }while(1);
    printf("agora digite o N1 e N2: ");
    scanf("%d %d", &n1, &n2 );
    printf("lista og:\n");
    TLSE_imprime(l);
    printf("\n");
    troca(l,n1,n2);
    printf("lista alterada:\n");
    TLSE_imprime(l);
    printf("\n");
    TLSE_lib_rec(l);
    return 0;
}