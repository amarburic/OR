#include <stdio.h>

int transformisi(int* niz, int velicina){
    /*A*/
    int i,j,k;
    for(i=0;i<velicina;i++)
        if(niz[i]>0)
            for(j=i+1;j<velicina;j++)
                if(niz[j]==-niz[i]){
                    velicina-=j-i+1;
                    for(k=i;k<velicina;k++)
                        niz[k]=niz[k+j-i+1];
                    i--;
                    break;
                }
    /*B*/
    for(i=1;i<velicina;i++)
        if(niz[i]==niz[i-1]*niz[i-1]){
            int broj=niz[i-1];
            for(j=broj+1;j<broj*broj;j++)
                if(j%2==0){
                    for(k=velicina-1;k>=i;k--)
                        niz[k+1]=niz[k];
                    niz[i]=j;
                    velicina++;
                    i++;
                }
        }
    return velicina;
    }                       

int main() {
    int niz[] = {1,5,25,-5,4,16,-5,5,-5};
    int velicina=transformisi(niz,9),i;
    for(i=0;i<velicina;i++)
        printf("%d ",niz[i]);
    return 0;
}

