#include <stdio.h>
int main(){
    float x;
    printf("digite seu salario bruto: ");
    scanf("%f", &x);
    float xx = x;
    if (x<=1499.14)
        printf("nao tem desconto");
    else if (1499.15<=x && x<=2246.75) {
        x = x * 0.075;
        x = x - 112.44;
        xx = xx - x;
        printf("%.2f", xx);
    }
    else if (2246.76<=x && x<=2995.70){
        x = x * 0.15;
        x = x - 280.94;
        xx = xx - x;
        printf("%.2f", xx);
    }
    else if (2995.71<=x && x<=3743.19){
        x = x * 0.225;
        x = x - 506.62;
        xx = xx - x;
        printf("%.2f", xx);
    }
    else{
        x = x * 0.275;
        x = x - 692.78;
        xx = xx - x;
        printf("%.2f", xx);
    }
    return 0;
}