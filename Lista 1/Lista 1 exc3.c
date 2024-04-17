//Entrada: a entrada contém vários casos de teste. Cada caso de teste é descrito em uma linha,
//contendo quatro números inteiros H1, M1, H2, M2, com H1:M1 representando a hora e minuto
//atuais, e H2:M2 representando a hora e minuto para os quais o alarme despertador foi
//programado (0≤H1≤23, 0≤M1≤59, 0≤H2≤23, 0≤M2 ≤59). O final da entrada é indicado por
//uma linha que contém apenas quatro zeros, separados por espaços em branco.
//Saída: para cada caso de teste da entrada seu programa deve imprimir uma linha, cada uma
//contendo um número inteiro, indicando o número de minutos que Daniela tem para dormir.

#include "stdio.h"
int main(){
    int h1, m1, h2, m2, x;
    do{
        printf("horario ");
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        if (h1==0 && m1==0 && h2==0 && m2==0) return 0;
        else if (h2>=h1 && m2>=m1) x=((h2-h1)*60) + (m2-m1);
        else if (h2>h1 && m2<m1) x=((h2-h1)*60 - (m1-m2));
        else if (h2<=h1 && m2>m1) x=(((24-(h1-h2))*60)+(m2-m1));
        else if (h2<=h1 && m2<=m1)x=(((24-(h1-h2))*60)-(m1-m2)); // (24 -(hi-hf))*60 - (mi-mf);
        printf("%d\n", x);
    }while(1);
}