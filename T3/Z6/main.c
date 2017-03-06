#include <stdio.h>
#include <math.h>
int main() {
    int n,i,b=0;
    printf("Unesite broj: ");
    scanf("%d",&n);
    if(n<=0)
        printf("Broj nije prirodan");
    else if(n==1)
        printf("Broj nije ni prost ni slozen");
    else{
        for(i=(int)sqrt(n);i>=2;i--)
        {
            if(n%i==0)
            {
                printf("Broj je slozen");
                b=1;
                break;
            }
        }
        if(!b)
            printf("Broj je prost");
    }
    return 0;
}

