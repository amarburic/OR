#include <stdio.h>

char konvertuj(char s, int b){
    if(b) return s;
    else return (s>='A' && s<='Z')?(s+'a'-'A'):(s);
}

int strcmp(const char* s1, const char* s2, int velikamala){
    while(konvertuj(*s1,velikamala)==konvertuj(*s2,velikamala) && *s1!='\0'){
        s1++;
        s2++;
    }
    if(*s1=='\0'){
        if(*s2=='\0') return 0;
        else return -1;
    }
    return (konvertuj(*s1,velikamala)<konvertuj(*s2,velikamala))?(-1):(1);
}

int main() {
    printf("Tutorijal 9, Zadatak 7");
    return 0;
}

