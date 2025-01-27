#ifndef _ORDER_H
#define _ORDER_H

#include "../listdinamis/listardin.h"
#include<time.h>

typedef struct{
    int NoPesanan;
    int Pemesan;
    List ListKomponen;
    int HargaInvoice;
} Order;

#define NomorOrder(O) (O).NoPesanan
#define Pemesan(O) (O).Pemesan
#define Invoice(O) (O).HargaInvoice
#define ListKomponen(O) (O).ListKomponen
#define GetKomponen(O, i) (O).ListKomponen[(i)]

void CreateOrder(Order *O, int pemesan, List komponen, int invoice);

Order GenerateOrder(List inventory, int JmlOrang);
/* fungsi untuk generate list of components to order */

#endif