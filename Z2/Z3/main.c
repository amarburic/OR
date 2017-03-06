#include <stdio.h>
#include <math.h>
#define MAX 100
#define EPSILON 0.1

int eq(float a, float b){
    return fabs(a-b)<0.0001;
}

int main() {
    float matrica[MAX][MAX],input,msred,vsred;
    int n,m,i,j,k,del[MAX]={0};
    i=j=0;
    msred=0;
    n=m=0;
    printf("Unesite matricu:\n");
    
    do{                                                                         /*unos i provjera validnosti*/
        do{
            scanf("%f",&input);
            if(input<0 && !(eq(input,-1) || eq(input,-2)))printf("Greska\n");
        }while(input<0 && !(eq(input,-1) || eq(input,-2)));
        if(j>0 && ((eq(input,-1) || eq(input,-2)) && i!=n)){
            printf("Ovo nije matrica!");
            return 0;
        }
        if(eq(input,-1))
        {
            if(j==0)n=i;
            j++;
            i=0;
        }
        else if(eq(input,-2)){
            m=j+1;
            break;
        }else{
            matrica[j][i]=input;
            i++;
        }
        }while(1);
        
    
    for(j = 0; j<m; j++)                                                        /*racunanje srednje vrijednosti*/
        for(i = 0; i<n; i++)                                                
            msred+=matrica[j][i];
    msred/=m*n;
    
    for(j = 0; j<m; j++){
     vsred=0;
        for(i = 0; i<n; i++)
            vsred+=matrica[j][i];
     vsred/=n;
     if(eq(vsred,msred))
        del[j]++;
        
    }
    
    for(i = m-1; i>=0; i--){                                                    /*brisanje redova*/
        if(del[i]){
            for(j=i+1;j<m;j++)
                for(k=0;k<n;k++)
                    matrica[j-1][k]=matrica[j][k];
        m--;
        }
    }
    printf("Nakon izbacivanja redova matrica glasi: \n");                       /*ispis*/
    for(j=0; j<m;j++)
    {
        for(i = 0; i<n; i++)
            printf("%5g",matrica[j][i]);
        printf("\n");
    }
    return 0;
}

