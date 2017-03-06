#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int vl,guess;
    srand(time(NULL));
    vl=rand()%100+1;
    printf("Izabrao sam broj. Probaj ga pogoditi (-1 za izlaz).\n\n");
    do{
        printf("Unesite broj: ");
        scanf("%d",&guess);
        if(guess==-1) break;
        else if(guess<vl)
            printf("VECI\n");
        else if(guess>vl)
            printf("MANJI\n");
        else printf("JEDNAK\n");
    }while(guess!=vl);
    printf("Kraj igre.");
    return 0;
}

