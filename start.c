#include "mesinkar.h"
#include "mesinkata.h"
#include "point.h"
#include "stdio.h"
#include "stdlib.h"
#include "start.h"
extern POINT B,S,CC1;
int JumlahGedung;
POINT B,S,CC1;
void StartGame(){
    START();
    JumlahGedung=BacaJumlahGedung();
    MembuatGedung(JumlahGedung,&B,&S,&CC1);
    return 0;
}
