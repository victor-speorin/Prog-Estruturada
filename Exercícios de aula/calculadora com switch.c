#include "stdio.h"
int main(){
    int x,y,z;
    char meio;
    do {
        scanf("%d %c %d", &x, &meio, &y);
        switch (meio) {
            case 'q': return 0;
            case 'Q': return 0;
            case '+': z = x + y; break;
            case '-': z = x - y; break;
            case '*': z = x * y; break;
            case '/':
                if (!y) {
                    printf("invalido\n");
                    continue;
                }
                else z=x/y; break;
            default :
                printf("invalido\n");
                continue;
        }
        printf("%d %c %d = %d\n", x, meio, y, z);
    }while(1);
    }
