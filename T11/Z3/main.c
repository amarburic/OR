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

struct Pravougaonik {
    struct Tacka t1,t2;  
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

struct Pravougaonik unos_pravougaonika() {
    struct Pravougaonik p;
    printf("Unesite jednu tacku pravougaonika:\n");
    p.t1 = unos_tacke();
    printf("Unesite drugu tacku pravougaonika:\n");
    p.t2 = unos_tacke();
    return p;
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

float obim_pravougaonika(struct Pravougaonik p){
    return 2*(fabs(p.t1.x-p.t2.x)+fabs(p.t1.y-p.t2.y));
}

float povrsina_pravougaonika(struct Pravougaonik p){
    return fabs(p.t1.x-p.t2.x)*fabs(p.t1.y-p.t2.y);
}

float min(float a, float b){
    return (a<b)?a:b;
}

float max(float a, float b){
    return (a>b)?a:b;
}

int main() {
	struct Kruznica k;
	struct Tacka t;
	struct Pravougaonik p;
	float d;
	printf ("Unesite kruznicu:\n");
	k = unos_kruznice();
	printf ("Unesite pravougaonik:\n");
	p = unos_pravougaonika();
	printf ("Unesite neku tacku:\n");
	t = unos_tacke();
	d = udaljenost(t, k.centar);
	if (d<k.poluprecnik)
		printf("Tacka je unutar kruznice.\n");
	else if (d==k.poluprecnik)
		printf("Tacka je na kruznici.\n");
	else
		printf("Tacka je izvan kruznice.\n");
	if(t.x>=min(p.t1.x,p.t2.x) && t.x<=max(p.t1.x,p.t2.x) 
	&& t.y>=min(p.t1.y,p.t2.y) && t.y<=max(p.t1.y,p.t2.y)){
	   if(t.x==p.t1.x || t.x==p.t2.x || t.y==p.t1.y || t.y==p.t2.y)
	        printf("Tacka se nalazi na pravougaoniku.\n");
	   else
	        printf("Tacka se nalazi unutar pravougaonika.\n");
	}
	else 
	   printf("Tacka se nalazi van pravougaonika\n");
	printf("Obim kruznice: %g\n",obim_kruznice(k));
	printf("Povrsina kruznice: %g\n",povrsina_kruznice(k));
	printf("Obim pravougaonika: %g\n",obim_pravougaonika(p));
	printf("Povrsina pravougaonika: %g\n",povrsina_pravougaonika(p));
	return 0;
}
