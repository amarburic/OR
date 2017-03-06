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

int broj_predmeta(FILE* predmeti, char* ime_predmeta)
{
    int ucitani_broj;
    char ime_ucitanog[100];
    fseek(predmeti, 0, SEEK_SET);
    while(fscanf(predmeti, "\t%d %[^\n]", &ucitani_broj, ime_ucitanog) == 2) {
        if(strncmp(ime_ucitanog, ime_predmeta, 100) == 0) {
            return ucitani_broj;
        }
    }
    return -1;
}

void stat_studenta(FILE* ispiti)
{
    int brindexa, trazeni_brindexa, ocjena, predmet, slusao = 0, polozio = 0, suma = 0;
    printf("Unesite broj indexa: ");
    scanf("%d", &trazeni_brindexa);
    fseek(ispiti, 0, SEEK_SET);
    while(fscanf(ispiti, "%d %d %d", &brindexa, &predmet, &ocjena) == 3) {
        if(brindexa == trazeni_brindexa) {
            if(ocjena != 5) {
                polozio++;
                suma += ocjena;
            }
            slusao++;
        }
    }
    if(slusao == 0)
        printf("Zalimo, ali ne postoje podaci o studentu %d!\n", trazeni_brindexa);
    else {
        printf("Student je slusao %d predmeta, a polozio %d (%g%%).\n", slusao, polozio, polozio*100./slusao);
        printf("Prosjecna ocjena polozenih predmeta je %.1f.\n", (float)suma/polozio);
    }
}

void stat_predmeta(FILE* ispiti, FILE* predmeti)
{
    int brindexa, ocjena, predmet, trazeni_predmet, slusalo = 0, polozilo = 0, suma = 0;
    char ime_predmeta[100];
    do {
        printf("Unesite predmet: ");
        ucitaj(ime_predmeta, 100);
        trazeni_predmet = broj_predmeta(predmeti, ime_predmeta);
        if(trazeni_predmet == -1) {
            printf("Nepostojeci predmet!\n");

        }
    } while(trazeni_predmet == -1);
    fseek(ispiti, 0, SEEK_SET);
    while(fscanf(ispiti, "%d %d %d", &brindexa, &predmet, &ocjena) == 3) {
        if(predmet == trazeni_predmet) {
            if(ocjena != 5) {
                polozilo++;
                suma += ocjena;
            }
            slusalo++;
        }
    }
    if(slusalo == 0)
        printf("Zalimo, ali ne postoje podaci o predmetu %s!\n", ime_predmeta);
    else {
        printf("Predmet je slusalo %d studenata, a polozilo %d (%g%%).\n", slusalo, polozilo, polozilo*100./slusalo);
        printf("Prosjecna prolazna ocjena je %.1f.\n", (float)suma/polozilo);
    }
}
int main()
{
    FILE* ispiti, *predmeti;
    int izbor, prekini = 0;
    char* predmeti_path = "predmeti.txt", *ispiti_path = "ispiti.txt";
    ispiti = fopen(ispiti_path, "r");
    if(ispiti == NULL) {
        printf("Doslo je do greske.\n");
        exit(1);
    }
    predmeti = fopen(predmeti_path, "r");
    if(predmeti == NULL) {
        printf("Doslo je do greske.\n");
        exit(1);
    }
    while(!prekini) {
        printf("Unesite 1 za statistiku studenta, 2 za statistiku predmeta, 0 za izlaz:\n");
        scanf("%d", &izbor);
        switch(izbor) {
        case 1:
            stat_studenta(ispiti);
            break;
        case 2:
            stat_predmeta(ispiti, predmeti);
            break;
        case 0:
            prekini = 1;
            break;
        }
    }
    fclose(ispiti);
    fclose(predmeti);
    return 0;
}
