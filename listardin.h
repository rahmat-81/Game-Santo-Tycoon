#ifndef __DYNAMIC_LIST__
#define __DYNAMIC_LIST__
#include "boolean.h"

#define InitialSize 100

typedef int IdxType;
typedef int ElType;
typedef struct {
    ElType *A;
    int Capacity;
    int Neff;
} List;


List MakeList();
/* I.S. sembarang
   F.S. Terbentuk List kosong dengan ukuran InitialSize */

void DeallocateList(List *list);
/* I.S. List terdefinisi
   F.S. list->A terdealokasi */

boolean IsEmpty(List list);
/* Fungsi untuk mengetahui apakah suatu list kosong.
   Prekondisi: list terdefinisi */

int Length(List list);
/* Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
   Prekondisi: list terdefinisi */

ElType Get(List list, IdxType i);
/* Mengembalikan elemen list L yang ke-I (indeks lojik).
   Prekondisi: list tidak kosong, i di antara 0..Length(list). */

int GetCapacity(List list);
/* Fungsi untuk mendapatkan kapasitas yang tersedia.
   Prekondisi: list terdefinisi */

void InsertAt(List *list, ElType el, IdxType i);
/* Fungsi untuk menambahkan elemen baru di index ke-i
   Prekondisi: list terdefinisi, i di antara 0..Length(list). */

void InsertLast(List *list, ElType el);
/* Fungsi untuk menambahkan elemen baru di akhir list.
   Prekondisi: list terdefinisi */

void InsertFirst(List *list, ElType el);
/* Fungsi untuk menambahkan elemen baru di awal list.
   Prekondisi: list terdefinisi */
 
#endif