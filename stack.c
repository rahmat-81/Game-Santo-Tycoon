
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S){
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
    (*S).T = (infotype *) malloc(MaxEl * sizeof(infotype));
    (*S).TOP = Nil;
}

boolean IsStackEmpty(Stack S){
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
    return ((S).TOP == Nil);
}

boolean IsStackFull(Stack S){
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
    return ((S).TOP == MaxEl);
}

/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, infotype X){
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/* F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
    if(!IsStackFull(*S)){
        S->T[Top(*S)] = X;
        Top(*S)++;
    }
}

void Pop(Stack *S, infotype *X){
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
    if(!IsStackEmpty(*S)){
        *X = InfoTop(*S);
        Top(*S)--;
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
        CreateEmptyStack(&Stemp);
        if (IsStackFull(*S)){
            while((*S).TOP != 0){
                Pop(S, &L);
                Push(&Stemp, L);
            }
            Pop(S, &del); //elemenpaling bawah
            while(!IsStackEmpty(Stemp)){
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
    Stack temp;
    infotype X;
    CreateEmptyStack(&temp);
    while(!IsStackEmpty(*S)){
        Pop(S, &X);
        Push(&temp, X);
    }
    CopyStack(temp, S);
}


void CopyStack (Stack Sin, Stack* Sout)
/* Membuat salinan Sin */
/* I.S. Sin terdefinisi, Sout sembarang */
/* F.S. Sout berisi salinan Sin yang identik */
{
    Stack temp;
    infotype X;
    CreateEmptyStack(&temp);

    while(!IsStackEmpty(Sin)){
        Pop(&Sin, &X);
        Push(&temp, X);
    }
    CreateEmptyStack(Sout);
    while(!IsStackEmpty(temp)){
        Pop(&temp, &X);
        Push(Sout, X);
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
    int i = 1; /* untuk nomor komponen */
    if(IsStackEmpty(S)){
        printf("Belum ada komponen yang terpasang.\n");
    } else {
        CopyStack (S, &Stemp);
        InverseStack(&Stemp);
        while (!IsStackEmpty(Stemp))
        {
            Pop(&Stemp, &X);
            printf(" %d. %s\n", i, Nama(X));
            i++;
        }
    }
}


