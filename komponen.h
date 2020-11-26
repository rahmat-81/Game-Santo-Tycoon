#ifndef _KOMPONEN_H
#define _KOMPONEN_H

typedef struct{
    char* NamaBarang;
    char* Kategori;
    int Harga;
    int Jumlah;
}Komponen;

#define Nama(K) (K).NamaBarang
#define Categ(K) (K).Kategori
#define Harga(K) (K).Harga
#define Jumlah(K) (K).Jumlah

void CreateComponent(Komponen* K, char* merek, int categ, int price, int jumlah);
#endif