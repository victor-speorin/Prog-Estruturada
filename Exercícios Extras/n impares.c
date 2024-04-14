#include <stdio.h>
int main(){
    int n;
    printf("insira um numero: ");
    scanf("%d", &n);
    int u = (n*(n-1))+1;
    int x = 0;
    while (x<n){
        if (u%2==1) {                  //= if (u%2)
            printf("%d\n", u);
            u++;
            x++;
        }
        else u++;
    }
    return 0;
}