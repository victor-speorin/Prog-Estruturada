/*
Considere a existência de uma estrutura que representa um ponto no espaço 2D. Escreva
uma função que indique se um ponto p está dentro de um retângulo, retornando um e, zero, caso
contrário. O retângulo é definido com dois vértices: o inferior esquerdo e o superior direito. O
protótipo desta função é o seguinte: int dentroRet (TPTO2D *inf, TPTO2D *sup,
TPTO2D *p).
*/
#include "stdio.h"
typedef struct ponto{
    float x, y;
}TPTO2D;
int dentroRet (TPTO2D *inf, TPTO2D *sup, TPTO2D *p){
    if ((p->x >= inf->x && p->x <= sup->x) && (p->y >= inf->y && p->y <= sup->y)) return 1;
    return 0;
}
int main(){
    TPTO2D inf, sup, p;
    printf("digite as coordenadas inferiores do retangulo:\n");
    scanf("%f", &inf.x);
    scanf("%f", &inf.y);
    printf("digite as coordenadas superiores do retangulo:\n");
    scanf("%f",&sup.x);
    scanf("%f",&sup.y);
    printf("digite as coordendas do P:\n");
    scanf("%f",&p.x);
    scanf("%f",&p.y);
    int x = dentroRet(&inf,&sup,&p);
    if (x) printf("esta dentro.");
    else printf("fora!");
    return 0;
}