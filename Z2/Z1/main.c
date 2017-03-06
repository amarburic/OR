#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAZMAK 100
#define MAX 1000

int dani[]={31,29,31,30,31,30,31,31,30,31,30,31};

int prestupna(int g){
    return g%4==0 && !(g%100==0 && g%400!=0);
}

int ispravan(int d, int m, int g){
    time_t vrijeme = time(NULL);                                                /*source:stackoverflow.com*/
    struct tm *vrijemeinfo = localtime(&vrijeme);                               /*source:stackoverflow.com*/
    if(d<1 || d>31)return 0;
    if(m<1 || m>12)return 0;
    if(g<1 || g>vrijemeinfo->tm_year+1900)return 0;
    if(d>dani[m-1])return 0;
    if(m==2 && !prestupna(g) && d>28)return 0;
    if(g==vrijemeinfo->tm_year+1900 && m>vrijemeinfo->tm_mon+1)return 0;
    if(g==vrijemeinfo->tm_year+1900 && m==vrijemeinfo->tm_mon+1 && d>vrijemeinfo->tm_mday)return 0;
    return 1;
}

int dana(int d, int m ,int g){
    int s,i;
    s=0;
    s+=(g-1)*365 + (g-1)/4 - (g-1)/100 + (g-1)/400;
    for(i=0;i<m-1;i++){
        s+=dani[i];
        if(i==1 && !prestupna(g))
            s--;
    }
    s+=d;
    return s;
}

int main() {
    int n,d,m,g,i,j,bl,pos;
    int niz[MAX];
    short parovi[MAX*MAX/4][2];  
    pos=0;
    do{
        printf("Unesite broj studenata: ");
        bl=scanf("%d",&n);
        while(getchar()!='\n');
        if(n<1 || n>MAX || bl!=1)printf("Neispravan broj studenata\n");
    }while(n<1 || n>MAX || bl!=1);
    for(i = 0; i<n; i++){
        do{
            printf("Unesite datum rodjenja %d. studenta: ",i+1);
            bl = scanf("%d,%d,%d",&d,&m,&g);
            while(getchar()!='\n');
            if(!ispravan(d,m,g) || bl<3)printf("Neispravan datum\n");
        }while(!ispravan(d,m,g) || bl<3);
        niz[i]=dana(d,m,g);
        for(j=i-1;j>=0;j--){
            if(abs(niz[j]-niz[i])==RAZMAK)
            {   
                if(niz[j]<niz[i]){
                    parovi[pos][0]=j+1;
                    parovi[pos][1]=i+1;
                }
                else{
                    parovi[pos][0]=i+1;
                    parovi[pos][1]=j+1;
                }
                pos++;
            }
        }
    }
    for(i=0;i<pos;i++)
        printf("Student %d. je rodjen tacno 100 dana prije studenta %d.\n",(int)parovi[i][0],(int)parovi[i][1]);
    return 0;
}

