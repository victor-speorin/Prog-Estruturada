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