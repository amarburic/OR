#include <stdio.h>
int main() {
    int a,b,c,i;
    i=0;
    printf("Unesite brojeve (0 za kraj):\n");
    scanf("%d\n%d\n%d",&a,&b,&c);
    do{
        if(b==a-c)i++;
        a=b;
        b=c;
        scanf("%d",&c);
    }while(c!=0);
    
    if(i==0)
    printf("Niti jedan clan niza ne zadovoljava uslov.");
    else if(i%10>=2 && i%10<=4 && (i/10)%10!=1)
    printf("%d clana niza zadovoljava uslov.",i);
    else if(i%10==1 && (i/10)%10!=1)
    printf("%d clan niza zadovoljava uslov.",i);
    else
    printf("%d clanova niza zadovoljava uslov.",i);
    return 0;
}

