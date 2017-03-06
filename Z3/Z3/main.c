#include <stdio.h>
double unesi_realan(){
    int a, b;
    double d_b;
    scanf("%d %d", &a, &b);
    d_b=b;
    while((int)d_b != 0)
        d_b/=10;
    return a+d_b;
}

double izracunaj(double x, double y){
    return x*x + 2*x*y -y*y;
}

void zvjezdice(double x){
    int br_zv1,br_zv2,i;
    br_zv1=((int)x)%10;
    br_zv2=((int)(x*10))%10;
    for(i=0;i<br_zv1;i++)
        printf("*");
    printf("\n");
    for(i=0;i<br_zv2;i++)
        printf("*");
}

#include <stdio.h>
int main() {
	double x=unesi_realan();
	double y=unesi_realan();
	zvjezdice(izracunaj(x,y));
	return 0;
}
