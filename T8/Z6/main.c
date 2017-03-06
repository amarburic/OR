#include <stdio.h>

void sortiraj(double p[], int br){
    double* q,*r;
    double temp;
    q=p;
    while(q<p+br){
        r=q+1;
        while(r<p+br){
            if(*q>*r){
                temp=*q;
                *q=*r;
                *r=temp;
            }
            r++;
        }
        q++;
    }
}
int main() {
    return 0;
}

