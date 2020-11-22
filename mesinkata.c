#include "mesinkata.h"
boolean EndKata;
Kata CKata;
char Choice[100];

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

void ReadChoice(){
    printf("ENTER COMMAND:");
    scanf("%s\n",Choice);    
}

void PrintChoice(){
    printf("%s",Choice);
}