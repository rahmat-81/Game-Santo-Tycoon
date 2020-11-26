#include "listardin.h"
#include <stdio.h>
#include <stdlib.h>

List MakeList() 
/* I.S. sembarang
   F.S. Terbentuk List kosong dengan ukuran InitialSize */
{
    List list;

    list.A = (ElType *) malloc(InitialSize * sizeof(ElType));
    list.Capacity = InitialSize;
    list.Neff = 0;

    return list;
}

void DeallocateList(List *list)
/* I.S. List terdefinisi
   F.S. list->A terdealokasi */
{
    free(list->A);
}


boolean IsEmpty(List list)
/* Fungsi untuk mengetahui apakah suatu list kosong.
   Prekondisi: list terdefinisi */
{
    return list.Neff == 0;
}


int Length(List list) 
/* Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
   Prekondisi: list terdefinisi */
{
    return list.Neff;
}


ElType Get(List list, IdxType i) 
/* Mengembalikan elemen list L yang ke-I (indeks lojik).
   Prekondisi: list tidak kosong, i di antara 0..Length(list). */
{
    return list.A[i];
}


int GetCapacity(List list) 
/* Fungsi untuk mendapatkan kapasitas yang tersedia.
   Prekondisi: list terdefinisi */
{
    return list.Capacity;
}


void InsertFirst(List *list, ElType el) 
/* Fungsi untuk menambahkan elemen baru di awal list.
   Prekondisi: list terdefinisi */
{
    InsertAt(list, el, 0);
}

void InsertLast(List *list, ElType el) 
/* Fungsi untuk menambahkan elemen baru di akhir list.
   Prekondisi: list terdefinisi */
{
    int insertAt = Length(*list);
    InsertAt(list, el, insertAt);
}

void InsertAt(List *list, ElType el, IdxType i) 
/* Fungsi untuk menambahkan elemen baru di index ke-i
   Prekondisi: list terdefinisi, i di antara 0..Length(list). */
{
    int length = Length(*list);
    int capacity = GetCapacity(*list);

    if (length == capacity) {
        int newCapacity = capacity + InitialSize;
        ElType *array = (ElType *) malloc(newCapacity * sizeof(ElType));
        for (int a = 0; a < length; a++) {
            array[a] = Get(*list, a);
        }
        free(list->A);
        
        list->A = array;
        list->Capacity = newCapacity;
    }

    for (int a = length - 1; a >= i; a--) {
        list->A[a + 1] = list->A[a];
    }

    list->A[i] = el;
    list->Neff++;
}

