#include <stdio.h>
#include <math.h>
int main() {
	double x1,x2,z1,z2,y1,y2;
	printf("Unesite T1:");
	scanf("%lf %lf %lf",&x1,&y1,&z1);
	printf("Unesite T2:");
	scanf("%lf %lf %lf",&x2,&y2,&z2);
	double dist = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
	printf("Udaljenost izmedju t1 i t2 je %5.2f",dist);
	return 0;
}
