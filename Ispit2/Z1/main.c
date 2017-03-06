#include <stdio.h>
int maxprost(int *niz, int vel);
int main() {
    int niz[6] = {1,2,3,5,7,12};
    printf("%d", maxprost(niz,6));
    return 0;
}

int maxprost(int* niz, int vel){
    int i, j, je_prost, maxprost=0;
    for(i = 0; i < vel; i++){
        if(niz[i]<=1)
            continue;
        je_prost=1;
        for(j = 2; j<niz[i]; j++)
            if(niz[i]%j==0){
                je_prost=0;
                break;
            }
        if(je_prost && niz[i]>maxprost)
            maxprost = niz[i];
    }
    return maxprost;
}

