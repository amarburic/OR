#include <stdio.h>

int strcmp(const char* s1, const char* s2){
    while(*s1==*s2 && *s1!='\0'){
        s1++;
        s2++;
    }
    if(*s1=='\0'){
        if(*s2=='\0') return 0;
        else return -1;
    
    return (*s1<*s2)?(-1):(1);
}

int main() {
    printf("Tutorijal 9, Zadatak 6");
    return 0;
}