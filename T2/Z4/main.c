#include <stdio.h>
#define LB 50
#define UB 200
int main() {
    int a,b,c,temp;
    printf("Unesite tri broja: ");
    scanf("%d %d %d",&a,&b,&c);
    if(!(a>LB && a<UB && b>LB && b<UB && c>LB && c<UB))
    {
        printf("Svi brojevi nisu iz intervala 50 do 200");
        return 0;
    }
    if(a>b) 
    {
        temp=a;
        a=b;
        b=temp;
    }
    if(b>c)
    {
        temp=b;
        b=c;
        c=temp;
    }
    if(a>c)
    {
        temp=a;
        a=c;
        c=temp;
    }
    printf("Brojevi poredani po veličini glase: %d,%d,%d\n",a,b,c);
    if(a==c)
    printf("Unesen je 1 broj.\n");
    else if(a==b || b==c)
    printf("Unesena su 2 različita broja.\n");
    else 
    printf("Unesena su 3 različita broja.\n");    
    return 0;
}

