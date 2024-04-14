#include <stdio.h>
int main(){
    int cont=0, y=1, x;
    printf("Digite um numero: ");
    scanf("%d", &x); // escolhendo o numero
    int xx = x;
    while (y<x){    // vai dividir por todos os numeros até o anterior dele
        if (x%y==0){
            cont++;
        }
        y++;
    }
    if (cont==1) {
        printf("este numero eh primo");
        x++;
        y = 1;
        int coco = 0;
        int c2 = 0;
        while (c2<2){
            while (y<x){
                if (x%y==0) coco++;
                y++;
            }
            if (coco==1) {
                c2++;
                printf("\n%d", x);
            }
            x++;
            y=1;
            coco = 0;
        }
        }
    if (cont==1) {
        xx--;
        y = 1;
        int coco = 0;
        int c2 = 0;
        while (c2<2){
            while (y<xx){
                if (xx%y==0) coco++;
                y++;
            }
            if (coco==1) {
                c2++;
                printf("\n%d", xx);
            }
            xx--;
            y=1;
            coco = 0;
        }
    }
    else printf("esse numero nao eh primo otario achou que ia foder meu codigo");
    return 0;
}