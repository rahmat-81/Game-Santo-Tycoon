#include "mesinkata.h"
boolean EndKata;
Kata CKata;

void IgnoreBlank() {
/* Mengabaikan satu atau beberapa BLANK
I.S.: CC sembarang
F.S.: CC ≠ BLANK */
/* Kamus Lokal */
/* Algoritma */
while (CC == BLANK) {
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
        if (CC != BLANK){
        i++;}
    }
    while (i<3);
    CKata.Length=i;
    ADV();
}
int ChartoInt(char C){
    if (C=='0'){
        return 0;
    }
    else {
        return 1;
    }
    
}
POINT BacaFileMasukinkePoint (){
    SalinKataPoint();
    return(MakePOINT(ChartoInt(CKata.TabKata[1]),ChartoInt(CKata.TabKata[2])));
}

int BacaJumlahGedung(){
    return (ChartoInt(CC));
}

void MembuatGedung(int JumlahGedung,POINT (*B),POINT (*S),POINT (*CC1)){
    (*B)=BacaFileMasukinkePoint();
    (*S)=BacaFileMasukinkePoint();
    (*CC1) = BacaFileMasukinkePoint();
    }
