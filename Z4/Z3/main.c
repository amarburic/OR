#include <stdio.h>

int duzina(char* s){
    int i=0;
    while(*s++)i++;
    return i;
}

int je_cifra(char c){
    return c>='0' && c<='9';
}

int je_prekid(char c){
    return c==' ' || c=='.' || c==',' || c=='\0';
}

int pretvori_u_int(char* p){
    int ret=0,i;
    for(i=0;i<duzina(p);i++){
        if(!je_cifra(p[i]))break;
        ret*=10;
        ret+=p[i]-'0';
    }
    return ret;
}

void pretvori_u_string(int d, char* s){
    int i=0,temp;
    do{
        s[i++]=(char)(d%10+'0');
        d/=10;
    }while(d!=0);
    s[i]='\0';
    for(i=0;i<duzina(s)/2;i++){
        temp=s[i];
        s[i]=s[duzina(s)-i-1];
        s[duzina(s)-i-1]=temp;
    }
}

int dek_u_bin_konv(int dek){
    int rbin=0,bin=0,i=0;
    do{
        rbin*=10;
        rbin+=dek%2;
        dek/=2;
        i++;
    }while(dek!=0);
    do{
        bin*=10;
        bin+=rbin%10;
        rbin/=10;
        i--;
    }while(i!=0);
    return bin;
}

void obrisi(char* p, char* k){
    int i;
    for(i=0;i<=duzina(p);i++)
        p[i]=p[i+k-p];
}

void umetni(char* p, char* s){
    int i;
    for(i=duzina(p);i>=0;i--)
        p[i+duzina(s)]=p[i];
    for(i=0;i<duzina(s);i++)
        p[i]=s[i];

}

char* pretvori_u_bin(char* s){
    int i,prekid=1,pocetak=-1;
    for(i=0;i<=duzina(s);i++){
        if(je_cifra(s[i]) && prekid){
            pocetak=i;
            prekid=0;
        }
        if(je_prekid(s[i])){
            if(pocetak>=0){
                char stemp[11]="";
                pretvori_u_string(dek_u_bin_konv(pretvori_u_int(s+pocetak)),stemp);
                obrisi(s+pocetak,s+i);
                umetni(s+pocetak,"0b");
                pocetak+=2;
                umetni(s+pocetak,stemp);
                i=pocetak+duzina(stemp);
            }
            pocetak=-1;
            prekid=1;
        }
        if(!je_prekid(s[i]) && !je_cifra(s[i]))
        {
            pocetak=-1;
            prekid=0;
        }
    }
    return s;
}

int main() {
    char text[1000] = "Na OR-u ima 13 tutora od cega je 11 demonstratora. Ovo je 4. zadaca.";
    pretvori_u_bin(text);
    printf ("%s",text);
    return 0;
}

