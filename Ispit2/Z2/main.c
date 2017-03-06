#include <stdio.h>

void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}

char* izbaci_maxbr(char* s){
    int neg, broj, ne_cifra=1,maxbr,pronadjen=0,duzina=0,trduzina;
    char* p, *s0,*pmaxbr;
    s0 = s;
    while(s == s0 || *(s-1)!='\0'){
        if(*s>='0' && *s<='9'){
            if(ne_cifra){
                if(s>s0 && *(s-1)=='-'){
                    neg = 1;
                    p = s-1;
                }
                else{
                    neg = 0;
                    p = s;
                }
                ne_cifra=0;
                trduzina=0;
                broj = 0;
            }
            broj*=10;
            broj+=(*s-'0');
            trduzina++;
        }
        else if(!ne_cifra){
            if(neg)
                broj*=-1;
            if(!pronadjen || broj>maxbr){
                maxbr=broj;
                pmaxbr=p;
                duzina=trduzina;
                if(neg)
                    duzina++;
                pronadjen = 1;
            }
            ne_cifra=1;
        }
        s++;
    }
    if(pronadjen){
        p=pmaxbr+duzina;
        while(*p!='\0'){
            *(p-duzina)=*p;
            p++;
        }
        *(p-duzina)='\0';
    }
    return s0;
}

int main() {
    char tekst[100];
    unesi(tekst,100);
    izbaci_maxbr(tekst);
    printf("Nakon izbacivanja: %s", tekst);
    return 0;
}

