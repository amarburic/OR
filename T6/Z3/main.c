#include <stdio.h>
#define MAX 100
int main() {
    int niz[MAX],i,j,n,x;
    printf("Unesite elemente niza: ");
    for(i = 0;i<MAX;i++)
    {
        scanf("%d",niz + i);
        if(niz[i]==-1)break;
    }
    n=i;
    printf("Unesite element koji treba izbaciti: ");
    scanf("%d",&x);
    for(i = n-1; i>=0;i--){
        if(niz[i]==x){
            for(j=i;j<n-1;j++)
                niz[j]=niz[j+1];
            n--;
        }
    }
    printf("Novi niz glasi: ");
    for(i=0;i<=n-1;i++){
        
        printf("%d",niz[i]);
        if(i!=n-1)printf(",");
    }
    return 0;
}

