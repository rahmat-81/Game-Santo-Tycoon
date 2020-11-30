#ifndef queue_H
#define queue_H
#include "../boolean/boolean.h"
#include <stdlib.h>
#include "../order/order.h"
#define Nil -1


typedef Order infotype;
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

boolean IsQEmpty (Queue Q);
boolean IsQFull (Queue Q);
int NBElmnt (Queue Q);
void CreateEmpty (Queue *Q, int Max);
void DeAlokasi (Queue *Q);
void Enqueue (Queue * Q, infotype X);
void Dequeue (Queue *Q, infotype* X);



#endif