#include <stdio.h>
#define BROJ_EL 5
int main() {
    float a[BROJ_EL],b[BROJ_EL],c[BROJ_EL];
    int i;
    for(i = 0;i<BROJ_EL;i++)
    {
        printf("Unesite a%d: ",i+1);
        scanf("%f",a+i);
        printf("Unesite b%d: ",i+1);
        scanf("%f",b+i);
        c[i]=2*a[i] + b[i];
    }
    for(i=0; i<BROJ_EL;i++)
        printf("a%d: %g\n",i+1,a[i]);
    for(i=0; i<BROJ_EL;i++)
        printf("b%d: %gd\n",i+1,b[i]);
    for(i=0; i<BROJ_EL;i++)
        printf("c%d: %g\n",i+1,c[i]);
    return 0;
}

