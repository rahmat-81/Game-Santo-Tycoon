#include<stdio.h>
#include "komponen.h"

void CreateComponent(Komponen* K, char* merek, int categ, int price, int jumlah, int pemilik){
    Nama(*K) = merek;
    Categ(*K) = categ;
    Harga(*K) = price;
    Jumlah(*K) = jumlah;
    Pemilik(*K) = pemilik;
    
}
