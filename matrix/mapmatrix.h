/* ********** Definisi TYPE MATRIX dengan indeks dan elemen CHARACTER ********** */

#ifndef MATRIX_H
#define MATRIX_H

#include "../boolean/boolean.h"
#include "../point/point.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define BrsMin 0
#define BrsMax 19
#define KolMin 0
#define KolMax 29

typedef int indeks; /* indeks baris, kolom */
typedef char ElType; 
typedef struct { 
	ElType Mem[BrsMax+1][KolMax+1];
   int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIX;
/* NBrsEff >= 1 dan NKolEff >= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIX *** */
void MakeMATRIX (int NB, int NK, MATRIX * M); 
/* Membentuk sebuah MATRIX "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIX" *** */
boolean IsIdxValid (int i, int j);
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIX M);
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIX M);
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIX M);
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIX M);
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIX M, indeks i, indeks j);
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */


/* ********** KELOMPOK BACA/TULIS ********** */ 
void CreateEmptyMap (MATRIX * M, int NB, int NK);
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIX(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void PrintMap (MATRIX M, POINT player);
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

void SetMapElement(MATRIX* M, int i, int j, char el);
/* I.S. IsIdxValid(i,j) */
/* F.S. Elemen matriks pada indeks i,j akan menjadi X */ 

#endif