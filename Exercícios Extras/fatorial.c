#include <stdio.h>
int main(){
    int x;
    printf("informe um numero e direi o fatorial: ");
    scanf("%d", &x);
    int xx=x;
    for (int i=1;i<xx;i++){
        x = x*i;
    }
    printf("%d", x);
    return 0;
}
