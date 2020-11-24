#include<stdio.h>
#include "matrix.h"

// void SetElement(Matrix* M, int i, int j, ElType Pelanggan)
// /* menyimpan data pelanggan di map pada koordinat i+1,j+1 (menghitung dari batas luar peta) */
// {
//     Elemen(*M, i, j) = Pelanggan;
// }
// void MakeEmptyMatrix(Matrix *M)
// /* Membuat Map Kosong yang siap untuk diisi elemen lain */
// {
//     int i = 0;
//     int j = Baris;
//     int k = 0;
//     int l = Kolom;

//     for(i; i <= j; i++){
//         if((i == 0) || (i == Baris)){
//             (*M).Elmt[i][j] = '*';
//         } else {
//             (*M).Elmt[i][j] = ' ';
//         }
//         for(j; j <= Kolom; j++){
//             if((j == 0) || (j == Kolom)){
//                 (*M).Elmt[i][j] = '*';
//             } else {
//                 (*M).Elmt[i][j] = ' ';
//             }
//         }
//     }
// }
// void ShowMap(Matrix M)
// /* Mencetak Map ke layar */
// {
//     int i, j;

//     for(i = 0; i <= Baris; i++){
//         for(j = 0; j <= Kolom; j++){
//             printf("%c", M.Elmt[i][j]);
//         }
//         printf("\n");
//     }
// }

void MakeMatrix (int NB, int NK, Matrix* M)
/* Membuat sebuah matriks kosong berukuran (NB+1)x(NK+1) yang juga termasuk border dari map */
/* I.S. NB dan NK adalah angka yang valid, tidak lebih dari BarisMax dan KolomMaks */
/* F.S. Matriks M dengan ukuran NB X NK berhasil dibuat */
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

boolean IsIdxValid(int NB, int NK)
/* Mengecek apakah NB dan NK ada dalam range BarisMax dan KolomMax */
/* Mengirimkan true jika i,j adalah indeks yang valid untuk matrix apapun*/
{
    return ((NB >= BarisMin && NB <= BarisMax) && (NK >= KolomMin && NK <= KolomMax));
}

void MakeEmptyMap (Matrix *M, int NB, int NK)
/* Melakukan penulisan terhadap matrix */
/* I.S. NB dan NK valid */
/* F.S. tercipta sebuah map kosong dengan border berupa '*', dan elemen lainnya berupa ' ' */
{
    /* Kamus Lokal */
    int i = 0;
    int j = 0;
    ElType blank = ' ';
    /* Algoritma */
    if (IsIdxValid(NB, NK)){
        MakeMatrix(NB, NK, M); /* Membuat matriks dengan NBrsEff dan NKolEff */
        for(i; i <= NBrsEff(*M); i++){
            for(j; j <= NKolEff(*M); j++){
                SetElementMatrix(M, i, j, blank);
            }
        }
    }

}

void SetElementMatrix (Matrix *M, int i, int j, ElType X)
/* I.S. IsIdxValid(i,j) */
/* F.S. Elemen matriks pada indeks i,j akan menjadi X */
{
    Elemen(*M, i, j) = X;
}

void PrintMatriks(Matrix M)
/*I.S. M terdefinisi */
/* F.S. Nilai Elmt(M,i,j) tercetak pada layar per baris, masing masing baris dipisahan dengan spasi */
{
    /* Kamus Lokal */
    int i, j = 0;
    /* Algoritma */
    for (int a = 0; a <= NBrsEff(M); a++){
        printf("%c", '*');    
        // printf("here");
    } /* print batas peta atas */
    printf("\n");
    for(i; i <= NBrsEff(M); i++){
        printf("%c", '*'); /*print batas peta kiri */
        for(j; j <= NKolEff(M); j++){
            // printf("masuk loop");
            if (j == NKolEff(M)){
                printf("%c", Elemen(M,i,j));
                printf("%c\n", '*'); /* print batas peta kanan */
            } else {
                printf("%c", Elemen(M,i,j));
            }
        }
    }
    for (int a = 0; a <= NBrsEff(M); a++){
        printf("%c", '*');
    }
}