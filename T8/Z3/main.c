#include <stdio.h>
#define MAX 100

float maxtemp(float p[],int br){
    float max = p[0];
    int i;
    for(i=1;i<br;i++)
        if(p[i]>max)max=p[i];
    return max;
}

float prtemp(float p[],int br){
    float pr=0;
    int i;
    for(i=0;i<br;i++)
        pr+=p[i];
    return pr/br;
}
 
int main() {
    float temp[MAX];
    int i=-1;
    printf("Unesite temperature:\n");
    do{
        scanf("%f",&temp[++i]);
    }while(temp[i]!=-1);
    printf("Maksimalna temperatura: %g\n",maxtemp(temp,i));
    printf("Prosjecna temperatura: %.f\n",prtemp(temp,i));

    return 0;
}

