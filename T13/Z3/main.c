#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    FILE *izlaz;
    char prezime[20], ime[20];
    int br_bod1, br_bod2, ponovi_unos;
    if((izlaz = fopen("ispit.txt", "a")) == NULL) {
        printf("Greska pri otvaranju datoteke ispit.txt");
        exit(1);
    }
    do {
        printf("Unesite prezime: ");
        ucitaj(prezime, 20);
        printf("Unesite ime: ");
        ucitaj(ime, 15);
        printf("Unesite broj bodova na 1. parcijali: ");
        scanf("%d", &br_bod1);
        printf("Unesite broj bodova na 2. parcijali: ");
        scanf("%d", &br_bod2);
        ponovi_unos = 0;
        if(br_bod1 < 0 || br_bod1 > 20 || br_bod2 < 0 || br_bod2 > 20) {
            printf("Neispravan broj bodova. Ponovite unos.\n");
            ponovi_unos = 1;
        }
    } while(ponovi_unos);
    fprintf(izlaz, "%-20s%-15s%2d%2d\n", prezime, ime, br_bod1, br_bod2);
    fclose(izlaz);
    return 0;
}
