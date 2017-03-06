#include <stdio.h>
#define PI 3.14

int main()
{
    float R, P, V, A;

    printf ("Unesite poluprecnik:");
    scanf ("%f", &R);
    P=(R*R)*PI;
    A=4*(R*R)*PI;
    V=(4./3)*R*R*R*PI;

    printf("\n Povrsina kruga sa poluprecnikom %2f je %.2f", R,P);
    printf("\n Povrsina lopte sa poluprecnikom %2f je %.2f", R,A);
    printf("\n Zapremina kugle sa poluprecnikom %2f je %.2f", R,V);
    return 0;
}