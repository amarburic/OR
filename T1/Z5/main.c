#include <stdio.h>

int main() {
	float VT,MT,cVT,cMT,sum,uVT,uMT,rac;
	printf("VT= ");
	scanf("%f",&VT);
	printf("MT= ");
	scanf("%f",&MT);
	printf("cijena VT= ");
	scanf("%f",&cVT);
	printf("cijena MT= ");
	scanf("%f",&cMT);
	sum=VT+MT;
	uVT=VT*100/sum;
	uMT=MT*100/sum;
	rac=VT*cVT + MT*cMT;
	printf("\nUkupna potrosnja je %.2f KWh.",sum);
	printf("\nUdio velike tarife u ukupnoj potrosnji je %g%%.",uVT);
	printf("\nUdio male tarife u ukupnoj potrosnji je %g%%.",uMT);
	printf("\nIznos racuna je %.2f KM.",rac);
	return 0;
}


