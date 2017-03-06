#include <stdio.h>

struct Radnik {
    char ime[20], prezime[20];
    int godina;
    float plata[12];
} radnici[1000];
int br_radnika;

void ucitaj(){
    FILE* ulaz = fopen("ulaz.txt", "r");
    int i, upisano = 0;
    br_radnika=0;
    while(!feof(ulaz) && upisano <1000){
        fscanf(ulaz, "%s %s %d ",radnici[br_radnika].ime, radnici[br_radnika].prezime, &radnici[br_radnika].godina);
        for(i = 0; i < 12; i++)
            fscanf(ulaz, " %f", &radnici[br_radnika].plata[i]);
        fscanf(ulaz, "\n");
        br_radnika++;
        upisano++;
    }
    fclose(ulaz);
}
void zapisi(){
    FILE* izlaz = fopen("izlaz.txt", "w");
    int i, j;
    float prosjek;
    for(i = 0; i<br_radnika; i++){
        if(radnici[i].godina!=2010)
            continue;
        prosjek = 0;
        for(j = 0; j < 12; j++)
            prosjek+=radnici[i].plata[j];
        prosjek/=12;
        if(prosjek>1000)
            fprintf(izlaz, "%-20s%-20s%.2f\n", radnici[i].ime, radnici[i].prezime, prosjek);
    }
    fclose(izlaz);
}
int main() {
    ucitaj();
    zapisi();
    return 0;
}

