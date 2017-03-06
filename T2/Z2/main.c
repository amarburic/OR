#include <stdio.h>
#define NSP1 65.0
#define NSP2 90.0
#define NDP1 105.0
#define NDP2 140.0
#define NP1 65
#define NP2 80
int main() {
    float SP,DP,P;
    printf("Unesite sistolicki, dijastolicki pritisak i puls: ");
    scanf("%f %f %f",&SP,&DP,&P);
    printf("\nSP: ");
    if(SP>NSP1 && SP<NSP2)
        printf("normalan");
    else
        printf("nije normalan");
    printf("\nDP: ");
    if(DP>NDP1 && DP<NDP2)
        printf("normalan");
    else
        printf("nije normalan");
    printf("\nP: ");
    if(P>NP1 && P<NP2)
        printf("normalan");
    else
        printf("nije normalan");
    return 0;
}

