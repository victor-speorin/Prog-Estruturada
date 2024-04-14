#include <stdio.h>
#include <math.h>
int main(){
    int x;
    printf("deseja fazer quantas vezes?");
    scanf("%d", &x);
    for (int i=0; i<x; i++){
        float pa, pb, ca, cb;
        printf("digite as duas pop seguidas das taxas de crescimento.");
        scanf("%f %f %f %f", &pa, &pb, &ca, &cb);
        int a=0;
        while (pa<=pb){
            pa = pa + ((ca/100)*pa);
            pb = pb + ((cb/100)*pb);
            pa = floor(pa);
            pb = floor(pb);
            a++;
        }
        if (a>100) printf("mais de 1 seculo");
        else printf("%d\n", a);
    }

    return 0;
}
