#include "mesinkar.h"
#include "mesinkata.h"
#include "point.h"
#include "stdio.h"
#include "stdlib.h"

int main(){
    START();
    int JumlahGedung=BacaJumlahGedung();
    POINT B,S,CC1;
    MembuatGedung(JumlahGedung,&B,&S,&CC1);
    TulisPOINT(B);
    TulisPOINT(S);
    TulisPOINT(CC1);
    return 0;
}
