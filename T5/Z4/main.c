#include <stdio.h>
int main() {
    int i,j,k,input;
    i=j=k=0;
    printf("Unesite brojeve: \n");
    do{
        scanf("%d",&input);
        if(input%5==0)i++;
        if(input%7==0)j++;
        if(input%11==0)k++;
    }while(input!=-1);
    printf("Djeljivih sa 5: %d\n",i);
    printf("Djeljivih sa 7: %d\n",j);
    printf("Djeljivih sa 11: %d\n",k);
    return 0;
}

