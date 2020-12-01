#include<stdio.h>
#include<stdlib.h>
#include "boolean/boolean.h"
#include "graf/graf.h"
#include "komponen/komponen.h"
#include "listdinamis/listdinamispoint.h"
#include "listdinamis/listardin.h"
#include "matrix/mapmatrix.h"
#include "mesinkata/mesinkata.h"
#include "mesinkar/mesinkar.h"
#include "order/order.h"
#include "point/point.h"
#include "queue/Queue.h"
#include "stack/stack.h"
#include "command/command.h"


// gcc -o testmain mainprogram.c graf/graf.c komponen/komponen.c listdinamis/listdinamispoint.c listdinamis/listardin.c matrix/mapmatrix.c mesinkata/mesinkata.c order/order.c point/point.c queue/Queue.c stack/stack.c mesinkar/mesinkar.c
// command untuk compile ^

char IntToChar(int i){
    return i +'0';
}
void ListPointtoMatrix(ListPoint list, MATRIX *M){
    for (int i=0;i<list.Neff;i++){
        if (i==0){
            SetMapElement(M,list.A[i].Y,list.A[i].X,'B');
        }
        else if (i==1){
            SetMapElement(M,list.A[i].Y,list.A[i].X,'S');
        }
        else{
            SetMapElement(M,list.A[i].Y,list.A[i].X,IntToChar(i-1));
        }
        
    }

}
void CheckOrder(Queue Q) {
    //KAMUS LOKAL
    int i;
    //ALGORITMA
    i = 0;
    if (IsQEmpty(Q)) {
        printf("Tidak ada Order\n");
    }
    else {
        printf("Nomor Order : %d\n", NomorOrder(InfoHead(Q)));
        printf("Pemesan: Pelanggan %d\n", Pemesan(InfoHead(Q)));
        printf("Invoice : $%d\n", Invoice(InfoHead(Q)));
        printf("Komponen :\n");
        //Print list komponen
        while(i < Length(ListKomponen(InfoHead(Q)))){
        printf("%d. %s\n", i+1, Nama(Get(ListKomponen(InfoHead(Q)), i)));
        i++;
        }
    }
}

void Shop (List* shop, List* Inventory, int* saldo)
{
    int beli; /* pilihan yang ingin dibeli */
    int jumlah; /* jumlah yang ingin dibeli*/
    int totalharga;
    ListEl komponen;

    /* Print komponen yang tersedia di shop */ 
    printf("Komponen yang tersedia: \n");
    if ((*shop).Neff > 0)
    {
        IdxType iteration = 0;
        if (Length(*shop) != 0)
        {
            while (iteration < Length(*shop))
            {
                printf("%d. %s - $%d\n", iteration+1, Nama((*shop).A[iteration]), Harga((*shop).A[iteration])); 
                iteration++;
            }
        }
    }
    else
    {
        printf ("Toko sedang kosong\n"); 
    }

    printf("Komponen yang ingin dibeli: ");
    scanf("%d", &beli);
    while(beli < 1 || beli > 40){
        printf("Tolong pilih komponen yang tersedia di toko!\n");
        printf("Komponen yang ingin dibeli: ");
        scanf("%d", &beli);
    }
    printf("\n");
    printf("Masukkan jumlah yang ingin dibeli: ");
    scanf("%d", &jumlah);
    printf("\n");

    // cek apakah saldo mencukupi komponen yang ingin dibeli 
    komponen = Get(*shop, beli-1);
    totalharga = ((Harga(komponen)) * jumlah);
    if (totalharga <= *saldo) // uang mencukupi
    {
        // cek apakah komponen sudah ada
        if (DoesComponentExist(*Inventory, komponen) > -1)
        /* komponen sudah ada di inventory */
        {
            // menambahkan komponen yang sudah ada
            Jumlah(komponen) = Jumlah(komponen) + jumlah; /* coba di tes, jalan ato ngga */
        }
        else 
        {   
            // menambahkan komponen baru
            InsertLast(Inventory, komponen, jumlah);
        }
        printf("Komponen berhasil dibeli!\n");
        *saldo -= totalharga;
    }
    else 
    {
        printf ("Uang tidak cukup!\n");
    }
    
}

void AddComponent(Stack *S, List* Inventory){
    int pilihan; /* menyimpan pilihan */
    Komponen pasang;
    printf("Komponen yang telah terpasang: \n");
    PrintStack(*S);
    printf("Komponen yang tersedia: \n");
    if ((*Inventory).Neff > 0){
        PrintList(*Inventory);
    }
    if(!IsStackFull(*S)){
        printf("Komponen yang ingin dipasang: ");
        scanf("%d", &pilihan);
        while(pilihan > Length(*Inventory) || pilihan < 1){
            printf("Komponen tidak valid!\n");
            printf("Komponen yang ingin dipasang: ");
            scanf("%d", &pilihan);
        }
        printf("\n");
        pasang = Get(*Inventory, pilihan-1);
        Jumlah(pasang) = 1; /* supaya yang dipasang hanya 1 */
        Push(S, pasang);
        DeleteComponent(Inventory, pasang);
        printf("Komponen berhasil di pasang!\n");
    } else {
        printf("Semua komponen telah terpasang. Silakan lakukan finish build!\n");
    }
}

List CreateShopList(){
    List ShopList = MakeList(); /* list untuk shop */
    Komponen mobo,mobo2,mobo3,mobo4,mobo5;
    Komponen cpu,cpu2,cpu3,cpu4,cpu5;
    Komponen ram,ram2,ram3,ram4,ram5;
    Komponen cooler,cooler2,cooler3,cooler4,cooler5;
    Komponen casing,casing2,casing3,casing4,casing5;
    Komponen gpu,gpu2,gpu3,gpu4,gpu5;
    Komponen ssd,ssd2,ssd3,ssd4,ssd5;
    Komponen psu,psu2,psu3,psu4,psu5;
    // List Inventory = MakeList(); /* list untuk inventory */
    /* membuat komponen untuk list shop */
    CreateComponent(&mobo, "Motherboard AT", 1, 150, 1);
    CreateComponent(&mobo2, "Motherboard ATX", 1, 200, 1);
    CreateComponent(&mobo3, "Motherboard Micro-ATX", 1, 250, 1);
    CreateComponent(&mobo4, "Motherboard Mini ITX", 1, 275, 1);
    CreateComponent(&mobo5, "Motherboard E-ATX", 1, 300, 1);
    CreateComponent(&cpu, "Ryzeng 5 4500X", 2, 400, 1);
    CreateComponent(&cpu2, "Intol i9 9800HK", 2, 700, 1);
    CreateComponent(&cpu3, "Ryzeng 7 2900X", 2, 450, 1);
    CreateComponent(&cpu4, "Intol Pentium Trio", 2, 75, 1);
    CreateComponent(&cpu5, "Apple Silicca", 2, 900, 1);
    CreateComponent(&ram, "Kingstool 16GB DDR4 2600 MHz", 3, 65, 1);
    CreateComponent(&ram2, "HyperVTX 8GB DDR4 3200 MHz", 3, 60, 1);
    CreateComponent(&ram3, "Sumsang 8GB DDR4 3200 MHz", 3, 75, 1);
    CreateComponent(&ram4, "VGan 4GB DDR3 2133 MHz", 3, 45, 1);
    CreateComponent(&ram5, "Kingston 16GB DDR4", 3, 150, 1);
    CreateComponent(&cooler, "Cooler Mister Silent Cooler", 4, 70, 1);
    CreateComponent(&cooler2, "Alsaya TBF-100 Cooler", 4, 50, 1);
    CreateComponent(&cooler3, "Cooler Mister Master Liquid", 4, 95, 1);
    CreateComponent(&cooler4, "Aigoo DarkFlash Cooler", 4, 70, 1);
    CreateComponent(&cooler5, "Cooler Mister MasterAir", 4, 100, 1);
    CreateComponent(&casing, "NZXT H510i", 5, 170, 1);
    CreateComponent(&casing2, "Fantich PULSE CG71", 5, 30, 1);
    CreateComponent(&casing3, "Armagendong XDS20", 5, 50, 1);
    CreateComponent(&casing4, "Simbanda", 5, 8, 1);
    CreateComponent(&casing5, "Imperial Fortress 303 RGB", 5, 45, 1);
    CreateComponent(&gpu, "NVDIA RTX 3090Ti", 6, 2200, 1);
    CreateComponent(&gpu2, "AMJ RX 5600M", 6, 90, 1);
    CreateComponent(&gpu3, "NVDIA GTX 1080Ti", 6, 150, 1);
    CreateComponent(&gpu4, "AMJ RX580", 6, 2000, 1);
    CreateComponent(&gpu5, "AMJ RX 5600XT", 6, 460, 1);
    CreateComponent(&ssd, "Sumsang EVO 980 1TB", 7, 230, 1);
    CreateComponent(&ssd2, "Sumsang EVO 860 120GB", 7, 80, 1);
    CreateComponent(&ssd3, "Kingstool 500GB SATA", 7, 95, 1);
    CreateComponent(&ssd4, "Seaglare Barracuda 250GB", 7, 99, 1);
    CreateComponent(&ssd5, "VGan HDD 1TB", 7, 60, 1);
    CreateComponent(&psu, "Armagendong PSU 600W", 8, 70, 1);
    CreateComponent(&psu2, "Panascanic PSU 500W", 8, 70, 1);
    CreateComponent(&psu3, "Corseer PSU 600W", 8, 70, 1);
    CreateComponent(&psu4, "Cooler Mister CX PSU 600W", 8, 70, 1);
    CreateComponent(&psu5, "ThermalGive PSU 550W", 8, 70, 1);

    /* masukkan komponen ke list */
    InsertLast(&ShopList, mobo, Jumlah(mobo));
    InsertLast(&ShopList, mobo2, Jumlah(mobo2));
    InsertLast(&ShopList, mobo3, Jumlah(mobo3));
    InsertLast(&ShopList, mobo4, Jumlah(mobo4));
    InsertLast(&ShopList, mobo5, Jumlah(mobo5));
    InsertLast(&ShopList, cpu, Jumlah(cpu));
    InsertLast(&ShopList, cpu2, Jumlah(cpu2));
    InsertLast(&ShopList, cpu3, Jumlah(cpu3));
    InsertLast(&ShopList, cpu4, Jumlah(cpu4));
    InsertLast(&ShopList, cpu5, Jumlah(cpu5));
    InsertLast(&ShopList, ram, Jumlah(ram));
    InsertLast(&ShopList, ram2, Jumlah(ram2));
    InsertLast(&ShopList, ram3, Jumlah(ram3));
    InsertLast(&ShopList, ram4, Jumlah(ram4));
    InsertLast(&ShopList, ram5, Jumlah(ram5));
    InsertLast(&ShopList, cooler, Jumlah(cooler));
    InsertLast(&ShopList, cooler2, Jumlah(cooler2));
    InsertLast(&ShopList, cooler3, Jumlah(cooler3));
    InsertLast(&ShopList, cooler4, Jumlah(cooler4));
    InsertLast(&ShopList, cooler5, Jumlah(cooler5));
    InsertLast(&ShopList, casing, Jumlah(casing));
    InsertLast(&ShopList, casing2, Jumlah(casing2));
    InsertLast(&ShopList, casing3, Jumlah(casing3));
    InsertLast(&ShopList, casing4, Jumlah(casing4));
    InsertLast(&ShopList, casing5, Jumlah(casing5));
    InsertLast(&ShopList, gpu, Jumlah(gpu));
    InsertLast(&ShopList, gpu2, Jumlah(gpu2));
    InsertLast(&ShopList, gpu3, Jumlah(gpu3));
    InsertLast(&ShopList, gpu4, Jumlah(gpu4));
    InsertLast(&ShopList, gpu5, Jumlah(gpu5));
    InsertLast(&ShopList, ssd, Jumlah(ssd));
    InsertLast(&ShopList, ssd2, Jumlah(ssd2));
    InsertLast(&ShopList, ssd3, Jumlah(ssd3));
    InsertLast(&ShopList, ssd4, Jumlah(ssd4));
    InsertLast(&ShopList, ssd5, Jumlah(ssd5));
    InsertLast(&ShopList, psu, Jumlah(psu));
    InsertLast(&ShopList, psu2, Jumlah(psu2));
    InsertLast(&ShopList, psu3, Jumlah(psu3));
    InsertLast(&ShopList, psu4, Jumlah(psu4));
    InsertLast(&ShopList, psu5, Jumlah(psu5));
    return ShopList;
}

void End_Day(Queue* OrderQueue, List Shop, int jmlorang){
    CreateEmpty(OrderQueue, 8); /* max 8 order dalam 1 hari */
    int i = 0;
    while(i < 8){
        Order O;
        O = GenerateOrder(Shop, jmlorang);
        Enqueue(OrderQueue, O);
        i++;
    }
}

void RemoveComponent(Stack *S, List* Inventory) {
    //Komponen
    infotype component;
    //Algoritma
    
    if (IsStackEmpty(*S)) {
        printf("Tidak ada komponen yang terpasang\n");
    }
    else {
        Pop(S, &component);
        printf("Komponen %s berhasil dicopot !\n", Nama(component));
        InsertLast(Inventory, component, Jumlah(component));
    }

}

void Deliver(POINT player, POINT customer, List* Inventory, Queue* Q){
    if(Absis(player) == Absis(customer) && Ordinat(player) == Ordinat(customer)){
        /* posisi player ada pada gedung pelanggan */
        ListEl Build;
        if(DoesBuildExists(Inventory, &Build)){
            QInfo BuildCustomer;
            Dequeue(Q, &BuildCustomer); /* dequeue orderan */
            DeleteComponent(Inventory, Build);
        } else {
            printf("Anda belum memiliki build yang selesai, silakan selesaikan build terlebih dahulu\n");
        }
    } else {
        printf("Anda belum berada di lokasi customer! Silakan lakukan command MOVE terlebih dahulu!\n");
    }
}


void Status(int Saldo, Queue Order, List Inventory, POINT player, ListPoint Point) {
    printf("Uang tersisa: $%d\n", Saldo);
    printf("Build yang sedang dikerjakan:");
    printf("pesanan %d untuk pelanggan %d\n", NomorOrder(InfoHead(Order)), Pemesan(InfoHead(Order)));
    printf("Lokasi: pemain sedang berada pada ");
    boolean found = false;
    int i = 0;
    
    while (!found && i < LengthPoint(Point)) {
        if (player.X == Point.A[i].X && player.Y == Point.A[i].Y) {
            found = true;
        }
        else
        {
            i++;
        }
        
    }

    if (found) {
        if (i==0) {
            printf("Base\n");
        }
        else if (i==1) {
            printf("Shop\n");
        }
        else
        {
            printf("Gedung %d\n", i-1);
        }
        
    }

    printf("Inventory anda:\n");
    PrintList(Inventory);
}

void FINISHBUILD(Stack Inventory, Order order){

    Stack InventoryCheck;
    Komponen X;
    CopyStack(Inventory,&InventoryCheck);
    if (IsStackEmpty(InventoryCheck)){
        printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.");
    }
    else{
        int i=0;
        boolean found=false;
        while ((!IsStackEmpty(InventoryCheck))&& (!found)){
            Pop(&InventoryCheck,&X);
            if (X.NamaBarang != order.ListKomponen.A[i-7].NamaBarang){
                found=true;
            }
            i++;
        }
        if (found){
            printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.");
        }
        else{
            printf("Pesanan %d telah selesai. Silahkan antar ke pelanggan %d!",order.NoPesanan,order.Pemesan);
        }
    }
    
}
/*
int main(){
    List ShopList = CreateShopList();
    int SaldoPlayer = 10000;
    List PlayerInventory = MakeList();
    Stack newBuild;
    Queue queuepesanan;
    int i = 0;


}

*/


// Test status
int main() {
    InsisiasiCommand();
    START();
    int NB = BacaInteger();
    ADV();
    int NK =BacaInteger();
    IgnoreBlank();
    int JumlahGedung=BacaInteger();
    ADVNEW();
    ListPoint listpoint=MakeListPoint(JumlahGedung);
    MembuatGedung(JumlahGedung,&listpoint);
    MATRIX Graf;
    //PrintMap(Graf);
    //BacaFilekeMatriks(JumlahGedung,&Graf);
    printf("%d",ChartoInt('1'));
    //PrintMap(Graf);
    //printf("\n");
    MATRIX CHECK;
    CreateEmptyMap(&Graf,NB,NK);
    PrintMap(Graf);
    //ListPointtoMatrix(listpoint,&CHECK);
    //PrintMap(CHECK);
    List ShopList = CreateShopList();
    int SaldoPlayer = 10000;
    List PlayerInventory;
    Stack newBuild;
    Queue queuepesanan;
    int i = 0;
    
    CreateEmpty(&queuepesanan, 5);
    PlayerInventory = CreateShopList();
    Order O1 = GenerateOrder(ShopList, 7);
    Order O2 = GenerateOrder(ShopList, 7);
    Order O3 = GenerateOrder(ShopList, 7);

    if(IsQEmpty(queuepesanan)){
        printf("kosong\n");
    } else {
        printf("ngaco lu\n");
    }

    Enqueue(&queuepesanan, O1);
    Enqueue(&queuepesanan, O2);
    Enqueue(&queuepesanan, O3);

    POINT player = listpoint.A[2];

    Status(SaldoPlayer, queuepesanan, PlayerInventory, player, listpoint);

}