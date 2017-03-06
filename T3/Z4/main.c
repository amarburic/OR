#include <stdio.h>
int main() {
    int n,i,j;
    printf("Unesite broj n: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){    
        for(j=1;j<=n;j++){
            if(i%2==0)
                printf(" *");
            else
                printf("* ");
        }
        printf("\n");
    }       
return 0;
}

