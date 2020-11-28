
#include "stack.h"
#include <stdio.h>

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack *S){
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
    (*S).TOP = Nil;
}

boolean IsEmpty(Stack S){
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
    return ( (S).TOP == Nil);
}

boolean IsFull(Stack S){
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
    return ( (S).TOP == MaxEl);
}

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infotype X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
    if(!IsFull(*S)){
        ((*S).TOP)++;
        (*S).T[(*S).TOP]=X; 
    }
}

void Pop(Stack *S, infotype *X){
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    if(!IsEmpty(*S)){
        *X = (*S).T[(*S).TOP];
        ((*S).TOP)--;
    }
}


/* ********** Operator Tambahan ********* */
void ForcePush(Stack *S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S mungkin penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1
        Apabila S penuh, buang element paling bawah dari S dan masukkan X sebagai TOP
        Contoh: S berisi a b c d e f g h i j, setelah melakukan ForcePush(S, "k")
        S berisi b c d e f g h i j k */
        // KAMUS
{
        Stack Stemp;
        infotype L;
        infotype del; // untuk menyimpan buangan elemen paling bawah
        // ALGORITMA
        CreateEmpty(&Stemp);
        if (IsFull(*S)){
            while((*S).TOP != 0){
                Pop(S, &L);
                Push(&Stemp, L);
            }
            Pop(S, &del); //elemenpaling bawah
            while(!IsEmpty(Stemp)){
                Pop(&Stemp, &L);
                Push(S, L);
            }
        }
        Push(S, X);
}

void InverseStack (Stack *S)
/* Membalik isi suatu Stack */
/* I.S. S terdefinisi */
/* F.S. Isi S terbalik dari posisi semula */
{
    infotype X;
    if (!IsEmpty(*S))
    {
        Pop(S, &X);
        InverseStack(S);
        Push(S, X);
    }
}


void CopyStack (Stack Sin, Stack Sout)
/* Membuat salinan Sin */
/* I.S. Sin terdefinisi, Sout sembarang */
/* F.S. Sout berisi salinan Sin yang identik */
{
    infotype X;

    while (!IsEmpty(Sin))
    {
        Pop(&Sin, &X);
        Push(&Sout, X);
    }
    while (!IsEmpty(Sout))
    {
        Pop(&Sout, &X);
        Push(&Sin, X);  
    }
}


void PrintStack (Stack S)
/* I.S. S terdefinisi, mungkin kosong */ 
/* F.S. Isi S tertulis di layar dari bottom ke top (hasil inverse). */ 
/* Di akhir penulisan, S kembali ke kondisi I.S. */ 
/* Jika S kosong, tuliskan “Stack kosong” */ 
{
    infotype X;
    Stack Stemp;
    CopyStack (S, Stemp);
    InverseStack(&Stemp);
    while (!IsEmpty(Stemp))
    {
        Pop(&Stemp, &X);
        printf("%d", X);
    }
}


