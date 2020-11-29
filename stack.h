
#ifndef stack_H
#define stack_H
#include <stdio.h>
#include "komponen.h"
#include "boolean.h"

#define Nil -1
#define MaxEl 8

typedef Komponen infotype;
typedef int address;

typedef struct
{
    infotype* T;
    address TOP;
} Stack;

/* Definisi stack S kosong : S.TOP = Nil */
/* S.TOP = jumlah element stack */
/* S.T[S.TOP-1] = element paling atas */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsStackEmpty(Stack S);
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
boolean IsStackFull(Stack S);
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
void Pop(Stack *S, infotype *X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

/* ********** Operator Tambahan ********* */
void ForcePush(Stack *S, infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S mungkin penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1
        Apabila S penuh, buang element paling bawah dari S dan masukkan X sebagai TOP
        Contoh: S berisi a b c d e f g h i j, setelah melakukan ForcePush(S, "k")
        S berisi b c d e f g h i j k */

void InverseStack(Stack *S);
/* Membalik isi suatu Stack */
/* I.S. S terdefinisi */
/* F.S. Isi S terbalik dari posisi semula */

void CopyStack (Stack Sin, Stack Sout);
/* Membuat salinan Sin */
/* I.S. Sin terdefinisi, Sout sembarang */
/* F.S. Sout berisi salinan Sin yang identik */

void PrintStack (Stack S);
/* I.S. S terdefinisi, mungkin kosong */ 
/* F.S. Isi S tertulis di layar dari bottom ke top (hasil inverse). */ 
/* Di akhir penulisan, S kembali ke kondisi I.S. */ 
/* Jika S kosong, tuliskan “Stack kosong” */ 

int NBAssembled(Stack S);
/* menunjukkan berapa banyak komponen yang terpasang */

#endif
