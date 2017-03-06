#include <stdio.h>

void obrni(int* p, int* q){
    int temp;
    while(p<q){
        temp=*p;
        *p++=*(--q);
        *q=temp;
    }
}

int main() {
	int i, vel, niz[100];
	printf("Unesite clanove niza (-1 za kraj):\n");
	for (i=0; i<10; i++) {
		scanf("%d", &niz[i]);
		if (niz[i] == -1) break;
	}
		vel=i;
	obrni(niz, niz+vel);
	printf("Nakon poziva funkcije niz glasi:\n");
	for (i=0; i<vel; i++)
		printf("%d ", niz[i]);
	return 0;
}
