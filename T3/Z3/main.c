#include <stdio.h>
int main() {
    int n;
    printf("Unesite broj n: ");
    scanf("%d",&n);
    for(;n>0;n--)
        if(n%5==0 || n%7==0 || n%11==0)
            printf("%d\n",n);
    return 0;
}

