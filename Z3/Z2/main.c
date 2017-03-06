#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001

double ln1x(double x, int n){
    double stepen=1,suma=0;
    int i; 
    if(x<=-1 || x>=1 || n<1)return 0;
    for(i=1;i<=n;i++){
        stepen*=x;
        suma+=((i%2)?(1):(-1))*stepen/i;
    }
    return suma;
}

int main() {
    double x,moja_funkcija,bibliotecna,razlika;
    int n;
    do{
        printf("Unesite broj x: ");
        scanf("%lf",&x);
        if(x<=-1 || x>=1)
            printf("Greska.\n");
    }while(x<=-1 || x>=1);
    do{
        printf("Unesite broj n: ");
        scanf("%d",&n);
        if(n<1)
            printf("Greska.\n");
    }while(n<1);
    moja_funkcija=ln1x(x,n);
    bibliotecna=log(1+x);
    if(fabs(bibliotecna)<EPSILON)razlika=0;
    else razlika=((moja_funkcija-bibliotecna)*100)/bibliotecna;
    printf("Funkcija ln1x: %.6f\n",moja_funkcija);
    printf("Bibliotecna funkcija: %.6f\n",bibliotecna);
    printf("Razlika u postotcima: %.2f%%",razlika);
    
    return 0;
}

