#include "mapmatrix.h"
#include "point.h"

void PrintMap (MATRIX M, paramter posisi, ElType elemen)
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
    // print baris pertama
    for (a = 0; a <= (NKolEff(M) + 1); a++){
        printf("%c ", '*');
    }
    printf("\n");

    for(i = 0; i < NBrsEff(M) ; i++)
    {
        printf("%c ", '*'); // print kolom pertama

        for(j = 0; j < NKolEff(M); j++)
        {
            if (/* posisi sama */)
            {
                elemen =  posisi; // elemen yang dicetak
            }
            else
            {
                elemen = Elmt(M, i, j);
            }
            
            // cetak elemen
            if (i==(NBrsEff(M)-1) && j==(NKolEff(M)-1))
            {
                printf("%c ", elemen);
                printf("%c\n", '*');
            } 
            else if(j==(NKolEff(M)-1))
            {
                printf("%c ", elemen);
                printf("%c\n", '*');
            } 
            else 
            {
                printf("%c ", elemen);
            }
        }
    }
    // print baris terakhir
    for (b = 0; b <= (NKolEff(M) + 1); b++){
        printf("%c ", '*');
    }
}

// void PrintMap (MATRIX M, paramter posisiplayer, ElType elemen)
// /* I.S. M terdefinisi */
// /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
//    dipisahkan sebuah spasi */
// /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
// /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
// 1 2 3
// 4 5 6
// 8 9 10
// */
// {
//     indeks a, b, i, j;
//     // print baris pertama
//     for (a = 0; a <= (NKolEff(M) + 1); a++){
//         printf("%c ", '*');
//     }
//     printf("\n");

//     for(i = 0; i < NBrsEff(M) ; i++)
//     {
//         printf("%c ", '*'); // print kolom pertama

//         for(j = 0; j < NKolEff(M); j++)
//         {
//             if (/* posisi sama */)
//             {
//                 SetMapElement (*M, i, j, P); // mengganti elemen 
//             }
            
//             // cetak elemen
//             if (i==(NBrsEff(M)-1) && j==(NKolEff(M)-1))
//             {
//                 printf("%c ", elemen);
//                 printf("%c\n", '*');
//             } 
//             else if(j==(NKolEff(M)-1))
//             {
//                 printf("%c ", elemen);
//                 printf("%c\n", '*');
//             } 
//             else 
//             {
//                 printf("%c ", elemen);
//             }
//         }
//     }
//     // print baris terakhir
//     for (b = 0; b <= (NKolEff(M) + 1); b++){
//         printf("%c ", '*');
//     }
// }