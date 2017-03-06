#include <stdio.h>
#define BROJ_EL 10

int main() {
    int i, input, max, min;
    
    for(i = 0; i<BROJ_EL;i++)
    {
        printf("Unesite %d. cijeli broj: ",i+1);
        scanf("%d",&input);
        if(i==0)min=max=input;
        else{
            if(input<min)min=input;
            if(input>max)max=input;
        }
    }
    
    printf("Min: %d, Max:%d",min,max);
    return 0;
}

