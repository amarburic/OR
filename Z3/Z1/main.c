#include <stdio.h>

int iste_cifre(int a, int b){
    int cifre_a[10]={0},cifre_b[10]={0},i;
    if(a<0)a=-a;
    if(b<0)b=-b;
    do{
        if(!cifre_a[a%10])cifre_a[a%10]++;
        a/=10;
    }while(a!=0);
    do{
        if(!cifre_b[b%10])cifre_b[b%10]++;
        b/=10;
    }while(b!=0);
    for(i=0;i<10;i++)
        if(cifre_a[i] ^ cifre_b[i]) return 0;
    return 1;
}

int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",iste_cifre(a,b));
    return 0;
}

