#include <stdio.h>
#include "../boolean/boolean.h"
#include "mapmatrix.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIX *** */
void MakeMATRIX (int NB, int NK, MATRIX * M) 
/* Membentuk sebuah MATRIX "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIX" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return (i>=BrsMin && i<=BrsMax) && (j>=KolMin && j<=KolMax);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIX M)
/* Mengirimkan indeks baris terkecil M */
{
    return BrsMin;
}

indeks GetFirstIdxKol (MATRIX M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMin;
}

indeks GetLastIdxBrs (MATRIX M)
/* Mengirimkan indeks baris terbesar M */
{
    return NBrsEff(M)-1;
}

indeks GetLastIdxKol (MATRIX M)
/* Mengirimkan indeks kolom terbesar M */
{
    return NKolEff(M)-1;
}

boolean IsIdxEff (MATRIX M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return (i>=BrsMin && i<=GetLastIdxBrs(M)) && (j>=KolMin && j<=GetLastIdxKol(M));
}


/* ********** KELOMPOK BACA/TULIS ********** */ 
void CreateEmptyMap (MATRIX * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIX(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
{
    MakeMATRIX(NB, NK, M);
    indeks i, j;
    for(i=0; i<NB ;i++){
        for(j=0; j<NK; j++){
            char el = ' ';
            Elmt(*M, i, j) = el;
        }
    }
}

void PrintMap (MATRIX M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    indeks a, b, i, j;
    for (a = 0; a <= (NKolEff(M) + 2); a++){
        printf("%c", '*');
    }
    printf("\n");
    for(i = 0; i < NBrsEff(M) ; i++){
        printf("%c  ", '*');
        for(j = 0; j < NKolEff(M); j++){
            if (i==(NBrsEff(M)-1) && j==(NKolEff(M)-1)){
                printf("%c  ", Elmt(M,i,j));
                printf("%c\n", '*');
            } else if(j==(NKolEff(M)-1)){
                printf("%c  ", Elmt(M,i,j));
                printf("%c\n", '*');
            } else {
                printf("%c", Elmt(M,i,j));
            }
        }
    }
    for (b = 0; b <= (NKolEff(M) + 2); b++){
        printf("%c", '*');
    }
}

void SetMapElement(MATRIX* M, int i, int j, char el)
/* I.S. IsIdxValid(i,j) */
/* F.S. Elemen matriks pada indeks i,j akan menjadi X */ 
{
    Elmt(*M, i-1, j-1) = el;
}