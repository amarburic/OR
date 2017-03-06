#include <stdio.h>

void zamijeni(double* a,double* b){ 
    double temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main() {
    printf("Tutorijal 8, Zadatak 7");
    return 0;
}

