/*(e) escreva uma função que, dada uma pilha p, retorne uma fila, contendo todos os elementos
de p, e obedecendo a ordem de entrada dos inteiros em p, isto é, o primeiro inteiro que sair da
pilha p deve ser o primeiro inteiro a sair da fila. Não é possível alterar a ordem dos elementos
da pilha de entrada. A função deve obedecer o seguinte protótipo: TFila* p2f (TPilha *p).*/

#include"alm.c"

TF* p2f (TP *p){
    TF *f = TF_inicializa();
    while (!TP_vazia(p)) TF_insere(f, TP_pop(p));
    return f;
}

int main() {
    TP *p = TP_inicializa();
    printf("p:\n");
    int n;
    while (1) {
        scanf("%d", &n);
        if (n < 0) break;
        TP_push(p, n);
    }
    printf("pilha og:\n");
    TP_imprime(p);
    printf("\n");
    TF *f = p2f(p);
    printf("fila resposta:\n");
    TF_imprime(f);
    printf("\n");
    TP_libera(p);
    TF_libera(f);
    return 0;
}