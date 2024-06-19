/*
verificar se os elementos que estão nas posições pares e
ímpares são pares e ímpares, respectivamente: int misc (TLSE *l) (RECURSIVA!!)
*/
#include "TLSE.c"

int rec (TLSE *l, int x){
    if (!l) return 1;
    if (x%2!=0){
        if (!(l->info%2)) return 0;
    }
    else {
        if (l->info%2) return 0;
    }
    rec(l->prox,x+1);
}

int misc (TLSE *l){
    int x = rec(l,1);
    return x;
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