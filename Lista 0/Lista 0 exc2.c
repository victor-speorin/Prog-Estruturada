#include "stdio.h"
int main() {
    int x, t;
    do {
        printf("Digite o enesimo termo: ");
        scanf("%d", &x);
        if (x<0) return 0;
        else {
            if (x<=1) printf("1\n");
            else {
                int p = 1, s = 1;
                for (int i = 1; i < x ; i++) {
                    t = p + s;
                    p = s;
                    s = t;
                }
                printf("%d\n", t);
            }
        }
    }while(1);
    }