#include <stdio.h>
#define MAX 100
int main() {
    int i,j,s,a,b,mat[MAX][MAX];
    s=0;
    scanf("%d %d",&a,&b);
    for(i=0;i<a;i++)
        for(j=0;j<b;j++){
            scanf("%d",&mat[i][j]);
            if(i==0 || j==0 || i==a-1 || j==b-1)
                s+=mat[i][j];
        }
    printf("%d",s);
    return 0;
}

