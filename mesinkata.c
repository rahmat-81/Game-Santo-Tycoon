#include "mesinkata.h"
#include "mesinkar.h"
#include "point.h"
#include "listdinamispoint.h"
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
void IgnoreBlink() {
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

void ADVKATA(){
    SalinKataPoint(); 
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
        if (j!=JumlahGedung-1){
            ADVNEW();
        }
    }
    }

int BacaJumlahBaris (){
    return (ChartoInt(CC));
}

int BacaJumlahKolom (){
    return (ChartoInt(CC));
}
