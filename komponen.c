#include<stdio.h>
#include "komponen.h"

void CreateComponent(Komponen* K, char* merek, char* categ, int price){
    Nama(*K) = merek;
    Categ(*K) = categ;
    Harga(*K) = price;
}
