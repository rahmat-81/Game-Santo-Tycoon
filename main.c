#include "mesinkar.h"
#include "mesinkata.h"
#include "point.h"
#include "stdio.h"
#include "stdlib.h"
#include "listdinamispoint.h"

int main(){
    START();
    int NB = BacaInteger();
    printf("%d\n",NB);
    ADV();
    int NK =BacaInteger();
    printf("%d\n",NK);
    IgnoreBlank();
    int JumlahGedung=BacaInteger();
    ADVNEW();
    printf("%d\n",JumlahGedung);
    ListPoint listpoint=MakeListPoint(JumlahGedung);
    MembuatGedung(JumlahGedung,&listpoint);
    PrintListPoint(listpoint);
    return 0;
}
