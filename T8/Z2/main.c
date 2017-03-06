#include <stdio.h>
#define MAX 8

float maxtemp(float p[]){
    float max = p[0];
    int i;
    for(i=1;i<MAX;i++)
        if(p[i]>max)max=p[i];
    return max;
}

float prtemp(float p[]){
    float pr=0;
    int i;
    for(i=0;i<MAX;i++)
        pr+=p[i];
    return pr/MAX;
}

int main() {
    float temp[MAX];
    int i=0;
    printf("Unesite temperature:\n");
    for(i=0;i<MAX;i++)
        scanf("%f",temp+i);
    printf("Maksimalna temperatura: %g\n",maxtemp(temp));
    printf("Prosjecna temperatura: %.f\n",prtemp(temp));

    return 0;
}

