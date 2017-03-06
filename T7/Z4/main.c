#include <stdio.h>
int obrnut(int x){
    int ret=0;
    do{
        ret*=10;
        ret+=x%10;
        x/=10;
    }while(x!=0);
    return ret;
}
int main() {
    int input;
    scanf("%d",&input);
    printf("%d",obrnut(input));
    return 0;
}

