#include <stdio.h>
#include"../queue/Queue.h"
#include "../listdinamis/listardin.h"
#include "../komponen/komponen.h"

void CheckOrder(Queue Q) {
    //KAMUS LOKAL
    int i;
    //ALGORITMA
    i = 0;
    if (IsQEmpty(Q)) {
        printf("Tidak ada Order\n");
    }
    else {
        printf("Nomor Order : %d\n", Pemesan(InfoHead(Q)));
        printf("Invoice : $%d\n", Invoice(InfoHead(Q)));
        printf("Komponen :\n");
        //Print list komponen
        while(i < Length(ListKomponen(InfoHead(Q)))){
        printf("%d. %s (%d)\n", i+1, Nama(Get(ListKomponen(InfoHead(Q)), i)), Jumlah(Get(ListKomponen(InfoHead(Q)), i)));
        i++;
        }
    }
}
