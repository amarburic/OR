#include <stdio.h>
int main() {
    int n,s,i,j;
    printf("Unesite broj n: ");
    scanf("%d",&n);
    if(n<3 || n>100 || n%2==0){
        printf("Broj je van trazenog opsega");
        return 0;
    }
    s=n/2+1;
    for(i = 0; i<s-1; i++)
        for(j=1;j<=n; j++)
        {
            if(j==s-i || j==s+i)
                printf("+");
            else 
                printf(" ");
            if(j==n)
                printf("\n");
        }
    for(i = 1;i<=n; i++)
        for(j = 1; j<=n; j++)
        {
            if(i==1 || j==1 || i==n || j==n || i==j || i+j==n+1)
                printf("+");
            else printf(" ");
            if(j==n) printf("\n");
        }
    
    return 0;
}

