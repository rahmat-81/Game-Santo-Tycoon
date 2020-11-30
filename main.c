#include "mesinkar.h"
#include "mesinkata.h"
#include "point.h"
#include "stdio.h"
#include "stdlib.h"
#include "listdinamispoint.h"
#include "mapmatrix.h"
#include "command.h"

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
        if (isSamaKata(CCommand,FINISHBUILD)){
                printf("%s",CCommand.TabKata);
            
            endgame=true;
        }
    } 
    return 0;
}
