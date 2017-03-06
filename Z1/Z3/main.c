#include <stdio.h>
int main() {

    int s;
    char ch;
    s=0;
    printf("Unesite znakove: ");
    do{
        scanf("%c",&ch);
        if(ch>='0' && ch<='9')
            s+=ch-'0';
    }while(ch!='.');
    printf("Suma je: %d",s);
    return 0;
}

