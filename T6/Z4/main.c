#include <stdio.h>
#define DIM 10
int main() {
    int i,j,m[DIM][DIM],min;
    min=0;
    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++){
            scanf("%d",&m[i][j]);
            if(i==j && (i==0 || min>m[i][j]))
                min=m[i][j];
        }
    printf("%d",min);
    return 0;
}

