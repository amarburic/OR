#include <stdio.h>
#define MAX 10
int main() {
    int i,j,k;
    for(j=0;j<=MAX;j++)
    {
        for(i=0;i<=MAX;i++)
        {
            if(i==0 && j==0)
                printf("  X |");
            else if(i==0)
                printf("%3d |",j);
            else if(j==0)
                printf("%4d",i);
            else printf("%4d",i*j);
        }
        printf("\n");
        if(j==0)
            for(k=0;k<=MAX;k++)
            {
                printf("----");
                if(k==0)
                    printf("+");
                if(k==MAX)
                    printf("\n");
            }
    }
    return 0;
}

