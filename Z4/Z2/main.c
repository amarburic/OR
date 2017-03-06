#include <stdio.h>

int duzina(char* s){
    int i=0;
    while(*s++)i++;
    return i;
}

char* string_od_chara(char* s, char c, int n){
    int i;
    for(i=0;i<n;i++)
        s[i]=c;
    s[i]='\0';
    return s;
    
}

void umetni(char* poc, char* s){
    int i;
    for(i=duzina(poc)+duzina(s)-1;i>=duzina(s);i--)
        poc[i]=poc[i-duzina(s)];
    for(i=0;i<duzina(s);i++)
        poc[i]=s[i];
}

char* centriraj(char* str, int n){
    char temp[100];
    if(duzina(str)>=n)return str;
    umetni(str,string_od_chara(temp,' ',(n-duzina(str))/2));
    umetni(str+duzina(str),string_od_chara(temp,' ',n-duzina(str)));
    return str;
}

int main() {
    char n1[100] = "Bosna", n2[100] = "Hercegovina";
    char* p1 = centriraj(n1, 4);
    char* p2 = centriraj(n2, 25);
    printf ("'%s'\n'%s'", p1, p2);
    return 0;
}

