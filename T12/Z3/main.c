#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* ispiti;
    int brindexa, predmet, trazeni_predmet, ocjena, slusali, prosli = 0, pali = 0, suma = 0;
    char* ispiti_path = "ispiti.txt";
    ispiti = fopen(ispiti_path, "r");
    if(ispiti == NULL) {
        printf("Doslo je do greske. Fajl %s ne postoji\n",ispiti_path);
        exit(1);
    }
    printf("Unesite predmet: ");
    scanf("%d", &trazeni_predmet);
    while(fscanf(ispiti, "%d %d %d", &brindexa, &predmet, &ocjena) == 3){
        if(predmet == trazeni_predmet){
            if(ocjena == 5) pali++;
            else prosli++;
            suma += ocjena;
        }
    }
    slusali = prosli + pali;
    if(slusali == 0)
        printf("Zalimo, ali ne postoje podaci o predmetu sa brojem %d!", trazeni_predmet);
    else
        printf("Prosjecna ocjena: %.2f\nProlaznost: %g%%", ((double)suma)/slusali,  prosli*100.0/slusali);
    fclose(ispiti);
    return 0;
}
