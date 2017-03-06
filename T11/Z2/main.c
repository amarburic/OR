#include <stdio.h>
#include <math.h>
#define PI 3.14

struct Tacka {
	float x,y;
};

struct Kruznica {
	struct Tacka centar;
	float poluprecnik;
};

struct Tacka unos_tacke() {
	struct Tacka t;
	printf ("Unesite koordinate tacke (x,y): ");
	scanf ("%f,%f", &t.x, &t.y);
	return t;
}

struct Kruznica unos_kruznice() {
	struct Kruznica k;
	printf ("Unesite centar kruznice:\n");
	k.centar = unos_tacke();
	printf ("Unesite poluprecnik kruznice: ");
	scanf("%f", &k.poluprecnik);
	return k;
}

float udaljenost(struct Tacka t1, struct Tacka t2) {
	return sqrt( (t1.x-t2.x)*(t1.x-t2.x) + (t1.y-t2.y)*(t1.y-t2.y) );
}

float obim_kruznice(struct Kruznica k){
    return 2*k.poluprecnik*PI;
}

float povrsina_kruznice(struct Kruznica k){
    return k.poluprecnik*k.poluprecnik*PI;
}

int main() {
	struct Kruznica k;
	struct Tacka t;
	float d;
	printf ("Unesite kruznicu:\n");
	k = unos_kruznice();
	printf ("Unesite neku tacku:\n");
	t = unos_tacke();
	d = udaljenost(t, k.centar);
	if (d<k.poluprecnik)
		printf("Tacka je unutar kruznice.");
	else if (d==k.poluprecnik)
		printf("Tacka je na kruznici.");
	else
		printf("Tacka je izvan kruznice.");
	printf("\nObim kruznice: %g",obim_kruznice(k));
	printf("\nPovrsina kruznice: %g",povrsina_kruznice(k));
	return 0;
}
