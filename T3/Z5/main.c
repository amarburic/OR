#include <stdio.h>
int main() {
    int n,i;
    double s=0;
    printf("Unesite broj n: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(i%2==0)
            s-=1./i;
        else
            s+=1./i;
    }
    printf("Koristeci %d clanova suma je %.3f",n,s);
    return 0;
}

