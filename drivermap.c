#include<stdio.h>
#include "mapmatrix.h"

int main(){
    MATRIX M;
    CreateEmptyMap(&M, 10, 15);
    PrintMap(M);
    printf("\n");
    SetMapElement(&M, 2, 3, 'c');
    PrintMap(M);
}