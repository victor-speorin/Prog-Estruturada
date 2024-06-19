/*
verificar se os elementos que estão nas posições pares e ímpares
são pares e ímpares, respectivamente: int misc (TLSE *l)
*/
#include "TLSE.c"
int misc (TLSE *l){
    TLSE *p = l;
    int x = 1;
    while (p){
        if (x%2!=0){
            if (p->info%2==0) return 0;
        }
        else {
            if (p->info%2!=0) return 0;
        }
        p=p->prox;
        x++;
    }
    return 1;
}
int main(){
    TLSE *l = TLSE_inicializa();
    int x;
    do{
        scanf("%d", &x);
        if(x < 0) break;
        l = TLSE_ins_fim(l, x);
    }while(1);
    printf("lista og:\n");
    TLSE_imprime(l);
    printf("\n");
    x = misc(l);
    if (x) printf("sim!\n");
    else printf("nao\n");
    TLSE_lib_rec(l);
    return 0;
}