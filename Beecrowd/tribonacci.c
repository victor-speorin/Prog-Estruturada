#include <stdio.h>
int main() {
    int x;
    while (scanf("%d", &x) != EOF) {
        long long int p = 1, s = 1, t, c = 0, copiat;
        while (c < x) {
            copiat = 0;
            t = p + s;
            copiat += t;
            if (copiat % 3 == 0) c++;
            else {
                while (copiat > 0) {
                    if (copiat % 10 == 3) {
                        c++;
                        break;
                    }
                    copiat /= 10;
                }
            }
            p = s;
            s = t;
        }
        printf("%lld\n", t);
    }
    return 0;
}