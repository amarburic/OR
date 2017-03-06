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

int proteklo(struct Vrijeme v1, struct Vrijeme v2){
    int s1,s2;
    s1 = v1.sekunde + v1.minute*60 + v1.sati*3600;
    s2 = v2.sekunde + v2.minute*60 + v2.sati*3600;
    return fabs(s1-s2);
}

int main() {
    struct Vrijeme v1,v2;
    printf("Unesite prvo vrijeme (h m s): ");
    v1 = unos_vremena();
    printf("Unesite drugo vrijeme (h m s): ");
    v2 = unos_vremena();
    printf("Između dva vremena je proteklo %d sekundi.",proteklo(v1,v2));
    return 0;
}

