#include <stdio.h>

char* pretvori(char* s){
    char* s0=s;
    while(*s){
        if(*s>='A' && *s<='Z')*s+='a'-'A';
        else if(!(*s>='a' && *s<='z'))*s='-';
        s++;
    }
    return s0;
}

void sastavi(char* s1, char* s2){
    while(*s1++);
    s1--;
    while(*s2)
        *s1++=*s2++;
    *s1='\0';
}

void kopiraj(char* s1, char* s2){
    while(*s2)
        *s1++=*s2++;
    s1='\0';
}
char *adresa(char *ime, char *prezime){
    char mail[250]="[";
    sastavi(mail,pretvori(ime));
    sastavi(mail,"].[");
    sastavi(mail,pretvori(prezime));
    sastavi(mail,"]@etf.unsa.ba");
    kopiraj(prezime,mail);
    return prezime;
}

void ucitaj(char* s, int duzina){
    char c = getchar();
    int i = 0;
    if(c=='\n')c=getchar();
    while(c!='\n' && i<duzina){
        s[i]=c;
        i++;
        c=getchar();
    }
    s[i]='\0';
}

int main() {
    char ime[100],prezime[100];
    ucitaj(ime,100);
    ucitaj(prezime,100);
    printf("%s", adresa(ime,prezime));
    return 0;
}

