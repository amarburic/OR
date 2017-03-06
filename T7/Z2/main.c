#include <stdio.h>
long long Faktorijel(int n){
    if(n==1 || n==0)return 1;
    else return n*Faktorijel(n-1);
}

int main() {
    int n,i;
    float x,suma;
    printf("Unesite broj n u intervalu [1, 12]: ");
    scanf("%d",&n);
    printf("Unesite realan broj x: ");
    scanf("%f",&x);
    suma=0;
    for(i=1;i<=n;i++)
        suma+=1./Faktorijel(i);
    suma*=x;
    printf("Suma od 1 do %d za x = %.3f je %.3f",n,x,suma);
    return 0;
}

