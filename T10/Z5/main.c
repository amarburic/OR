#include <stdio.h>

char* whitespace(char* s){
    char* tmp = s,*tmp2;
    int ima_razmak=1;
    while(*tmp){
        if(*tmp=='\n' || *tmp=='\t')*tmp=' ';
        tmp++;
    }
    tmp=s;
    while(*tmp){
        if(*tmp==' ' && ima_razmak){
            tmp2=tmp+1;
            while(*tmp2){
                *(tmp2-1)=*tmp2;
                tmp2++;
            }
            *(tmp2-1)='\0';
        }
        else if(*tmp==' ' && !ima_razmak){
            ima_razmak=1;
            tmp++;
        }
        else{
            ima_razmak=0;
            tmp++;
        }
    }
    return s;
}

int main() {
    char tekst[100] = "  Ovo    \n      je\nneki              tekst  ";
    printf("%s", whitespace(tekst));
    return 0;
}

