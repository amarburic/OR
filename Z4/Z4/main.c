#include <stdio.h>
#include <math.h>

int duzina(char* s){
    int i = 0;
    while(*s++)i++;
    return i;
}

int je_cifra(char c){
    return c>='0' && c<='9';
}

int je_operator(char c){
    return c=='^' || c=='*' || c=='/' || c=='+' || c=='-';
}

int pretvori_u_int(char* s){
    int i,neg=0,rez=0;
    if(s[0]=='-'){
        neg=1;
        s++;
    }
    for(i=0;i<duzina(s) && je_cifra(s[i]);i++){
        rez*=10;
        rez+=s[i]-'0';
    }
    if(neg)rez*=-1;
    return rez;
}

char* pretvori_u_string(int broj, char* s){
    int i=0,neg=0,temp;
    if(broj<0){
        broj*=-1;
        neg=1;
    }
    do{
        s[i++]=(char)(broj%10+'0');
        broj/=10;
    }while(broj);
    if(neg)s[i++]='-';
    s[i]='\0';
    for(i=0;i<duzina(s)/2;i++){
        temp=s[i];
        s[i]=s[duzina(s)-i-1];
        s[duzina(s)-i-1]=temp;
    }
    return s;
}

void obrisi(char* p, char* k){
    int i,razmak=k-p;
    for(i=0;i<=duzina(p)-razmak;i++)
        p[i]=p[i+razmak];
}

void umetni(char* p, char* s){
    int i;
    for(i=duzina(p);i>=0;i--)
        p[i+duzina(s)]=p[i];
    for(i=0;i<duzina(s);i++)
        p[i]=s[i];
}

int provjera(char* s){
    int i, br_op=0;
    if(!(s[0]=='-' || je_cifra(s[0])))return 0;
    if(je_operator(s[duzina(s)-1]))return 0;
    for(i=1;i<duzina(s);i++){
        if(!je_cifra(s[i]) && !je_operator(s[i]))return 0;
        if(je_operator(s[i]) && je_operator(s[i-1]) && s[i]!='-')return 0;
        if(i==1 && s[i]=='-' && s[i-1]=='-')return 0;
        if(je_operator(s[i]))br_op++;
        else br_op=0;
        if(br_op>2)return 0;
    }
    return 1;
}

int izracunaj(char* s0, int* ok){
    *ok = provjera(s0);
    if(!*ok)return -1;
    char operacije[3][3]={"^^","*/","+-"},stmp[1000]="",s[1000];
    int i,j,k,l;
    for(i=0;i<=duzina(s0);i++)
        s[i]=s0[i];
    for(i=0;i<3;i++){
        for(j=1;j<duzina(s);j++){
            if(s[j]==operacije[i][0] || s[j]==operacije[i][1]){
                for(k=j-1;k>=1 && je_cifra(s[k-1]);k--);
                if(k>0 && s[k-1]=='-' && (k==1 || je_operator(s[k-2])))k--;
                for(l=j+1;l<duzina(s)-1 && je_cifra(s[l+1]);l++);
                int op1=pretvori_u_int(s+k),op2=pretvori_u_int(s+j+1),rez;
                switch(s[j]){
                    case '^':
                        if(op1==0 && op2<=0){
                            *ok=0;
                            return -1;
                        }
                        rez=pow(op1,op2);
                        break;
                    case '*':
                        rez=op1*op2;
                        break;
                    case '/':
                        if(op2==0){
                            *ok=0;
                            return -1;
                        }
                        rez=op1/op2;
                        break;
                    case '+':
                        rez=op1+op2;
                        break;
                    case '-':
                        rez=op1-op2;
                        break;
                }
                obrisi(s+k,s+l+1);
                umetni(s+k,pretvori_u_string(rez,stmp));
                j+=duzina(stmp)-(j-k)-1;
            }
        }
    }
    return pretvori_u_int(s);
}

int main() {
    int ok;
    int rez = izracunaj("11+111+1234^-7--2^4", &ok);
    if (ok)
        printf("rezultat je: %d\n", rez);
    else
        printf("greska\n");
    return 0;
}

