#include <stdio.h>

int je_slovo(char c){
    return ((c>='a' && c<='z') || (c>='A' && c<='Z'));
}

char* izbaci_rijec(char* tekst, int rb){
    int neznak=1,n=0;
    char* p,*k, *kt=tekst, *tmp=tekst;
    while(*kt)kt++;
    while(*tmp){
        if(je_slovo(*tmp) && neznak){
            n++;
            
            neznak=0;
            if(n==rb){
                p=tmp;
                k=tmp;
                while(je_slovo(*k++));
                k--;
                while(k<=kt)
                    *p++=*k++;
                *p='\0';
                kt=p-1;
                
            }
        }
        else if(!je_slovo(*tmp)){
            neznak=1;
        }
        tmp++;
    }
    return tekst;
}
int main() {
    char tekst[] = "Isao sam auto-stopom do Zenice";
    izbaci_rijec(tekst, 4);
    printf("%s", tekst);
    return 0;
}

