#include <stdio.h>

int main() {
     int d,m;
     printf("Dan: ");
     scanf("%d",&d);
     printf("Mjesec: ");
     scanf("%d",&m);
     
     if(m<1 || m>12 || m<1 || m>31)
     {
          printf("Datum neispravan");
          return 0;
     }
     printf("Vaš znak je ");
     if(m==1 && d<=19 || m==12 && d>=22)
     printf("Jarac");
     if(m==1 && d>=20 || m==2 && d<=18)
     printf("Vodolija");
     if(m==2 && d>=19 || m==3 && d<=20)
     printf("Ribe");
     if(m==3 && d>=21 || m==4 && d<=19)
     printf("Ovan");
     if(m==4 && d>=20 || m==5 && d<=20)
     printf("Bik");
     if(m==5 && d>=21 || m==6 && d<=20)
     printf("Blizanci");
     if(m==6 && d>=21 || m==7 && d<=22)
     printf("Rak");
     if(m==7 && d>=23 || m==8 && d<=22)
     printf("Lav");
     if(m==8 && d>=23 || m==9 && d<=22)
     printf("Djevica");
     if(m==9 && d>=23 || m==10 && d<=22)
     printf("Vaga");
     if(m==10 && d>=23 || m==11 && d<=21)
     printf("Škorpija");
     if(m==11 && d>=22 || m==12 && d<=21)
     printf("Strijelac");
     printf("!\n");
     return 0;
}

