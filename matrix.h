#ifndef _MATRIKS_H
#define _MATRIKS_H

#include "boolean.h"
// #include "mesinkar.h"

#define KolomMax 29
#define BarisMax 19
#define KolomMin 0
#define BarisMin 0

// typedef int indeks;
typedef char ElType;
typedef struct{
    ElType Elmt[BarisMax + 1][KolomMax + 1];
    int NBrsEff;
    int NKolEff;
    
} Matrix;
/* SELEKTOR */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elemen(M,i,j) (M).Elmt[(i)][(j)]


// void SetElement(Matrix* M, int i, int j, ElType Pelanggan);
// /* menyimpan data pelanggan di map pada koordinat i+1,j+1 (menghitung dari batas luar peta) */
// void MakeEmptyMatrix(Matrix *M);
// /* Membuat Map Kosong yang siap untuk diisi elemen lain */
// void ShowMap(Matrix M);
// /* Mencetak Map ke layar */

void MakeMatrix (int NB, int NK, Matrix* M);
/* Membuat sebuah matriks kosong berukuran (NB+2)x(NK+2) yang juga termasuk border dari map */
/* I.S. NB dan NK adalah angka yang valid, tidak lebih dari BarisMax dan KolomMaks */
/* F.S. Matriks M dengan ukuran NB+2 X NK+2 berhasil dibuat */

boolean IsIdxValid(int NB, int NK);
/* Mengecek apakah NB dan NK ada dalam range BarisMax dan KolomMax */
/* Mengirimkan true jika i,j adalah indeks yang valid untuk matrix apapun*/

void MakeEmptyMap (Matrix *M, int NB, int NK);
/* Melakukan penulisan terhadap matrix */
/* I.S. NB dan NK valid */
/* F.S. tercipta sebuah map kosong dengan border berupa '*' */

void SetElementMatrix (Matrix *M, int i, int j, ElType X);
/* I.S. IsIdxValid(i,j) */
/* F.S. Elemen matriks pada indeks i,j akan menjadi X */ 

void PrintMatriks(Matrix M);
/*I.S. M terdefinisi */
/* F.S. Nilai Elmt(M,i,j) tercetak pada layar per baris, masing masing baris dipisahan dengan spasi */
#endif