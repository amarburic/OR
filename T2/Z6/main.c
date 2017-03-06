#include <stdio.h>
int main() {
    float a,b,c,d;
    scanf("%f %f %f %f",&a,&b,&c,&d);
    if(a>c && b<d)
    printf("Skup S1 je sadrzan u skupu S2");
    else if(a<c && b>d)
    printf("Skup S2 je sadrzan u skupu S1");
    else
    {
        if(a>c)
        {
            float temp = c;
            c=a;
            a=temp;
            temp=b;
            b=d;
            d=temp;
        }
        if(b<c)
        printf("Skupovi nemaju presjeka");
        else 
        printf("Presjek skupova je [%g,%g]",c,b);
    }
    return 0;
}

