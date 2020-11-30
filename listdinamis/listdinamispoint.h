#ifndef __DYNAMIC_LIST_POINT__
#define __DYNAMIC_LIST_POINT__
#include "boolean.h"
#include "point.h"



typedef int IdxType;
typedef struct {
    POINT *A;
    int Capacity;
    int Neff;
} ListPoint;


ListPoint MakeListPoint(int Capacity);
/* I.S. sembarang
   F.S. Terbentuk ListPoint kosong dengan ukuran InitialSize */

void DeallocateListPoint(ListPoint *list);
/* I.S. ListPoint terdefinisi
   F.S. list->A terdealokasi */

boolean IsEmptyListPoint(ListPoint list);
/* Fungsi untuk mengetahui apakah suatu list kosong.
   Prekondisi: list terdefinisi */

int LengthPoint(ListPoint list);
/* Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
   Prekondisi: list terdefinisi */

POINT GetPoint(ListPoint list, IdxType i);
/* Mengembalikan elemen list L yang ke-I (indeks lojik).
   Prekondisi: list tidak kosong, i di antara 0..Length(list). */

int GetCapacityPoint(ListPoint list);
/* Fungsi untuk mendapatkan kapasitas yang tersedia.
   Prekondisi: list terdefinisi */

void InsertAtPoint(ListPoint *list, POINT el, IdxType i);
/* Fungsi untuk menambahkan elemen baru di index ke-i
   Prekondisi: list terdefinisi, i di antara 0..Length(list). */

void InsertLastPoint(ListPoint *list, POINT el);
/* Fungsi untuk menambahkan elemen baru di akhir list.
   Prekondisi: list terdefinisi */

void InsertFirstPoint(ListPoint *list, POINT el);
/* Fungsi untuk menambahkan elemen baru di awal list.
   Prekondisi: list terdefinisi */
 
void PrintListPoint(ListPoint L);
/* mencetak isi list */

#endif