#include <stdio.h>
#include <math.h>

int main() {
    int n, k = 0;
    scanf("%d", &n);
    while (k < n) {
        int c = 0;
        int x, y;
        scanf("%d %d", &x, &y);
        double z = pow(x, y);
        c = 1 + (int)floor(log10(z));
        k++;
        printf("%d\n", c);
    }
    return 0;
}