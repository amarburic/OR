#include <stdio.h>

int Pascal(int x, int y){
    if(x==1 || x==y)return 1;
    return Pascal(x,y-1)+Pascal(x-1,y-1);
}

int main() {
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++)
            printf("%d ",Pascal(j,i));
        printf("\n");
    }
    return 0;
}

