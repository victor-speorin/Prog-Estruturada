//A entrada contém dados de diversos casos de teste. Cada caso de teste contém duas linhas. A
//primeira linha contém dois inteiros N e M, que indicam, respectivamente, o número de bilhetes
//originais e o número de pessoas presentes na festa (1 ≤ N ≤ 10000 e 1 ≤ M ≤ 20000). A segunda
//linha do caso de testes contém M inteiros Ti representando os números dos bilhetes contidos no
// pacote que o diretor lhe deu (1 ≤ Ti ≤ N). O final da entrada é indicado por N = M = 0. Para cada
//caso de teste seu programa deverá imprimir uma linha, contendo o número de bilhetes do pacote
//que contém outro bilhete com o mesmo número da sequência.

#include "stdio.h"
void vet_leitura(int *vet, int n){
    int i;
    for(i = 0; i < n; i++) scanf("%d", &vet[i]);
}
int main(){
    int x,y;
    do{
        scanf("%d %d", &x, &y);
        if ((x==0) && (y==0)) return 0;
        int lista[y];
        vet_leitura(lista, y);
        int c=0;
        while (x>=1){
            int resp=0;
            for (int i=0; i<y; i++){
                if (lista[i] == x) resp++;
                if (resp>1){
                    c++;
                    resp=0;
                }
                }
            x--;
        }
        printf("%d\n", c);
        }while(1);
    }