#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ucitaj(char* s, int duzina)
{
    int i = 0;
    char c = getchar();
    if(c == '\n') c = getchar();
    while(c != '\n' && i < duzina - 1) {
        s[i++] = c;
        c = getchar();
    }
    s[i] = '\0';
}

int broj_predmeta(char* ime_predmeta)
{
    FILE* predmeti;
    int ucitani_broj;
    char ime_ucitanog[100], *predmeti_path = "predmeti.txt";
    predmeti = fopen(predmeti_path, "r");
    if(predmeti == NULL) {
        printf("Doslo je do greske. Fajl %s ne postoji\n", predmeti_path);
        exit(1);
    }
    while(fscanf(predmeti, "\t%d %[^\n]", &ucitani_broj, ime_ucitanog) == 2) {
        if(strncmp(ime_ucitanog, ime_predmeta,100) == 0){
            fclose(predmeti);
            return ucitani_broj;
        }
    }
    fclose(predmeti);
    return -1;
}

int main()
{
    FILE* ispiti;
    int brindexa, predmet, trazeni_predmet, ocjena, slusali, prosli = 0, pali = 0, suma = 0;
    char ime_predmeta[100], *ispiti_path = "ispiti.txt";
    ispiti = fopen(ispiti_path, "r");
    if(ispiti == NULL) {
        printf("Doslo je do greske. Fajl %s ne postoji\n",ispiti_path);
        exit(1);
    }
    do {
        printf("Unesite predmet: ");
        ucitaj(ime_predmeta, 100);
        trazeni_predmet = broj_predmeta(ime_predmeta);
        if(trazeni_predmet == -1) {
            printf("Nepostojeci predmet!\n");

        }
    } while(trazeni_predmet == -1);
    while(fscanf(ispiti, "%d %d %d", &brindexa, &predmet, &ocjena) == 3){
        if(predmet == trazeni_predmet){
            if(ocjena == 5) pali++;
            else prosli++;
            suma += ocjena;
        }
    }
    slusali = prosli + pali;
    if(slusali == 0)
        printf("Zalimo, ali ne postoje podaci o predmetu %s!", ime_predmeta);
    else
        printf("Prosjecna ocjena: %.2f\nProlaznost: %g%%", ((double)suma)/slusali,  prosli*100.0/slusali);
    fclose(ispiti);
    return 0;
}
