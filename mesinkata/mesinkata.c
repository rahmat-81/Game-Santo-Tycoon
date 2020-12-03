#include "../mesinkata/mesinkata.h"
#include "../mesinkar/mesinkar.h"
#include "../point/point.h"
#include "../listdinamis/listdinamispoint.h"
#include "../matrix/mapmatrix.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank() {
/* Mengabaikan satu atau beberapa BLANK
I.S.: CC sembarang
F.S.: CC ≠ BLANK */
/* Kamus Lokal */
/* Algoritma */
while (CC == BLANK || CC =='\n') {
ADV();
} /* CC != BLANK */
}

void INITAKSES(){
    START();
    IgnoreBlank();
}

void ADVNEW(){
    ADV();
    IgnoreBlank();
}

int BacaInteger(){
    int i=0;
    while(CC != BLANK && CC !='\n'){
        i=i*10+ChartoInt(CC);
        ADV();
    }
    return i;
}
void SalinKataPoint(){
    int i=0;
    do{
        CKata.TabKata[i]=CC;
        ADV();
        IgnoreBlank();
        if (CC != BLANK){
        i++;}
    }
    while (i<3);
    CKata.Length=i;
    ADV();
}
int ChartoInt(char C){
    return (C-'0');
    
}
POINT BacaFileMasukinkePoint (){
    SalinKataPoint();
    return(MakePOINT(ChartoInt(CKata.TabKata[1]),ChartoInt(CKata.TabKata[2])));
}

int BacaJumlahGedung(){
    return (ChartoInt(CC));
}

void MembuatGedung(int JumlahGedung,ListPoint *list){
    for(int j=0;j<JumlahGedung;j++){
        int c=BacaInteger();
        ADV();
        int x=BacaInteger();
        ADV();
        int y=BacaInteger();
        InsertLastPoint(list,MakePOINT(x,y));
        ADVNEW();
    }
    }

int BacaJumlahBaris (){
    return (ChartoInt(CC));
}

int BacaJumlahKolom (){
    return (ChartoInt(CC));
}
void BacaFilekeMatriks(int JumlahGedung, MATRIX *M){
    MakeMATRIX(JumlahGedung, JumlahGedung, M);
    indeks i, j;
    for(i=0; i<JumlahGedung ;i++){
        for(j=0; j<JumlahGedung; j++){
            char el = CC;
            Elmt(*M, i, j) = el;
            ADVNEW();
            }
            
        }
    }


Kata BacaKataDariCLI(){
    Kata C;
    char cc;
    char cnew[20];
    scanf("%c",&cc);
    int i=0;
    while ((cc != '\n')){
        C.TabKata[i]=cc;
        i++;
        scanf("%c",&cc);
    }
    C.Length=i;
    // cc = C.TabKata[i-1];
    // for(int j = 0; j <C.Length; j++){
    //     cnew[i] = C.TabKata[i];
    // }
    //     for(int j = 0; j <C.Length; j++){
    //     C.TabKata[i] = cnew[i];
    // }
    return C;
}

boolean isSamaKata(Kata Kata1, Kata Kata2){
    if (Kata1.Length==Kata2.Length){
       int i=0;
       boolean found=false;
       while (i < Kata1.Length && (!found)){
           if (Kata1.TabKata[i] != Kata2.TabKata[i]){
               found=true;
           }
           i++;
       }
       if (found){
           return false;
       }
       else {
           return true;
       }
       
    }
    else{
        return false;
    }
}
