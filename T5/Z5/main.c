#include <stdio.h>
int main() {
    int pon[101]={0},input,i;
    printf("Unesite brojeve: \n");
    do{
        do{
            scanf("%d",&input);
            if(input<-1 || input>100)
                printf("Brojevi moraju biti izmedju 0 i 100!\n");
            }while(input<-1 || input>100);
            if(input==-1)break;
            pon[input]++;
    }while(1);
    for(i=0;i<=100;i++)
        if(pon[i])
            printf("Broj %d se javlja %d puta.\n",i,pon[i]);
    return 0;
}

