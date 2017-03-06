#include <stdio.h>
#define MAX 10
int main() {
    int a[MAX],b[MAX],c[2*MAX];
    int i,n1,n2;
    printf("Unesite elemente niza A: ");
    for(i=0;i<MAX;i++){
        scanf("%d",a+i);
        if(a[i]==-1){
            i--;
            break;
        }
    }
    n1=i;
    printf("Unesite elemente niza B: ");
    for(i=0;i<MAX;i++){
        scanf("%d",b+i);
        if(b[i]==-1)
            break;
    }
    n2=i;
    for(i=0;i<n1+n2;i++){
        if(i<n1)
            c[i]=a[i];
        else
            c[i]=b[i-n1];
    }
    printf("Niz C glasi: ");
    for(i=0;i<n1+n2;i++)
        printf("%d ",c[i]);
    return 0;
}

