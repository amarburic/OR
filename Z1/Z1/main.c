#include <stdio.h>
#define EPSILON 0.0001
int main() {
    float a,b,c,temp;
    printf("Unesite tri realna broja: ");
    scanf("%f %f %f",&a,&b,&c);
    if(a>b){
        temp=a; /*a^=b^=a^=b;*/
        a=b;
        b=temp;
    }
    if(b>c){
        temp=b;
        b=c;
        c=temp;
    }
    if(a>b){
        temp=a;
        a=b;
        b=temp;
    }
    if(c<=0 || b<=0 || a<=0)
        printf("Brojevi moraju biti pozitivni i veci od nule");
    else if(a+b<=c)
        printf("Nije trougao");
    else if(c-a<EPSILON)
        printf("Jednakostranicni trougao");
    else if((b-a<EPSILON || c-b<EPSILON) && c*c - a*a - b*b<EPSILON)
        printf("Jednakokraki trougao\nPravougli trougao");
    else if(b-a<EPSILON || c-b<EPSILON)
        printf("Jednakokraki trougao");
    else if(c*c - a*a - b*b<EPSILON)
        printf("Pravougli trougao");
    else printf("Obicni trougao");
    return 0;
}

