#include <stdio.h>
#define LB -10.
#define UB 10.
int main() {
float a,b,c,x;
printf("Unesite koeficijente a, b i c: ");
scanf("%f %f %f",&a,&b,&c);
printf("Unesite tacku x: ");
scanf("%f",&x);
if(!(a>LB && a<UB && b>LB && b<UB && c>LB && c<UB))
printf("Koeficijenti nisu u zadanom rasponu");
else
printf("Prva derivacija u tacki x=%g je %g.",x,2*a*x + b);
return 0;
}

