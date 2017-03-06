#include <stdio.h>

    struct Osoba {
        char ime[15];
        char prezime[20];
        int telefon;
    };

void unesi(char *s, int duzina) {
    int i = 0;
    char c = getchar();
    if (c == '\n') c = getchar();
    while (i < duzina - 1 && c != '\n') {
        s[i++] = c;
        c = getchar();
    }
    s[i] = '\0';
}

struct Osoba unos_osobe() {
    struct Osoba o;
    printf("Unesite ime: ");
    unesi(o.ime, 15);
    printf("Unesite prezime: ");
    unesi(o.prezime, 20);
    printf("Unesite broj telefona: ");
    scanf("%d", &o.telefon);
    return o;
}

void ispis_osobe(struct Osoba o) {
    printf("%s %s, Tel: %d", o.ime, o.prezime, o.telefon);
}
int main() {
    struct Osoba imenik[100];
    int odabir, prekid = 0, i = 0, j;
    while (!prekid) {
        printf("Pritisnite 1 za unos, 2 za ispis, 0 za izlaz: ");
        scanf("%d", &odabir);
        switch (odabir) {
            case 0:
                prekid = 1;
                break;
            case 1:
                imenik[i++] = unos_osobe();
                break;
            case 2:
                for (j = 0; j < i; j++) {
                    printf("%d. ", j + 1);
                    ispis_osobe(imenik[j]);
                    printf("\n");
                }
            break;
        }
    }
    return 0;
}
