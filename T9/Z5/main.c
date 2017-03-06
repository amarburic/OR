#include <stdio.h>

int prva_rijec(char* s){
    int broj=0,i=0,ima_slovo=0,razmak=1;
    while(s[i]!='\0'){
        if(s[i]==' '){
          
            razmak=1;
            s[i]='\0';            
        }else if(razmak){
            razmak=0;
            broj++;
            
        }
        i++;
    }
    return broj;
}
int main() {
    printf("Tutorijal 9, Zadatak 5");
    return 0;
}

