#include <stdio.h>
#define DIM 10
int main() {
    int max,min,minr,maxr,mat[DIM][DIM],i,j,temp;
    max=min=maxr=minr=0;
    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++){
            scanf("%d",&mat[i][j]);
            if((i==0 && j==0) || min>mat[i][j]){
                min=mat[i][j];
                minr=i;
            }
            if((i==0 && j==0) || max<mat[i][j]){
                max=mat[i][j];
                maxr=i;
            }
            
        }
    if(maxr==minr){
        printf("Max i min su u istom redu.\n");
        return 0;
    }
    for(j=0;j<DIM;j++){
        temp=mat[maxr][j];
        mat[maxr][j]=mat[minr][j];
        mat[minr][j]=temp;
    }
    for(i = 0;i<DIM;i++)
        for(j=0;j<DIM;j++){
            printf("%d ",mat[i][j]);
            if(j==DIM-1)printf("\n");
        }
    return 0;
}

