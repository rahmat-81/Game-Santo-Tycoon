#include "../mesinkar/mesinkar.h"
#include "../mesinkata/mesinkata.h"
#include "../point/point.h"
#include "stdio.h"
#include "stdlib.h"
#include "../listdinamis/listdinamispoint.h"
#include "../matrix/mapmatrix.h"
#include "../command/command.h"

char IntToChar(int i){
    return i +'0';
}
void ListPointtoMatrix(ListPoint list, MATRIX *M){
    for (int i=0;i<list.Neff;i++){
        if (i==0){
            SetMapElement(M,list.A[i].X,list.A[i].Y,'B');
        }
        else if (i==1){
            SetMapElement(M,list.A[i].X,list.A[i].Y,'S');
        }
        else{
            SetMapElement(M,list.A[i].X,list.A[i].Y,IntToChar(i-1));
        }
        
    }

}

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
    //PrintMap(Graf);
    //BacaFilekeMatriks(JumlahGedung,&Graf);
    printf("%d",ChartoInt('1'));
    //PrintMap(Graf);
    //printf("\n");
    MATRIX CHECK;
    CreateEmptyMap(&Graf,NB,NK);
    PrintMap(Graf);
    //ListPointtoMatrix(listpoint,&CHECK);
    //PrintMap(CHECK);

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
