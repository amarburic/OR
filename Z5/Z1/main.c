#include <stdio.h>
#include <string.h>

#define EPSILON 0.001
#define SVEL 100

struct Paket {
	char naziv_robe[SVEL];
	int kolicina;
	float cijena;
} paketi[100];

struct Skladiste {
	char naziv[SVEL];
	int kapacitet;
	struct Paket* sadrzaj[100];
	int br_paketa;
} skladista[100];

int br_paketa, br_skladista;

int ucitaj_datoteke();
int zapisi_datoteke();
int dodaj_skladiste(const char* naziv, int kapacitet);
int promijeni_skladiste(int indeks, const char* naziv, int kapacitet);
int obrisi_skladiste(int indeks);
int dodaj_paket(const char* naziv_robe, int kolicina, float cijena);
int stavi_paket_u_skladiste(int paket, int skladiste);
int izbaci_paket_iz_skladista(int paket, int skladiste);
int obrisi_paket(int paket);
int ulaz_robe(const char* naziv_robe, int kolicina, float cijena);
float izlaz_robe(const char* naziv_robe, int kolicina);
void statistika();

int validno_skladiste(int indeks, const char* naziv, int kapacitet);
int validan_paket(int kolicina, float cijena);

int popunjeni_kapacitet(struct Skladiste* s);
int preostali_kapacitet(struct Skladiste* s);

void kopiraj_skladiste(struct Skladiste* s1, struct Skladiste* s2);
void kopiraj_paket(struct Paket* p1, struct Paket* p2);

void izlistaj_skladista();
void printaj_skladiste(const char* naziv);
void printaj_paket(int indeks);

int indeks_skladista(const char* naziv);
int broj_skladista();

int adresa_paketa(int indeks);
int indeks_paketa(struct Paket* p);

void glavni_meni();
void skladista_meni();


int main(){
    glavni_meni();
    return 0;
}

int ucitaj_datoteke(){
    int i, j, indeks;
    FILE* fskladista, *fpaketi;
    fskladista = fopen("skladista.dat", "rb");
    if(!fskladista)
        return 0;
    fpaketi = fopen("paketi.dat", "rb");
    if(!fpaketi)
        return 0;
    br_paketa = fread(paketi, sizeof(struct Paket), 100, fpaketi);
    i = 0;
    while(!feof(fskladista)){
        fread(skladista[i].naziv, sizeof(char), SVEL, fskladista);
        fread(&skladista[i].kapacitet, sizeof(int), 1, fskladista);
        fread(&skladista[i].br_paketa, sizeof(int), 1, fskladista);
        for(j = 0; j < skladista[i].br_paketa; j++){
            fread(&indeks, sizeof(int), 1, fskladista);
            skladista[i].sadrzaj[j] = paketi + indeks;
        }
        i++;
    }
    br_skladista = i-1;
    fclose(fskladista);
    fclose(fpaketi);
    return 1;
}

int zapisi_datoteke(){
    FILE* fskladista, *fpaketi;
    int i, j, indeks;
    fskladista = fopen("skladista.dat", "wb");
    if(!fskladista)
        return 0;
    fpaketi = fopen("paketi.dat", "wb");
    if(!fpaketi)
        return 0;
    fwrite(paketi, sizeof(struct Paket), br_paketa, fpaketi);
    for(i = 0; i < br_skladista; i++){
        fwrite(skladista[i].naziv, sizeof(char), SVEL, fskladista);
        fwrite(&skladista[i].kapacitet, sizeof(int), 1, fskladista);
        fwrite(&skladista[i].br_paketa, sizeof(int), 1, fskladista);
        for(j = 0; j < skladista[i].br_paketa; j++){
            indeks = indeks_paketa(skladista[i].sadrzaj[j]);
            fwrite(&indeks, sizeof(int), 1, fskladista);
        }
    }
    fclose(fskladista);
    fclose(fpaketi);
    return 1;
}

int dodaj_skladiste(const char* naziv, int kapacitet){
    if(!validno_skladiste(-1, naziv, kapacitet))
        return -1;
    strncpy(skladista[br_skladista].naziv, naziv,
            sizeof(skladista[br_skladista].naziv));
    skladista[br_skladista].kapacitet = kapacitet;
    skladista[br_skladista].br_paketa = 0;
    ++br_skladista;
    return br_skladista - 1;
}

int promijeni_skladiste(int indeks, const char* naziv, int kapacitet){
    if(indeks < 0 || indeks > br_skladista - 1)
        return 0;
    if(!validno_skladiste(indeks, naziv, kapacitet))
        return 0;
    if(kapacitet < popunjeni_kapacitet(&skladista[indeks]))
        return 0;
    strncpy(skladista[indeks].naziv, naziv, SVEL);
    skladista[indeks].kapacitet = kapacitet;
    return 1;
}

int obrisi_skladiste(int indeks){
    int i;
    if(indeks < 0 || indeks > br_skladista - 1)
        return 0;
    for(i = indeks; i < br_skladista - 1; i++)
        kopiraj_skladiste(skladista + i, skladista + i + 1);
    --br_skladista;
    return 1;
}

int dodaj_paket(const char* naziv_robe, int kolicina, float cijena){
    int i;
    if(!validan_paket(kolicina, cijena))
        return -1;
    for(i = 0; i < br_paketa; i++)
        if(paketi[i].kolicina == 0)
            break;
    strncpy(paketi[i].naziv_robe, naziv_robe, SVEL);
    paketi[i].kolicina = kolicina;
    paketi[i].cijena = cijena;
    if(i == br_paketa)
        ++br_paketa;
    return i;
}

int stavi_paket_u_skladiste(int paket, int skladiste){
    struct Paket* p = paketi + paket;
    struct Skladiste* s = skladista + skladiste;
    if(paket < 0 || paket > br_paketa - 1)
        return 0;
    if(skladiste < 0 || skladiste > br_skladista - 1)
        return 0;
    if(adresa_paketa(paket) != -1)
        return 0;
    if(preostali_kapacitet(s) < p->kolicina)
        return 0;
    s->sadrzaj[s->br_paketa] = p;
    ++(s->br_paketa);
    return 1;
}

int izbaci_paket_iz_skladista(int paket, int skladiste){
    int indeks_paketa_u_skladistu, i;
    struct Skladiste* s = skladista + skladiste;
    if(paket < 0 || paket > br_paketa - 1 || paketi[paket].kolicina == 0)
        return 0;
    if(skladiste < 0 || skladiste > br_skladista - 1)
        return 0;
    if(adresa_paketa(paket) != skladiste)
        return 0;
    for(i = 0; i < s->br_paketa; i++)
        if(indeks_paketa(s->sadrzaj[i]) == paket){
            indeks_paketa_u_skladistu = i;
            break;
        }
    for(i = indeks_paketa_u_skladistu; i < s->br_paketa - 1; i++)
        s->sadrzaj[i] = s->sadrzaj[i+1];
    --(s->br_paketa);
    return 1;
}

int obrisi_paket(int paket){
    if(paket < 0 || paket > br_paketa - 1 || paketi[paket].kolicina == 0)
        return 0;
    izbaci_paket_iz_skladista(paket, adresa_paketa(paket));
    paketi[paket].kolicina = 0;
    return 1;
}

int ulaz_robe(const char* naziv_robe, int kolicina, float cijena){
    int indeks, i;
    if((indeks = dodaj_paket(naziv_robe, kolicina, cijena)) == -1)
        return 0;
    for(i = 0; i < br_skladista; i++)
        if(stavi_paket_u_skladiste(indeks, i))
            break;
    if(adresa_paketa(indeks) == -1){
        obrisi_paket(indeks);
        return 0;
    }
    return 1;
}

float izlaz_robe(const char* naziv_robe, int kolicina){
    int i;
    float cijena;
    if(kolicina <= 0)
        return -1;
    for(i = 0; i < br_paketa; i++)
        if(strncmp(paketi[i].naziv_robe, naziv_robe, SVEL) == 0){
            if(paketi[i].kolicina == kolicina){
                cijena = paketi[i].cijena * kolicina;
                obrisi_paket(i);
                return cijena;
            }else if(paketi[i].kolicina > kolicina){
                cijena = paketi[i].cijena * kolicina;
                paketi[i].kolicina -= kolicina;
                return cijena;
            }
        }
    return -1;
}

void statistika(){
    int i, j, ukupni_kapacitet = 0, ukupni_popunjeni_kapacitet = 0;
    float vrijednost_robe = 0;
    for(i = 0; i < br_skladista; i++){
        ukupni_kapacitet += skladista[i].kapacitet;
        ukupni_popunjeni_kapacitet += popunjeni_kapacitet(&skladista[i]);
        for(j = 0; j < skladista[i].br_paketa; j++)
            vrijednost_robe += skladista[i].sadrzaj[j]->cijena * skladista[i].sadrzaj[j]->kolicina;
    }
    printf("Evidentirana su %d skladista sa ukupnim kapacitetom %dkg.\n",
            br_skladista, ukupni_kapacitet);
    float procenat;
    if(ukupni_kapacitet == 0)
        procenat = 0;
    else
        procenat = ukupni_popunjeni_kapacitet*100. / ukupni_kapacitet;
    printf("Od toga je popunjeno %dkg (%.2f%%).\n",
           ukupni_popunjeni_kapacitet, procenat);
    printf("Ukupna vrijednost robe u skladistima je %.2f KM.\n", vrijednost_robe);
}

int validno_skladiste(int indeks, const char* naziv, int kapacitet){
    int i;
    if(kapacitet <= 0)
        return 0;
    for(i = 0; i < br_skladista; i++)
        if(strncmp(skladista[i].naziv, naziv, SVEL) == 0
           && i != indeks)
            return 0;
    return 1;
}

int validan_paket(int kolicina, float cijena){
    if(kolicina <= 0 || cijena <= 0)
        return 0;
    return 1;
}

int popunjeni_kapacitet(struct Skladiste* s){
    int i, popunjeno = 0;
    for(i = 0; i < s->br_paketa; i++)
        popunjeno += s->sadrzaj[i]->kolicina;
    return popunjeno;
}

int preostali_kapacitet(struct Skladiste* s){
    return s->kapacitet - popunjeni_kapacitet(s);
}

void kopiraj_skladiste(struct Skladiste* s1, struct Skladiste* s2){
    int i;
    s1->br_paketa = s2->br_paketa;
    s1->kapacitet = s2->kapacitet;
    strncpy(s1->naziv, s2->naziv, SVEL);
    for(i = 0; i < s2->br_paketa; i++)
        s1->sadrzaj[i] = s2->sadrzaj[i];
}

void kopiraj_paket(struct Paket* p1, struct Paket* p2){
    p1->cijena = p2->cijena;
    p1->kolicina = p2->kolicina;
    strncpy(p1->naziv_robe, p2->naziv_robe, SVEL);
}

void izlistaj_skladista(){
    int i;
    for(i = 0; i < br_skladista; i++)
        printf("%s\n", skladista[i].naziv);
}

void printaj_skladiste(const char* naziv){
    int i, indeks = indeks_skladista(naziv);
    if(indeks == -1)
        printf("Nepostojece skladiste\n");
    else{
    struct Skladiste* s = skladista + indeks;
    printf("Kapacitet skladista: %dkg\n", s->kapacitet);
    printf("Popunjeno: %dkg (%.2f%%)\n", popunjeni_kapacitet(s),
            popunjeni_kapacitet(s) * 100. / s->kapacitet);
    printf("Paketi:\n");
    for(i = 0; i < s->br_paketa; i++)
        printaj_paket(indeks_paketa(s->sadrzaj[i]));
    }
}

void printaj_paket(int indeks){
    struct Paket* p = paketi + indeks;
    printf("- %s (%dkg, %.2f KM/kg)\n", p->naziv_robe, p->kolicina, p->cijena);
}

int indeks_skladista(const char* naziv){
    int i, indeks = -1;
    for(i = 0; i < br_skladista; i++){
        if(strncmp(skladista[i].naziv, naziv, SVEL) == 0){
            indeks = i;
            break;
        }
    }
    return indeks;
}

int broj_skladista(){
    return br_skladista;
}

int adresa_paketa(int indeks){
    int i, j;
    for(i = 0; i < br_skladista; i++)
        for(j = 0; j < skladista[i].br_paketa; j++)
            if(skladista[i].sadrzaj[j] - paketi == indeks)
                return i;
    return -1;
}

int indeks_paketa(struct Paket* p){
    return p - paketi;
}

void ucitaj(char* s, int d){
    int i = 0;
    char c = getchar();
    if(c == '\n')
        c = getchar();
    while(c != '\n' && i < d - 1){
        s[i++] = c;
        c = getchar();
    }
    s[i] = '\0';
}

void glavni_meni(){
    int prekini = 0, izbor, kolicina;
    float cijena;
    char naziv_robe[SVEL];
    if(br_skladista == 0 && br_paketa == 0)
        ucitaj_datoteke();
    while(!prekini){
        printf("1) Skladista\n");
        printf("2) Ulaz robe\n");
        printf("3) Izlaz robe\n");
        printf("4) Statistika\n");
        printf("0) Izlaz\n");
        printf("Unesite vas izbor: ");
        scanf("%d", &izbor);
        switch(izbor){
            case 1:
                skladista_meni();
            break;
            case 2:
                printf("Unesite naziv robe: ");
                ucitaj(naziv_robe, SVEL);
                printf("Unesite kolicinu robe: ");
                scanf("%d", &kolicina);
                printf("Unesite cijenu robe: ");
                scanf("%f", &cijena);
                if(!ulaz_robe(naziv_robe, kolicina, cijena))
                    printf("Ulaz robe nije uspio\n");
            break;
            case 3:
                printf("Unesite naziv robe: ");
                ucitaj(naziv_robe, SVEL);
                printf("Unesite kolicinu robe: ");
                scanf("%d", &kolicina);
                if(izlaz_robe(naziv_robe, kolicina) == -1)
                    printf("Izlaz robe nije uspio\n");
            break;
            case 4:
                statistika();
            break;
            case 0:
                prekini = 1;
            break;
        }
        zapisi_datoteke();
    }
}

void skladista_meni(){
    int prekini = 0, izbor, kapacitet, indeks;
    char naziv[SVEL], stari_naziv[SVEL], novi_naziv[SVEL];
    while(!prekini){
        printf("1) Spisak skladista\n");
        printf("2) Podaci o skladistu\n");
        printf("3) Novo skladiste\n");
        printf("4) Promijeni skladiste\n");
        printf("5) Obrisi skladiste\n");
        printf("0) Povratak na glavni meni\n");
        printf("Unesite vas izbor: ");
        scanf("%d", &izbor);
        switch(izbor){
            case 1:
                izlistaj_skladista();
            break;
            case 2:
                printf("Unesite naziv skladista: ");
                ucitaj(naziv, SVEL);
                printaj_skladiste(naziv);
            break;
            case 3:
                printf("Unesite naziv skladista: ");
                ucitaj(naziv, SVEL);
                printf("Unesite kapacitet skladista: ");
                scanf("%d", &kapacitet);
                if(dodaj_skladiste(naziv, kapacitet) == -1)
                    printf("Neispravni podaci\n");
            break;
            case 4:
                printf("Unesite naziv skladista koji mijenjate: ");
                ucitaj(stari_naziv, SVEL);
                printf("Unesite novi naziv: ");
                ucitaj(novi_naziv, SVEL);
                printf("Unesite novi kapacitet skladista: ");
                scanf("%d", &kapacitet);
                indeks = indeks_skladista(stari_naziv);
                if(indeks == -1){
                    printf("Nepostojece skladiste\n");
                    break;
                }
                if(!promijeni_skladiste(indeks , novi_naziv, kapacitet))
                    printf("Neispravni podaci\n");
            break;
            case 5:
                printf("Unesite naziv skladista koje brisete: ");
                ucitaj(naziv, SVEL);
                indeks = indeks_skladista(naziv);
                if(indeks == -1){
                    printf("Nepostojece skladiste\n");
                    break;
                }
                if(obrisi_skladiste(indeks_skladista(naziv)))
                    printf("Skladiste uspjesno obrisano.\n");
                else
                    printf("Neispravni podaci\n");
            break;
            case 0:
                prekini = 1;
            break;
        }
        zapisi_datoteke();
    }
}

/*Code Blocks copy-paste*/
