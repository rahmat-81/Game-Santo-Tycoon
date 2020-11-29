#include "mesinkar.h"
#include "mesinkata.h"
#include "point.h"
#include "stdio.h"
#include "stdlib.h"
#include "listdinamispoint.h"

int main(){
    START();
    printf("%c\n",CC);
    int NB = BacaJumlahBaris();
    ADV();
    IgnoreBlank();
    int NK =BacaJumlahKolom();
    printf("%c\n",CC);
    ADV();
    IgnoreBlank();
    int JumlahGedung=BacaJumlahGedung();
    ADV();
    IgnoreBlank();
    printf("%d\n",JumlahGedung);
    ListPoint listpoint=MakeListPoint(JumlahGedung);
    MembuatGedung(JumlahGedung,&listpoint);
    PrintListPoint(listpoint);
    return 0;
}
