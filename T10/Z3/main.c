#include <stdio.h>

char* rot13(char** s1){
    char* s = *s1;
    while(*s){
        if(*s>='a' && *s<='z')
            *s=((*s+13)>'z')?('a'+12-('z'-*s)):(*s+13);
        else if(*s>='A' && *s<='Z')
            *s=((*s+13)>'Z')?('A'+12-('Z'-*s)):(*s+13);
        s++;
    }
    return *s1;
}

int main() {
    char s[]="Dobar dan";
    char* s1 = s;
    printf("%s", rot13(&s1));
    return 0;
}

