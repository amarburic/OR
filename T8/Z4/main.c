#include <stdio.h>
#define MAX 100

int drugi(int p[],int br){
    int first, second, isecond,i;
    first=p[0];
    for(i=0;i<br;i++)
        if(first<p[i])
            first=p[i];
    second=p[0];
    for(i=0;i<br;i++)
        if(second>p[i])
            second=p[i];
    isecond=-1;
    for(i=0;i<br;i++)
        if(second<=p[i] && p[i]<first){ 
            second=p[i];
            isecond=i;
        }
    return isecond;
}

int main() {
    int niz[MAX],i=-1;
    printf("Unesite niz brojeva: ");
    do{
        scanf("%d",&niz[++i]);
    }while(niz[i]!=-1);
    printf("Indeks drugog po velicini je: %d",drugi(niz,i));
    return 0;
}

