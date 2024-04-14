#include "stdio.h"
int main(){
    int h1, m1, h2, m2, x;
    do{
        printf("fala o horario ai dani dani");
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        if (h1==0 && m1==0 && h2==0 && m2==0) return 0;
        else if (h2>=h1 && m2>=m1) x=((h2-h1)*60) + (m2-m1);
        else if (h2>h1 && m2<m1) x=((h2-h1)*60 - (m1-m2));
        else if (h2<=h1 && m2>m1) x=(((24-(h1-h2))*60)+(m2-m1));
        else if (h2<=h1 && m2<=m1)x=(((24-(h1-h2))*60)-(m1-m2)); // (24 -(hi-hf))*60 - (mi-mf);
        printf("%d\n", x);
    }while(1);
}