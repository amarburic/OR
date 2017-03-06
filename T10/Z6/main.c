#include <stdio.h>

void obrisi(char* p1, char* p2){
    while(*p2)
        *p1++=*p2++;
    *p1='\0';
}

char* ukloni_komentare(char* s){
    char* poc=s+1, *tmp;
    while(*poc){
        if(*poc=='*' && *(poc-1)=='/'){
            tmp=poc+1;
            while(!(*tmp=='/' && *(tmp-1)=='*'))tmp++;
            obrisi(poc-1,tmp+1);
        }
        if(*poc=='/' && *(poc-1)=='/'){
            tmp=poc+1;
            while(!(*tmp=='\n' || *tmp=='\0'))tmp++;
            obrisi(poc-1,tmp);
        }
        poc++;
    }
    
    
    return s;
}

int main() {
    char kod[]="/*test*/ ovo ostaje \n // ovo se brise \n ovo ne";
    printf("%s",ukloni_komentare(kod));
    return 0;
}

