#ifndef _KOMPONEN_H
#define _KOMPONEN_H

typedef struct{
    char* NamaBarang;
    char* Kategori;
    int Harga;
}Komponen;

#define Nama(K) (K).NamaBarang
#define Categ(K) (K).Kategori
#define Harga(K) (K).Harga

void CreateComponent(Komponen* K, char* merek, char* categ, int price);
#endif