#include <stdio.h>

void obrisi(char* p1, char* p2){
    while(*p2)
        *p1++=*p2++;
    *p1='\0';
}

int je_slovo(char c){
    return !(c==' ' || c=='\0');
}

char* tritacke(char* s){
    int duzina=0;
    char *poc=s;
    while(*poc){
        if(je_slovo(*poc))
            duzina++;
        else{
            if(duzina>=10){
                obrisi(poc-duzina+4,poc);
                poc-=duzina-4;
                *(poc-1)='.';
            }
            duzina=0;
        }
        poc++;
    }
    return s;
}

int main() {
    char tekst[100] = "Za vrijeme promjena specifikacija moze doci do poremecaja tolerancije izlaznog proizvoda.";
    printf("%s", tritacke(tekst));
    return 0;
}
