#ifndef __DYNAMIC_LIST__
#define __DYNAMIC_LIST__
#include "../boolean/boolean.h"
#include "../komponen/komponen.h"

#define InitialSize 100

typedef int IdxType;
typedef Komponen ListEl;
typedef struct {
    ListEl *A;
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

ListEl Get(List list, IdxType i);
/* Mengembalikan elemen list L yang ke-I (indeks lojik).
   Prekondisi: list tidak kosong, i di antara 0..Length(list). */

int GetCapacity(List list);
/* Fungsi untuk mendapatkan kapasitas yang tersedia.
   Prekondisi: list terdefinisi */

void InsertAt(List *list, ListEl el, IdxType i, int jumlah);
/* Fungsi untuk menambahkan elemen baru di index ke-i
   Prekondisi: list terdefinisi, i di antara 0..Length(list). */

void InsertLast(List *list, ListEl el, int jumlah);
/* Fungsi untuk menambahkan elemen baru di akhir list.
   Prekondisi: list terdefinisi */

void InsertFirst(List *list, ListEl el, int jumlah);
/* Fungsi untuk menambahkan elemen baru di awal list.
   Prekondisi: list terdefinisi */

IdxType DoesComponentExist(List list, ListEl komponen);
/* fungsi yang mengembalikan indeks dari komponen pada list, jika ada/ */
/* I.S. list mungkin kosong */
/* F.S. jika komponen ditemukan, indeks dari komponen tersebut menjadi parameter output. Jika tidak ditemukan, return -1 */
 
void PrintList(List L);
/* mencetak isi list */

void DeleteComponent(List* L, ListEl X);
/* menghapus komponen list */
#endif