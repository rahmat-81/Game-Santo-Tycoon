#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif
#include "gamecommands.h"

Kata MOVE,STATUS,CHECKORDER,STARTBUILD,FINISHBUILD,ADDCOMPONENT,REMOVECOMPONENT,SHOP,DELIVER,END_DAY,MAP,EXIT;
void InisiasiCommand(){
MOVE.TabKata[0]='M';
MOVE.TabKata[1]='O';
MOVE.TabKata[2]='V';
MOVE.TabKata[3]='E';
MOVE.Length=4;
STATUS.TabKata[0]='S';
STATUS.TabKata[1]='T';
STATUS.TabKata[2]='A';
STATUS.TabKata[3]='T';
STATUS.TabKata[4]='U';
STATUS.TabKata[5]='S';
STATUS.Length=6;
CHECKORDER.TabKata[0]='C';
CHECKORDER.TabKata[1]='H';
CHECKORDER.TabKata[2]='E';
CHECKORDER.TabKata[3]='C';
CHECKORDER.TabKata[4]='K';
CHECKORDER.TabKata[5]='O';
CHECKORDER.TabKata[6]='R';
CHECKORDER.TabKata[7]='D';
CHECKORDER.TabKata[8]='E';
CHECKORDER.TabKata[9]='R';
CHECKORDER.Length=10;
STARTBUILD.TabKata[0]='S';
STARTBUILD.TabKata[1]='T';
STARTBUILD.TabKata[2]='A';
STARTBUILD.TabKata[3]='R';
STARTBUILD.TabKata[4]='T';
STARTBUILD.TabKata[5]='B';
STARTBUILD.TabKata[6]='U';
STARTBUILD.TabKata[7]='I';
STARTBUILD.TabKata[8]='L';
STARTBUILD.TabKata[9]='D';
STARTBUILD.Length=10;
FINISHBUILD.TabKata[0]='F';
FINISHBUILD.TabKata[1]='I';
FINISHBUILD.TabKata[2]='N';
FINISHBUILD.TabKata[3]='I';
FINISHBUILD.TabKata[4]='S';
FINISHBUILD.TabKata[5]='H';
FINISHBUILD.TabKata[6]='B';
FINISHBUILD.TabKata[7]='U';
FINISHBUILD.TabKata[8]='I';
FINISHBUILD.TabKata[9]='L';
FINISHBUILD.TabKata[10]='D';
FINISHBUILD.Length=11;
ADDCOMPONENT.TabKata[0]='A';
ADDCOMPONENT.TabKata[1]='D';
ADDCOMPONENT.TabKata[2]='D';
ADDCOMPONENT.TabKata[3]='C';
ADDCOMPONENT.TabKata[4]='O';
ADDCOMPONENT.TabKata[5]='M';
ADDCOMPONENT.TabKata[6]='P';
ADDCOMPONENT.TabKata[7]='O';
ADDCOMPONENT.TabKata[8]='N';
ADDCOMPONENT.TabKata[9]='E';
ADDCOMPONENT.TabKata[10]='N';
ADDCOMPONENT.TabKata[11]='T';
ADDCOMPONENT.Length=12;
REMOVECOMPONENT.TabKata[0]='R';
REMOVECOMPONENT.TabKata[1]='E';
REMOVECOMPONENT.TabKata[2]='M';
REMOVECOMPONENT.TabKata[3]='O';
REMOVECOMPONENT.TabKata[4]='V';
REMOVECOMPONENT.TabKata[5]='E';
REMOVECOMPONENT.TabKata[6]='C';
REMOVECOMPONENT.TabKata[7]='O';
REMOVECOMPONENT.TabKata[8]='M';
REMOVECOMPONENT.TabKata[9]='P';
REMOVECOMPONENT.TabKata[10]='O';
REMOVECOMPONENT.TabKata[11]='N';
REMOVECOMPONENT.TabKata[12]='E';
REMOVECOMPONENT.TabKata[13]='N';
REMOVECOMPONENT.TabKata[14]='T';
REMOVECOMPONENT.Length=15;
SHOP.TabKata[0]='S';
SHOP.TabKata[1]='H';
SHOP.TabKata[2]='O';
SHOP.TabKata[3]='P';
SHOP.Length=4;
DELIVER.TabKata[0]='D';
DELIVER.TabKata[1]='E';
DELIVER.TabKata[2]='L';
DELIVER.TabKata[3]='I';
DELIVER.TabKata[4]='V';
DELIVER.TabKata[5]='E';
DELIVER.TabKata[6]='R';
DELIVER.Length=7;
END_DAY.TabKata[0]='E';
END_DAY.TabKata[1]='N';
END_DAY.TabKata[2]='D';
END_DAY.TabKata[3]='_';
END_DAY.TabKata[4]='D';
END_DAY.TabKata[5]='A';
END_DAY.TabKata[6]='Y';
END_DAY.Length=7;
MAP.TabKata[0]='M';
MAP.TabKata[1]='A';
MAP.TabKata[2]='P';
MAP.Length=3;
EXIT.TabKata[0]='E';
EXIT.TabKata[1]='X';
EXIT.TabKata[2]='I';
EXIT.TabKata[3]='T';
EXIT.Length=4;
}

// gcc -o testmain mainprogram.c graf/graf.c komponen/komponen.c listdinamis/listdinamispoint.c listdinamis/listardin.c matrix/mapmatrix.c mesinkata/mesinkata.c order/order.c point/point.c queue/Queue.c stack/stack.c mesinkar/mesinkar.c
// command untuk compile ^

void UiAwal(){
    printf("      ::::::::      :::     ::::    ::: ::::::::::: ::::::::      ::::::::::: :::   :::  ::::::::   ::::::::   ::::::::  ::::    ::: \n"); 
    printf("    :+:    :+:   :+: :+:   :+:+:   :+:     :+:    :+:    :+:         :+:     :+:   :+: :+:    :+: :+:    :+: :+:    :+: :+:+:   :+:  \n"); 
    printf("   +:+         +:+   +:+  :+:+:+  +:+     +:+    +:+    +:+         +:+      +:+ +:+  +:+        +:+    +:+ +:+    +:+ :+:+:+  +:+   \n");
    printf("  +#++:++#++ +#++:++#++: +#+ +:+ +#+     +#+    +#+    +:+         +#+       +#++:   +#+        +#+    +:+ +#+    +:+ +#+ +:+ +#+    \n"); 
    printf("        +#+ +#+     +#+ +#+  +#+#+#     +#+    +#+    +#+         +#+        +#+    +#+        +#+    +#+ +#+    +#+ +#+  +#+#+#     \n"); 
    printf("#+#    #+# #+#     #+# #+#   #+#+#     #+#    #+#    #+#         #+#        #+#    #+#    #+# #+#    #+# #+#    #+# #+#   #+#+#      \n"); 
    printf("########  ###     ### ###    ####     ###     ########          ###        ###     ########   ########   ########  ###    ####       \n");

    printf("\n\nSELAMAT DATANG DI SANTO TYCOON! \n");


}

char IntToChar(int i){
    return i +'0';
}
void ListPointtoMatrix(ListPoint list, MATRIX *M){
    for (int i=0;i<list.Neff;i++){
        if (i==0){
            SetMapElement(M,list.A[i].X,list.A[i].Y,'B');
        }
        else if (i==1){
            SetMapElement(M,list.A[i].X,list.A[i].Y,'S');
        }
        else{
            SetMapElement(M,list.A[i].X,list.A[i].Y,IntToChar(i-1));
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
            // printf("Komponen yang tersedia: \n");
            while (iteration < Length(*shop))
            {
                printf("%d. %s - $%d\n", iteration+1, Nama((*shop).A[iteration]), Harga((*shop).A[iteration])); 
                iteration++;
            }
        
        }
        printf("Jika tidak jadi membeli, masukkan 0 pada komponen yang ingin dibeli!\n");
        printf("Komponen yang ingin dibeli: ");
        scanf("%d", &beli);
        if(beli != 0){
            // user membeli barang
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
        } else {
            ("Anda telah keluar dari shop!\n");
    }

        
    }
    else
    {
        printf ("Toko sedang kosong\n"); 
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
    } else {
        printf("Inventory Anda kosong.\n");
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
    CreateComponent(&mobo, "Motherboard AT", 1, 150, 1,0);
    CreateComponent(&mobo2, "Motherboard ATX", 1, 200, 1,0);
    CreateComponent(&mobo3, "Motherboard Micro-ATX", 1, 250, 1,0);
    CreateComponent(&mobo4, "Motherboard Mini ITX", 1, 275, 1,0);
    CreateComponent(&mobo5, "Motherboard E-ATX", 1, 300, 1,0);
    CreateComponent(&cpu, "Ryzeng 5 4500X", 2, 400, 1,0);
    CreateComponent(&cpu2, "Intol i9 9800HK", 2, 700, 1,0);
    CreateComponent(&cpu3, "Ryzeng 7 2900X", 2, 450, 1,0);
    CreateComponent(&cpu4, "Intol Pentium Trio", 2, 75, 1,0);
    CreateComponent(&cpu5, "Apple Silicca", 2, 900, 1,0);
    CreateComponent(&ram, "Kingstool 16GB DDR4 2600 MHz", 3, 65, 1,0);
    CreateComponent(&ram2, "HyperVTX 8GB DDR4 3200 MHz", 3, 60, 1,0);
    CreateComponent(&ram3, "Sumsang 8GB DDR4 3200 MHz", 3, 75, 1,0);
    CreateComponent(&ram4, "VGan 4GB DDR3 2133 MHz", 3, 45, 1,0);
    CreateComponent(&ram5, "Kingston 16GB DDR4", 3, 150, 1,0);
    CreateComponent(&cooler, "Cooler Mister Silent Cooler", 4, 70, 1,0);
    CreateComponent(&cooler2, "Alsaya TBF-100 Cooler", 4, 50, 1,0);
    CreateComponent(&cooler3, "Cooler Mister Master Liquid", 4, 95, 1,0);
    CreateComponent(&cooler4, "Aigoo DarkFlash Cooler", 4, 70, 1,0);
    CreateComponent(&cooler5, "Cooler Mister MasterAir", 4, 100, 1,0);
    CreateComponent(&casing, "NZXT H510i", 5, 170, 1,0);
    CreateComponent(&casing2, "Fantich PULSE CG71", 5, 30, 1,0);
    CreateComponent(&casing3, "Armagendong XDS20", 5, 50, 1,0);
    CreateComponent(&casing4, "Simbanda", 5, 8, 1,0);
    CreateComponent(&casing5, "Imperial Fortress 303 RGB", 5, 45, 1,0);
    CreateComponent(&gpu, "NVDIA RTX 3090Ti", 6, 2200, 1,0);
    CreateComponent(&gpu2, "AMJ RX 5600M", 6, 90, 1,0);
    CreateComponent(&gpu3, "NVDIA GTX 1080Ti", 6, 150, 1,0);
    CreateComponent(&gpu4, "AMJ RX580", 6, 2000, 1,0);
    CreateComponent(&gpu5, "AMJ RX 5600XT", 6, 460, 1,0);
    CreateComponent(&ssd, "Sumsang EVO 980 1TB", 7, 230, 1,0);
    CreateComponent(&ssd2, "Sumsang EVO 860 120GB", 7, 80, 1,0);
    CreateComponent(&ssd3, "Kingstool 500GB SATA", 7, 95, 1,0);
    CreateComponent(&ssd4, "Seaglare Barracuda 250GB", 7, 99, 1,0);
    CreateComponent(&ssd5, "VGan HDD 1TB", 7, 60, 1,0);
    CreateComponent(&psu, "Armagendong PSU 600W", 8, 70, 1,0);
    CreateComponent(&psu2, "Panascanic PSU 500W", 8, 70, 1,0);
    CreateComponent(&psu3, "Corseer PSU 600W", 8, 70, 1,0);
    CreateComponent(&psu4, "Cooler Mister CX PSU 600W", 8, 70, 1,0);
    CreateComponent(&psu5, "ThermalGive PSU 550W", 8, 70, 1,0);

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

void Deliver(POINT player, int NomorGedung, ListPoint Customer, List* Inventory, Queue* Q, int* Saldo){
    // nomor gedung didapatkan dari parameter pemesan pada infohead orderan, diakses melalu Pemesan(InfoHead(O))
    // membuat build satu2, lalu mengantarkan build tersebut. hanya ada 1 build dalam inventory.
    if(Absis(player) == Absis(Customer.A[NomorGedung+1]) && Ordinat(player) == Ordinat(Customer.A[NomorGedung+1])){
        /* posisi player ada pada gedung pelanggan */
        ListEl Build;
        if(DoesBuildExists(Inventory, &Build)){
            if(Pemilik(Build) == NomorGedung){
                QInfo BuildCustomer;
                Dequeue(Q, &BuildCustomer); /* dequeue orderan */
                DeleteComponent(Inventory, Build);
                printf("Pesanan #%d berhasil diantarkan kepada pelanggan %d!\n", NomorOrder(BuildCustomer), Pemesan(BuildCustomer));
                *Saldo += Invoice(BuildCustomer);
            } else {
                printf("Build yang diantarkan bukan milik pemesan ini! Silakan lakukan command Move ke tempat pemesan yang benar!\n");
            }
            
        } else {
            printf("Anda belum memiliki build yang selesai, silakan selesaikan build terlebih dahulu\n");
        }
    } else {
        printf("Anda belum berada di lokasi customer! Silakan lakukan command MOVE terlebih dahulu!\n");
    }
}


void Status(int Saldo, Queue Order, List Inventory, POINT player, ListPoint Point, boolean startedbuild) {
    printf("Uang tersisa: $%d\n", Saldo);
    printf("Build yang sedang dikerjakan: ");
    if(!startedbuild){
        printf("Belum ada\n");
    } else {
        printf("Pesanan %d untuk Pelanggan %d\n", NomorOrder(InfoHead(Order)), Pemesan(InfoHead(Order)));
    }
    printf("Lokasi: Pemain sedang berada pada ");
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

    printf("Inventory Anda:\n");
    PrintList(Inventory);
}

void FinishBuild(Stack Inventory, Order order, List* InventoryPlayer, boolean* startbuild){

    Stack InventoryCheck;
    Komponen X;
    CopyStack(Inventory,&InventoryCheck);
    if (IsStackEmpty(InventoryCheck)){
        printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.\n");
    }
    else{
        int i=0;
        boolean found=false;
        while ((!IsStackEmpty(InventoryCheck))&& (!found)){
            Pop(&InventoryCheck,&X);
            if (X.NamaBarang != order.ListKomponen.A[7-i].NamaBarang){
                found=true;
            }
            i++;
        }
        if (found){
            printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.\n");
        }
        else{
            printf("Pesanan %d telah selesai. Silahkan antar ke pelanggan %d!\n",order.NoPesanan,order.Pemesan);
            Komponen Build;
            char* namapesanan;
            asprintf(&namapesanan, "Build untuk pesanan #%d", NomorOrder(order)); /* alokasi nama order */
            CreateComponent(&Build, namapesanan, 9, Invoice(order), 1, Pemesan(order));
            //free(namapesanan); /* dealokasi nama order */
            InsertLast(InventoryPlayer, Build, 1);
            (*startbuild) = false;
        }
    }
    
}

void Move (POINT* player, AdjacencyMATRIX Graf, ListPoint Point){
    printf("Kamu berada pada ");
    boolean found = false;
    int i = 0;
    
    while (!found && i < LengthPoint(Point)) {
        if ((*player).X == Point.A[i].X && (*player).Y == Point.A[i].Y) {
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
    NeighborsList(Graf,i); /* i adalah posisi kita sekarang */
    printf("Nomor tujuan: ");
    int pilihan;
    scanf("%d",&pilihan);
    int j;
    int nomor_depan = 1;
    
    for(j=0; j < NBVertex(Graf); j++){
        if(Edges(Graf, j, i) > 0){
            if (nomor_depan == pilihan){
            *player=Point.A[j];
            // printf()
            printf("Kamu telah mencapai lokasi ");
            if (j==0){
                printf("Base\n");
            }
            else if (j==1){
                printf("Shop\n");
            }
            else{
                printf("Pelanggan %d\n", j-1);
            }
        
        // j++
        }
        nomor_depan++;
        }
    }


}

void StartBuild (ListPoint listpoint, POINT Player, Queue order, boolean* startbuild, Stack* newbuild)
{    
    // Stack newBuild;
    if(Player.X == listpoint.A[0].X && Player.Y == listpoint.A[0].Y){
        if (IsQEmpty(order))
        { 
        printf("Kamu belum menerima pesanan.\n");
        (*startbuild) = false;
        }
        else
        {
        CreateEmptyStack(newbuild);
        (*startbuild) = true;
        printf ("Kamu telah memulai pesanan %d untuk pelanggan %d.\n", NomorOrder(InfoHead(order)), Pemesan(InfoHead(order)));
        }
    } else {
        printf("Kamu belum berada di Base! Silakan lakukan MOVE ke base agar dapat melakukan build!\n");
        (*startbuild) = false;
    }
    
}

void MapPlayer (MATRIX M, POINT player)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    indeks a, b, i, j;
    // print baris pertama
    for (a = 0; a <= (NKolEff(M) + 2); a++){
        printf("%c", '*');
    }
    printf("\n");

    for(i = 0; i < NBrsEff(M) ; i++)
    {
        printf("%c ", '*'); // print kolom pertama

        for(j = 0; j < NKolEff(M); j++)
        {
            if ((player.X == i+1) && (player.Y == j+1))
            {
                printf("P");
            }
            else if (i==(NBrsEff(M)-1) && j==(NKolEff(M)-1))
            {
                printf("%c", Elmt(M, i, j));
                printf("%c\n", '*');
            } 
            else if(j==(NKolEff(M)-1))
            {
                printf("%c", Elmt(M, i, j));
                printf("%c\n", '*');
            } 
            else 
            {
                printf("%c", Elmt(M, i, j));
            }
        }
    }
    // print baris terakhir
    for (b = 0; b <= (NKolEff(M) + 2); b++){
        printf("%c", '*');
    }
}
