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
    for(int i=0;i<JumlahGedung;i++){
        InsertLastPoint(list,BacaFileMasukinkePoint());
    }
    }

int BacaJumlahBaris (){
    return (ChartoInt(CC));
}

int BacaJumlahKolom (){
    return (ChartoInt(CC));
}
