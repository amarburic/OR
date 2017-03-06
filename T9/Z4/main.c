#include <stdio.h>

void unesi(char* s, int duzina){
    int i=0;
    char znak=getchar();
    if(znak=='\n')znak=getchar();
    while(i<duzina-1 && znak!='\n'){
        *s++=znak;
        i++;
        znak=getchar();
    }
    *s='\0';
}

char* velika(char* s){
    char* p = s;
    while(*p){
        if(*p>='a' && *p<='z')
            *p-='a'-'A';
        p++;
    }
    return s;
}

int main() {
    char s[100];
    unesi(s,100);
	printf("%s", velika(s));
    return 0;
}

