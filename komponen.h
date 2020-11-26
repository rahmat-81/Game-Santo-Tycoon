#ifndef _KOMPONEN_H
#define _KOMPONEN_H

typedef struct{
    char* NamaBarang;
    int Kategori;
    int Harga;
    int Jumlah;
}Komponen;

/* Keterangan */
// kategori 1: motherboard
// kategori 2: CPU
// kategori 3: memory
// kategori 4: CPU Cooler
// kategori 5: Case
// kategori 6: GPU
// kategori 7: Storage
// kategori 8: PSU
// kategori 0: Build


#define Nama(K) (K).NamaBarang
#define Categ(K) (K).Kategori
#define Harga(K) (K).Harga
#define Jumlah(K) (K).Jumlah

void CreateComponent(Komponen* K, char* merek, int categ, int price, int jumlah);
#endif