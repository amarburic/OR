#include <stdio.h>
#include <math.h>

struct Vrijeme {
    int sati;
    int minute;
    int sekunde;
};

struct Vrijeme unos_vremena(){
    struct Vrijeme v;
    scanf("%d %d %d",&v.sati,&v.minute,&v.sekunde);
    return v;
}

struct Vrijeme proteklo(struct Vrijeme v1, struct Vrijeme v2){
    int s1,s2,razlika;
    struct Vrijeme v;
    s1 = v1.sekunde + v1.minute*60 + v1.sati*3600;
    s2 = v2.sekunde + v2.minute*60 + v2.sati*3600;
    razlika = fabs(s1-s2);
    v.sati = razlika/3600;
    v.minute = razlika%3600/60;
    v.sekunde = razlika%60;
    return v;
}

int main() {
    struct Vrijeme v1,v2,v3;
    printf("Unesite prvo vrijeme (h m s): ");
    v1 = unos_vremena();
    printf("Unesite drugo vrijeme (h m s): ");
    v2 = unos_vremena();
    v3 = proteklo(v1,v2);
    printf("Između dva vremena je proteklo: %d sati, %d minuta i %d sekundi.",v3.sati,v3.minute,v3.sekunde);
    return 0;
}

