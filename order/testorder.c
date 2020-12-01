#include<stdio.h>
#include<stdlib.h>
#include "../listdinamis/listardin.h"
#include "../komponen/komponen.h"
#include "order.h"
#include "../queue/Queue.h"
#include "../command/checkorder.c"

int main(){
    List ShopList = MakeList(); /* list untuk shop */
    Komponen mobo,mobo2,mobo3,mobo4,mobo5;
    Komponen cpu,cpu2,cpu3,cpu4,cpu5;
    Komponen ram,ram2,ram3,ram4,ram5;
    Komponen cooler,cooler2,cooler3,cooler4,cooler5;
    Komponen casing,casing2,casing3,casing4,casing5;
    Komponen gpu,gpu2,gpu3,gpu4,gpu5;
    Komponen ssd,ssd2,ssd3,ssd4,ssd5;
    Komponen psu,psu2,psu3,psu4,psu5;
    List Inventory = MakeList(); /* list untuk inventory */
    Order O1;
    Order O2;
    Order O3;
    Queue QueueOrder;
    CreateEmpty(&QueueOrder, 4);
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
    CreateComponent(&casing, "Fantich PULSE CG71", 5, 30, 1);
    CreateComponent(&casing, "Armagendong XDS20", 5, 50, 1);
    CreateComponent(&casing, "Simbanda", 5, 8, 1);
    CreateComponent(&casing, "Imperial Fortress 303 RGB", 5, 45, 1);
    CreateComponent(&casing, "Armagendong Nimitz", 5, 55, 1);
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

    O1 = GenerateOrder(ShopList, 7);
    O2 = GenerateOrder(ShopList, 7);
    O3 = GenerateOrder(ShopList, 7);

    if(IsQEmpty(QueueOrder)){
        printf("kosong\n");
    } else {
        printf("ngaco lu\n");
    }

    Enqueue(&QueueOrder, O1);
    Enqueue(&QueueOrder, O2);
    Enqueue(&QueueOrder, O3);

    if(!IsQEmpty(QueueOrder)){
        printf("keisi bor\n");
    } else {
        printf("gagal anying\n");
    }

    CheckOrder(QueueOrder);


}