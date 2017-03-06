#include <stdio.h>
int main() {
    int max,min,input;
    max=0;
    min=9;
    do{
        printf("Unesite broj: ");
        scanf("%d",&input);
    }while(input<=0);
    do{
        if(input%10>max)max=input%10;
        if(input%10<min)min=input%10;
        input/=10;
    }while(input!=0);
    printf("Najveca cifra je %d a najmanja je %d.",max,min);
    return 0;
}

