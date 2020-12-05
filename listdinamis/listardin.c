#include "listardin.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

List MakeList() 
/* I.S. sembarang
   F.S. Terbentuk List kosong dengan ukuran InitialSize */
{
    List list;

    list.A = (ListEl *) malloc(InitialSize * sizeof(ListEl));
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


ListEl Get(List list, IdxType i) 
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


void InsertFirst(List *list, ListEl el, int jumlah) 
/* Fungsi untuk menambahkan elemen baru di awal list.
   Prekondisi: list terdefinisi */
{
    InsertAt(list, el, 0, jumlah);
}

void InsertLast(List *list, ListEl el, int jumlah) 
/* Fungsi untuk menambahkan elemen baru di akhir list.
   Prekondisi: list terdefinisi */
{
    int insertAt = Length(*list);
    InsertAt(list, el, insertAt, jumlah);
}

void InsertAt(List *list, ListEl el, IdxType i, int jumlah) 
/* Fungsi untuk menambahkan elemen baru di index ke-i
   Prekondisi: list terdefinisi, i di antara 0..Length(list). */
{
    int length = Length(*list);
    int capacity = GetCapacity(*list);

    if (length == capacity) {
        int newCapacity = capacity + InitialSize;
        ListEl *array = (ListEl *) malloc(newCapacity * sizeof(ListEl));
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
    /* analisis kondisi dimana elemen komponen sudah ada, tinggal menambahkan jumlah */
    
    IdxType where = DoesComponentExist(*list, el); /* mencari indeks komponen */

    if (where != -1){
        /* ditemukan komponen yang sama dengan yg ingin di insert */
        Jumlah(list->A[where]) += jumlah;
    } else {
        list->A[i] = el;
        Jumlah(list->A[i]) = jumlah;
        list->Neff++;
    }
}

IdxType DoesComponentExist(List list, ListEl komponen)
/* fungsi yang mengembalikan indeks dari komponen pada list, jika ada/ */
/* I.S. list mungkin kosong */
/* F.S. jika komponen ditemukan, indeks dari komponen tersebut menjadi parameter output. Jika tidak ditemukan, return -1 */
{
    IdxType idxfound = 0;
    boolean found = false;
    while((idxfound < Length(list) && !found)){
        if (Nama(list.A[idxfound]) == Nama(komponen)){
            found = true;
        } else {
            idxfound++;
        }
    }
    if (found){
        return idxfound;
    } else {
        return -1;
    }
}

void PrintList(List L)
{
    // int i = 1;
    // int idx = 0;
    // if(L.Neff > 0){
    //     for(idx; idx < L.Neff; idx++){
    //         printf("%d. %s\n", i, Nama(Get(L, idx)));
    //     }
    // } else {
    //     printf("Kosong\n");
    // }
    IdxType iteration = 0;
    if(Length(L) != 0){
        while(iteration < Length(L)){
            printf("%d. %s (%d)\n", iteration+1, Nama(L.A[iteration]), Jumlah(L.A[iteration]));
            iteration++;
        }
    } else {
        printf("Kosong\n");
    }
}

void DeleteComponent(List* L, ListEl X)
/* menghapus komponen list */
{
    int i = 0;
    int where = DoesComponentExist(*L, X);
    if (where != -1){
        /* komponen ada di list */
        if (where == L->Neff-1){
            /* ditemukan di indeks terakhir */
            if(Jumlah(Get(*L, where)) < 2){
            L->Neff--;
            } else {
                Jumlah(L->A[where]) -= 1;
            }
        } else {
            /* ditemukan di tengah atau awal */
            if(Jumlah(Get(*L, where)) >= 2){
                Jumlah(L->A[where]) -= 1;
            } else {            
                for(where; where < L->Neff-1; where++){
                    /* geser rata kiri */
                    L->A[where] = L->A[where+1];
                }
                L->Neff--;
            }
        }
    }

}

boolean DoesBuildExists(List *L, ListEl* X){
    int i = 0;
    boolean found = false;
    while(i < L->Neff && !found){
        if(Categ(L->A[i]) == 9){
            found = true;
        } else {
            i++;
        }
    }
    if(found){
        *X = L->A[i];
        return true;
    } else {
        return false;
    }
}

int Search(char* test,List list){
    boolean found=false;
    int i=0;
    int result=0;
    while(found==false && i<list.Neff){
        if (strcmp(test,list.A[i].NamaBarang)==0){
            found=true;
            result=i;
            
        }
        i++;
    }
    return result;
}