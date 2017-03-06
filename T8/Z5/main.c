#include <stdio.h>
#define MAX 100

void zaokruzi(float p[],int br){
    float* q = p;
    while(q<p+br){
        *q=((int)((*q)*10+0.5))/10.;
        q++;
    }
}

int main() {
    printf("Tutorijal 8, Zadatak 5");
    return 0;
}

