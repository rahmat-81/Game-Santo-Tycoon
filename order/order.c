#include <stdio.h>
#include <stdlib.h>
#include "../order/order.h"


void CreateOrder(Order* O, int pemesan, List komponen, int invoice){

    Pemesan(*O) = pemesan;
    (*O).ListKomponen = komponen;
    Invoice(*O) = invoice;
    NomorOrder(*O) = rand() % 40;
}
Order GenerateOrder(List inventory, int JmlOrang)
/* fungsi untuk generate list of components to order */
{
    List pesanan = MakeList();
    /* asumsi awal bahwa kita memiliki 40 jenis komponen, indeks 0-4 adalah mobo, 
    indeks 5-9 adalah cpu, and so on */
    Order newOrder;

    int i = 0;
    int randint;
    int TotalHarga = 0;
    for(i; i < 8; i++){
        /* membuat 8 elemen */ 
        randint = (rand() % 5) + 5*i; /* mod 5 supaya nilainya antara 0-4 */
        /* ditambah 4*i karena tergantung kategorinya, 0-4 mobo, 5-9 cpu, dll */
        /* setiap iterasi adalah setiap kategori. iterasi 1 = mobo, iterasi 2 = cpu */
        ListEl RandomComponent;
        RandomComponent = Get(inventory, randint);
        TotalHarga += Harga(RandomComponent);
        InsertLast(&pesanan, RandomComponent, Jumlah(RandomComponent));
    }
    int no_pemesan = rand()%JmlOrang + 1;
    int harga_pesanan = TotalHarga + rand()%500 + 400; /* ambil keuntungan max $899 setiap order */
    CreateOrder(&newOrder, no_pemesan, pesanan, harga_pesanan);
    return newOrder;


}