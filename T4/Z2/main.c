#include <stdio.h>
int main() {
    int a,b,i,j;
    printf("Unesite stranice pravougaonika a,b: ");
    scanf("%d,%d",&a,&b);
    for(j=1;j<=b;j++)
    {
        for(i=1;i<=a;i++)
        {
            if((i==1 || i==a) && (j==1 || j==b))
                printf("+");
            else if(i==1 || i==a)
                printf("|");
            else if(j==1 || j==b)
                printf("-");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}

