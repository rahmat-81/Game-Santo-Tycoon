#include "../mesinkar/mesinkar.h"
#include "../mesinkata/mesinkata.h"
#include "../point/point.h"
#include "stdio.h"
#include "stdlib.h"
#include "../listdinamis/listdinamispoint.h"
#include "../matrix/mapmatrix.h"
#include "../command/command.h"

int main(){
    InsisiasiCommand();
    START();
    int NB = BacaInteger();
    ADV();
    int NK =BacaInteger();
    IgnoreBlank();
    int JumlahGedung=BacaInteger();
    ADVNEW();
    ListPoint listpoint=MakeListPoint(JumlahGedung);
    MembuatGedung(JumlahGedung,&listpoint);
    MATRIX Graf;
    BacaFilekeMatriks(JumlahGedung,&Graf);
    PrintMap(Graf);
    printf("\n");
    

    boolean endgame=false;
    Kata CCommand;
    while (endgame==false){
        CCommand=BacaKataDariCLI();
        if (isSamaKata(CCommand,STARTBUILD)){
            printf("%s",CCommand.TabKata);
            endgame=true;
        }
    } 
    return 0;
}
