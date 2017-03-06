#include <stdio.h>
int main() {
    int m,g;
    printf("Unesite mjesec: ");
    scanf("%d",&m);
    printf("Unesite godinu: ");
    scanf("%d",&g);
    switch(m){
        case 1:
        printf("Januar");
        break;
        case 2:
        printf("Februar");
        break;
        case 3:
        printf("Mart");
        break;
        case 4:
        printf("April");
        break;
        case 5:
        printf("Maj");
        break;
        case 6:
        printf("Juni");
        break;
        case 7:
        printf("Juli");
        break;
        case 8:
        printf("Avgust");
        break;
        case 9:
        printf("Septembar");
        break;
        case 10:
        printf("Oktobar");
        break;
        case 11:
        printf("Novembar");
        break;
        case 12:
        printf("Decembar");
        break;
    }
    if(m!=2)
        printf(" %d, broj dana: %d",g,(m<=7 && m%2==1 || m>=8 && m%2==0)?(31):(30));
    else printf(" %d, broj dana: %d",g,(g%4==0)?(29):(28));
    
    return 0;
}

