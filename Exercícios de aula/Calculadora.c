#include "stdio.h"
int main(){
    int x,y,z;
    char meio;
    do{
        scanf("%d %c %d", &x, &meio, &y);
        if ((meio=='q') || (meio=='Q')) return 0;
        else if (meio=='+') z=x+y;
        else if (meio=='-') z=x-y;
        else if (meio=='/'){
            if (!y) {
                printf("invalido\n");
                continue;
            }
            else z=x/y;
        }
        else if (meio=='*') z=x*y;
        else if (meio=='%') z=x%y;
        else {
            printf("invalido\n");
            continue;
        }
        printf("%d %c %d = %d\n", x, meio, y, z);
    }while(1);
}