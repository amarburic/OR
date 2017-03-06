#include <stdio.h>
#include <math.h>
long long faktorijel(int n){
    if(n==1 || n==0)return 1;
    else return n*faktorijel(n-1);
}

double sinus(double x, int n){
    int i;
    double ret;
    ret=0;
    for(i=1;i<=n;i++)
        ret+=((i%2)?(1):(-1))*pow(x,2*i-1)/faktorijel(2*i-1);
    return ret;
}

int main() {
    int n;
    double x;
    scanf("%d %lf",&n,&x);
    printf("sin(%g)=%g,sinus(%g,%d)=%g",x,sin(x),x,n,sinus(x,n));
    return 0;
}

