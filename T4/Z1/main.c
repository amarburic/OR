#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
int main() {
    double a, b, c, x1, x2, x1Re, x2Re, x1Im, x2Im, t, D;
    
    printf("Unesite koeficijente kvadratne jednadzbe a, b, c: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    D=b*b-4*a*c;
    if(D>0){
        t=sqrt(D);
        x1=(-b-t)/(2*a);
        x2=(-b+t)/(2*a);
        printf("\nRjesenja su: x1=%f x2=%f\n",x1,x2);
    }else if(D<=EPSILON){
        x1=-b/(2*a);
        printf("Rjesenja su x1=x2=%f",x1);
    }else{
        t=sqrt(-D);
        x1Re=-b/(2*a);
        x2Re=-b/(2*a);
        x1Im=-t/(2*a);
        x2Im=t/(2*a);
        printf("\nRjesenja su: x1 = (%f,%f)\n x2=(%f,%f)",x1Re,x1Im,x2Re,x2Im);
    }
    return 0;
}