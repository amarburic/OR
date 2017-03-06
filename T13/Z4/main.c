#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char prezime[20], ime[15];
    int br_bod1, br_bod2;
} Student;

void ucitaj(char* s, int d)
{
    int i = 0;
    char c = getchar();
    if(c == '\n')
        c = getchar();
    while(c != '\n' && i < d - 1) {
        s[i++] = c;
        c = getchar();
    }
    s[i] = '\0';
}

void sortiraj(Student* niz, int velicina)
{
    int j, k;
    Student tmp;
    for (j = 0; j < velicina-1; j++)
        for (k = j + 1; k < velicina; k++)
            if (niz[k].br_bod1 + niz[k].br_bod2
                    > niz[j].br_bod1 + niz[j].br_bod2) {
                tmp = niz[j];
                niz[j] = niz[k];
                niz[k] = tmp;
            }
}

void spremi(Student* niz, int velicina)
{
    FILE* ispis;
    int i;
    if((ispis = fopen("ispit.txt", "w")) == NULL) {
        printf("Fajl se ne moze otvoriti!\n");
        exit(1);
    }
    for (i = 0; i < velicina; i++)
        fprintf(ispis,"%-20s%-15s%-3d%-3d\n",
                niz[i].prezime, niz[i].ime, niz[i].br_bod1, niz[i].br_bod2);
    fclose(ispis);
}

void dodaj_studenta(Student* niz, int* velicina)
{
    printf("Unesite prezime: ");
    ucitaj(niz[*velicina].prezime, 20);
    printf("Unesite ime: ");
    ucitaj(niz[*velicina].ime, 15);
    printf("Unesite broj bodova na 1. parcijali: ");
    scanf("%d", &(niz[*velicina].br_bod1));
    printf("Unesite broj bodova na 2. parcijali: ");
    scanf("%d", &(niz[*velicina].br_bod2));
    (*velicina)++;
    sortiraj(niz, *velicina);
    spremi(niz, *velicina);
}

void obrisi_studenta(Student* niz, int* velicina)
{
    char prezime[20], ime[15];
    int i, k, obrisano = 0;
    printf("Unesite prezime: ");
    ucitaj(prezime, 20);
    printf("Unesite ime: ");
    ucitaj(ime, 15);
    for(i = 0; i < *velicina; i++)
        if(!strncmp(prezime, niz[i].prezime, 20)
                && !strncmp(ime, niz[i].ime, 15)) {
            for(k = i; k < *velicina; k++) {
                strncpy(niz[i].prezime, niz[i + 1].prezime, 20);
                strncpy(niz[i].ime, niz[i + 1].ime, 15);
                niz[i].br_bod1 = niz[i + 1].br_bod1;
                niz[i].br_bod2 = niz[i + 1].br_bod2;
            }
            (*velicina)--;
            obrisano++;
        }
    if(!obrisano)
        printf("Taj student ne postoji!\n");
    else {
        sortiraj(niz, *velicina);
        spremi(niz, *velicina);
    }
}

void izmjeni_studenta(Student* niz, int* velicina)
{
    char prezime[20], ime[15];
    char novo_prezime[20], novo_ime[15];
    int novi_br_bod1, novi_br_bod2;
    int i, pronadjen = 0;
    printf("Unesite prezime: ");
    ucitaj(prezime, 20);
    printf("Unesite ime: ");
    ucitaj(ime, 15);
    printf("Unesite novo prezime: ");
    ucitaj(novo_prezime, 20);
    printf("Unesite novo ime: ");
    ucitaj(novo_ime, 15);
    printf("Unesite novi broj bodova na 1. parcijali: ");
    scanf("%d", &novi_br_bod1);
    printf("Unesite novi broj bodova na 2. parcijali: ");
    scanf("%d", &novi_br_bod2);
    for(i = 0; i < *velicina; i++)
        if(!strncmp(prezime, niz[i].prezime, 20)
                && !strncmp(ime, niz[i].ime, 15)) {
            strncpy(niz[i].prezime, novo_prezime, 20);
            strncpy(niz[i].ime, novo_ime, 15);
            niz[i].br_bod1 = novi_br_bod1;
            niz[i].br_bod2 = novi_br_bod2;
            pronadjen++;
        }
    if(!pronadjen)
        printf("Taj student ne postoji\n");
    else {
        sortiraj(niz, *velicina);
        spremi(niz, *velicina);
    }
}

void ispisi(Student* niz, int velicina)
{
    int i;
    for(i = 0; i < velicina; i++)
        printf("%-20s%-15s%-3d%-3d\n",
               niz[i].prezime, niz[i].ime,
               niz[i].br_bod1, niz[i].br_bod2);
}

int main()
{
    FILE *ulaz;
    int izbor, prekini = 0, i = 0;
    Student studenti[300];
    if((ulaz = fopen("ispit.txt", "a+")) == NULL) {
        printf("Greska pri otvaranju datoteke ispit.txt");
        exit(1);
    }
    while (fscanf(ulaz,"%20s%15s%3d%3d\n",
                  studenti[i].prezime, studenti[i].ime,
                  &studenti[i].br_bod1, &studenti[i].br_bod2) == 4 && i<300)
        i++;
    fclose(ulaz);
    do {
        printf("Odaberite opciju:\n");
        printf("1) Dodaj studenta:\n");
        printf("2) Obrisi studenta:\n");
        printf("3) Izmjeni studenta\n");
        printf("4) Ispisi sadrzaj\n");
        printf("0) Prekini\n");
        scanf("%d", &izbor);
        switch(izbor) {
        case 0:
            prekini = 1;
            break;
        case 1:
            dodaj_studenta(studenti, &i);
            break;
        case 2:
            obrisi_studenta(studenti, &i);
            break;
        case 3:
            izmjeni_studenta(studenti, &i);
            break;
        case 4:
            ispisi(studenti, i);
            break;

        }
    } while(!prekini);
    return 0;
}
