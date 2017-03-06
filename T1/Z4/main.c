#include <stdio.h>
#define PI 3.14

int main() {
	float a,b,c,r,h,P,V;
	printf("Unesite sirinu kvadra: ");
	scanf("%f",&a);
	printf("Unesite visinu kvadra: ");
	scanf("%f",&b);
	printf("Unesite duzinu kvadra: ");
	scanf("%f",&c);
	printf("Unesite visinu valjka: ");
	scanf("%f",&h);
	printf("Unesite poluprecnik baze valjka: ");
	scanf("%f",&r);
	P=2*(a*b + b*c + a*c) + (2*r*PI*h);
	V=a*b*c + r*r*PI*h;
	printf("\nPovrsina tijela sa slike je %.3f cm2.",P);
	printf("\nZapremina tijela sa slike je %.3f cm3.",V);	
	return 0;
}


