#include "Queue.h"
#include <stdio.h>
boolean IsQEmpty (Queue Q) {
    return (Head(Q) == Invalid && Tail(Q) == Invalid);
}

boolean IsQFull (Queue Q) {
    return (MaxEl(Q) == NBElmnt(Q));
}

int NBElmnt (Queue Q) {
    //KAMUS
    address i;
    int counter;
    //Algoritma   
    if (IsQEmpty(Q)){
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
    (*Q).T = (QInfo *) malloc (Max * sizeof(QInfo));
    if ((*Q).T != NULL){
        Head(*Q) = Invalid;
        Tail(*Q) = Invalid;
        MaxEl(*Q) = Max;
    }
}


void Dealokasi(Queue *Q){
    MaxEl(*Q) = 0;
    free(Q->T);
}


void Enqueue(Queue *Q, QInfo X) {
    if (!IsQFull(*Q)){    
        if (IsQEmpty(*Q)){
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

void Dequeue(Queue *Q, QInfo *X) {
    //Kamus
    address i;
    //Algoritma
    
    if (!IsQEmpty(*Q)){
        *X = InfoHead(*Q);  
        if (Head(*Q) == Tail(*Q)){
            Head(*Q) = Invalid;
            Tail(*Q) = Invalid;
        }
        else{
            Head(*Q)++;
            
        }
    }
}


