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

int duzina(char *s){
    int i = 0;
    while(*s!='\0'){
        i++;
        s++;
    }
    return i;
}

int uporedi(char* s1, char* s2, int duzina){
    int i = 0;
    while(i<duzina){
        if(*s1>='a' && *s1<='z'){
            if(*s2>='a' && *s2<='z'){
                if(*s1!=*s2){
                    
                    return 0;
                }
            }
            else
                if(*s1!=(char)(*s2 + 'a' - 'A'))
                    return 0;
            }
        else{
            if(*s2>='a' && *s2<='z'){
                if(*s1 + 'a' - 'A' !=*s2)
                    return 0;
            }
            else
                if(*s1!=*s2)
                    return 0;
            }
        s1++;
        s2++;
        i++;
    }
    return 1;
}

int prebroji_rijec(char* s, char* tekst){
    int ne_slovo = 1, counter = 0;
    char* p, *t = tekst;
    while(t == tekst || *(t-1)!='\0'){
        if((*t>='a' && *t<='z') || (*t>='A' && *t<='Z'))
            if(uporedi(s, t, duzina(s)))
                counter++;
        t++;
    }
    return counter;
}

char* izbaci_najcescu(char* tekst){
    int niz[100][2] = {{0,0}}, i=0; 
    char *s = tekst, *p;
    int duzina, ne_slovo=1;
    while(s==tekst || *(s-1)!='\0'){
        if((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')){
            if(ne_slovo){
                p = s;
                duzina = 0;
                ne_slovo = 0;
            }
            duzina++;
        }else if(!ne_slovo){
            ne_slovo = 1;
            char rijec[100];
            
            int j;
            for(j = 0; j < duzina; j++)
                rijec[j] = *(p+j);
            rijec[j] = '\0';
            niz[i][0] = prebroji_rijec(rijec, tekst);
            niz[i][1] = duzina;
            i++;
        }
        s++;
    }
    int ind_max=0, max = 0, j;
    for(j = 0; j < i; j++){
        if(niz[j][0]>max){
            max = niz[j][0];
            ind_max = j;
        }
    }
    s = tekst;
    ne_slovo = 1;
    j = -1;
    char rijec[100];
    int k;
    while(s==tekst || *(s-1)!='\0'){
        if((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')){
            if(ne_slovo){
                j++;
                ne_slovo = 0;
            }
            if(j==ind_max){
                for(k = 0; k < niz[ind_max][1]; k++){
                    rijec[k] = *(s+k);
                }
                break;
            }
        }
        else if(!ne_slovo)
            ne_slovo = 1;
        s++;
    }
    s = tekst;
    while(s==tekst || *(s-1)!='\0'){
        if(uporedi(rijec, s, niz[ind_max][1])){
            char* p;
            p=s+niz[ind_max][1];
            while(*p!='\0'){
                *(p-niz[ind_max][1]) = *p;
                p++;
            }
            *(p-niz[ind_max][1]) = '\0';
        }
        s++;    
    }
    
    return tekst;
}

int main() {
    char tekst[100];
    unesi(tekst, 100);
    printf("Nakon izbacivanja: %s", izbaci_najcescu(tekst));
    
    return 0;
}

