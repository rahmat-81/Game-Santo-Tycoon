#include "listdinamispoint.h"
#include <stdio.h>
#include <stdlib.h>

ListPoint MakeListPoint(int Capacity) 
/* I.S. sembarang
   F.S. Terbentuk ListPoint kosong dengan ukuran InitialSize */
{
    ListPoint list;

    list.A = (POINT *) malloc(Capacity* sizeof(POINT));
    list.Capacity = Capacity;
    list.Neff = 0;

    return list;
}

void DeallocateListPoint(ListPoint *list)
/* I.S. ListPoint terdefinisi
   F.S. list->A terdealokasi */
{
    free(list->A);
}


boolean IsEmptyPoint(ListPoint list)
/* Fungsi untuk mengetahui apakah suatu list kosong.
   Prekondisi: list terdefinisi */
{
    return list.Neff == 0;
}


int LengthPoint(ListPoint list) 
/* Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
   Prekondisi: list terdefinisi */
{
    return list.Neff;
}


POINT GetPoint(ListPoint list, IdxType i) 
/* Mengembalikan elemen list L yang ke-I (indeks lojik).
   Prekondisi: list tidak kosong, i di antara 0..Length(list). */
{
    return list.A[i];
}


int GetCapacityPoint(ListPoint list) 
/* Fungsi untuk mendapatkan kapasitas yang tersedia.
   Prekondisi: list terdefinisi */
{
    return list.Capacity;
}


void InsertFirstPoint(ListPoint *list, POINT el) 
/* Fungsi untuk menambahkan elemen baru di awal list.
   Prekondisi: list terdefinisi */
{
    InsertAtPoint(list, el, 0);
}

void InsertLastPoint(ListPoint *list, POINT el) 
/* Fungsi untuk menambahkan elemen baru di akhir list.
   Prekondisi: list terdefinisi */
{
    int insertAt = LengthPoint(*list);
    InsertAtPoint(list, el, insertAt);
}

void InsertAtPoint(ListPoint *list, POINT el, IdxType i) 
/* Fungsi untuk menambahkan elemen baru di index ke-i
   Prekondisi: list terdefinisi, i di antara 0..Length(list). */
{
    int length = LengthPoint(*list);
    int capacity = GetCapacityPoint(*list);

    if (length == capacity) {
        int newCapacity = capacity + list->Capacity;
        POINT *array = (POINT *) malloc(newCapacity * sizeof(POINT));
        for (int a = 0; a < length; a++) {
            array[a] = GetPoint(*list, a);
        }
        free(list->A);
        
        list->A = array;
        list->Capacity = newCapacity;
    }

    for (int a = length - 1; a >= i; a--) {
        list->A[a + 1] = list->A[a];
    }
    /* analisis kondisi dimana elemen komponen sudah ada, tinggal menambahkan jumlah */

        list->A[i] = el;
        list->Neff++;
    
}

void PrintListPoint(ListPoint L)
{
    int i = 1;
    int idx = 0;
    if(L.Neff > 0){
        for(idx; idx < L.Neff; idx++){
            printf("%d. (%d,%d)\n", idx+1, L.A[idx].X, L.A[idx].Y);
        }
    } else {
        printf("Kosong\n");
    }
}
