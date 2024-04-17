//Escreva uma função para ordenar os caracteres de uma String,
// levando-se em consideração os seus respectivos valores na tabela ASCII.
// Se sua string for "amoR", a resposta será "Ramo". O protótipo dessa função
// é o que segue: void ordena(char *str). NÃO PODEMOS CRIAR VETORES
// E STRINGS AUXILIARES PRA RESOLVER ESSA QUESTÃO!!!

#include <stdio.h>
#include "string.h"
void ordena(char *str) {
    int j, menor;
    for (int i = 0; i < strlen(str); i++) {
        menor = i;
        for (j = i + 1; j < strlen(str); j++)
            if (str[menor] > str[j]) menor = j;
        if (menor != i) {
            int tmp = str[i];
            str[i] = str[menor];
            str[menor] = tmp;
        }
    }
}
int main() {
    char str[101];
    scanf(" %100[^\n]", str);
    ordena(str);
    printf("%s\n", str);
    return 0;
}