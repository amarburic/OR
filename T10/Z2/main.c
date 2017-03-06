#include <stdio.h>

void unesi(char niz[], int velicina){
	char znak = getchar();
	if(znak=='\n')znak=getchar();
	int i = 0;
	while(i<velicina-1 && znak!='\n'){
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

void zamijeni_broj(char* s, int c) {
     char cifre[][6] = {"nula","jedan","dva","tri","cetiri","pet","sest","sedam","osam","devet"};
   	 int duzine[] = {3,4,2,2,5,2,3,4,3,4},i;
   	 while (*s != '\0') {
   		 if (*s == c + '0') {
   			 char* kraj = s;
   			 while (*kraj != '\0') kraj++;
   			 while (kraj > s) {
   				 *(kraj+duzine[c]) = *kraj;
   				 kraj--;
   			 }
   			 for(i=0;i<=duzine[c];i++)
   			    *s++=cifre[c][i];
   		 }
   		 s++;
   	 }
}

int main() {
    char s[100] = "Broj 123 je 2. po redu";
    zamijeni_broj(s, 2);
    printf("%s", s);
    return 0;
}

