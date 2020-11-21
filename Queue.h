#ifndef queue_H
#define queue_H
#include "boolean.h"
#include <stdlib.h>
#define Nil -1


typedef int infotype;
typedef int address;

typedef struct {
    infotype *T;
    address HEAD;
    address TAIL;
    int MaxEl;
} Queue;

#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

boolean IsEmpty (Queue Q);
boolean IsFull (Queue Q);
int NBElmnt (Queue Q);
void CreateEmpty (Queue *Q, int Max);
void DeAlokasi (Queue *Q);
void Enqueue (Queue * Q, infotype X);
void Dequeue (Queue *Q, infotype* X);



#endif