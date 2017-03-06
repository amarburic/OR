#include <stdio.h>
#define MAX 100
int main() {
    int cifre[10]={0},i,input,prvi;
    char c;
    printf("Unesite brojeve: \n");
    for(i = 0; i<MAX; i++)
    {
        if(!scanf("%d",&input)){
            while((c=getchar())!=' ' && c!='\n'); 
            continue;
        }
        if(input<1)break;
        do{
            cifre[input%10]++;
            input/=10;
        }while(input!=0);
    }
    printf("Cifre: ");
    prvi=0;
    for(i = 0; i<10; i++)
        if(cifre[i]){
            if(prvi)printf(",");
            else prvi++;
            printf("%d",i);
        }
    printf(".");
    return 0;
}

