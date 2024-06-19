/*
Escreva uma função recursiva para comparar uma parte de duas strings.
 Sua função recebe os dois índices e as duas strings, e retorna os seguintes valores:
0, s1 = s2, [i1, i2]
1, s1 > s2, [i1, i2]
-1, caso contrário.
Pode ser informado i1 > i2. Seu programa deve passar
como terceiro (quarto) parâmetro, o menor (maior) índice: int f(char *s1, char *s2, int i1, int i2);
*/
#include "stdio.h"
int maior(int i1, int i2){
    if(i1>i2) return i1;
    return i2;
}
int menor(int i1, int i2){
    if (i1>i2) return i2;
    return i1;
}
int f(char *s1, char *s2, int i1, int i2){
    if (i1>i2) return 0;
    if (s1[i1]==s2[i1]) return f(s1,s2,i1+1,i2) + 0;
    if (s1[i1]>s2[i1]) return f(s1,s2,i1+1,i2) + s1[i1];
    if (s1[i1]<s2[i1]) return f(s1,s2,i1+1,i2) - s2[i1];
}
int main(){
    int i1,i2;
    printf("digite os indices: ");
    scanf("%d %d", &i1, &i2);
    char str1[100], str2[100];
    printf("string 1: "); scanf("%s",str1);
    printf("string 2: "); scanf("%s",str2);
    i1 = menor(i1,i2);
    i2 = maior(i1,i2);
    int z = f(str1,str2,i1,i2);
    if (!z) printf("0");
    else if (z>0) printf("1");
    else printf("-1");
    return 0;
}