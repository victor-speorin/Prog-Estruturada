/*
Refaça Q6, alterando a lista passada como parâmetro. O protótipo desta função é o
seguinte: void i_p (TLC *l).
*/
#include "TLC.c"

TLC * descola (TLC*l, TLC *ult){
    TLC *aux = l;
    while (aux != ult){
        aux->info = aux->prox->info;
        aux = aux->prox;
    }
    return l;
}

void i_p (TLC *l){
    TLC *p=l, *ult = l;
    int ver=1;
    while (ult->prox!=l) {
        ult = ult->prox; // coloco um ponteiro no final
        ver++;
    }
    while (ver){
        if (!(p->info%2)){ // toda vez que acho um par, desloco a lista para esquerda e coloco ele no final
            int x = p->info;
            p= descola(p,ult);
            ult->info=x;
            ver--;
        }
        else {
            p=p->prox;
            ver--;
        }
    }
}
int main(){
    TLC *l = NULL;
    int n;
    do{
        scanf("%d", &n);
        if(n < 0) break;
        l = TLC_insere(l, n);
    }while(1);
    printf("lista og:\n");
    TLC_imprime(l);
    printf("\n");
    i_p(l);
    printf("lista resposta:\n");
    TLC_imprime(l);
    TLC_libera(l);
    return 0;
}