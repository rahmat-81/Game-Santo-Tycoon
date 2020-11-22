#include "Queue.h"
#include <stdio.h>
boolean IsEmpty (Queue Q) {
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (Queue Q) {
    return (MaxEl(Q) == NBElmnt(Q));
}

int NBElmnt (Queue Q) {
    //KAMUS
    address i;
    int counter;
    //Algoritma   
    if (IsEmpty(Q)){
        return 0;
    }
    else {
        counter = 0;
        for (i = Head(Q); i <= Tail(Q); i++) {
            counter++;
        }
        return counter;
    }
}

void CreateEmpty(Queue *Q, int Max){
    (*Q).T = (infotype *) malloc (Max * sizeof(infotype));
    if ((*Q).T != NULL){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxEl(*Q) = Max;
    }
}


void Dealokasi(Queue *Q){
    MaxEl(*Q) = 0;
    free(Q->T);
}


void Enqueue(Queue *Q, infotype X) {
    if (!IsFull(*Q)){    
        if (IsEmpty(*Q)){
            Head(*Q) = 0;
            Tail(*Q) = 0;
            InfoHead(*Q) = X;
            InfoTail(*Q) = X;
        }
        else{
            Tail(*Q)++;
            InfoTail(*Q) = X;
        }
    }

}

void Dequeue(Queue *Q, infotype *X) {
    //Kamus
    address i;
    //Algoritma
    
    if (!IsEmpty(*Q)){
        *X = InfoHead(*Q);  
        if (Head(*Q) == Tail(*Q)){
            Head(*Q) = Nil;
            Tail(*Q) = Nil;
        }
        else{
            i = Head(*Q);

            while(i < Tail(*Q)){
                Q->T[i] = Q->T[i+1];
                i++;
            }
            Tail(*Q)--;
        }
    }
}


