#include<stdio.h>
#include "listardin.h"
#include "komponen.h"
#include<stdlib.h>


int main(){
    /* kamus global */
    Komponen mobo, cpu, ram, cooler, casing, gpu, ssd, psu, build, mobo2;
    List Inventory;
    Inventory = MakeList(); /* inisialisasi list of components */
    IdxType iteration = 0;

    /* membuat komponen */
    CreateComponent(&mobo, "Motherboard B450", 1, 150, 1);
    CreateComponent(&cpu, "Ryzen 5 4500X", 2, 400, 1);
    CreateComponent(&ram, "Kingston 16GB DDR4", 3, 150, 1);
    CreateComponent(&cooler, "Cooler Master Silent Cooler", 4, 50, 1);
    CreateComponent(&casing, "NZXT H510i", 5, 170, 1);
    CreateComponent(&gpu, "RTX 3090Ti", 6, 2000, 1);
    CreateComponent(&ssd, "Samsung EVO 980 1TB", 7, 200, 1);
    CreateComponent(&psu, "PSU 600W", 8, 70, 1);
    CreateComponent(&build, "Build #23", 9, 4300, 1);
    /* komponen duplikat */
    CreateComponent(&mobo2, "Motherboard B450", 1, 150, 1);

    if (IsEmpty(Inventory)){
        printf("Inventory masih kosong nih\n");
    }

    InsertLast(&Inventory, mobo);
    InsertLast(&Inventory, cpu);
    InsertLast(&Inventory, ram);
    InsertLast(&Inventory, cooler);
    InsertLast(&Inventory, casing);
    InsertLast(&Inventory, gpu);
    InsertLast(&Inventory, ssd);
    InsertLast(&Inventory, ssd);
    InsertLast(&Inventory, psu);
    InsertLast(&Inventory, build);

    printf("ada %d komponen\n", Length(Inventory));

    if(Length(Inventory) != 0){
        while(iteration < Length(Inventory)){
            printf("%d. %s (%d)\n", iteration+1, Nama(Get(Inventory, iteration)), Jumlah(Get(Inventory, iteration)));
            iteration++;
        }
    } else {
        printf("Gagal gus masukin ke list :(\n");
    }

    /* komponen duplikat */
    InsertLast(&Inventory, mobo2);
    printf("ada %d komponen\n", Length(Inventory));

    IdxType iteration2 = 0;
    if(Length(Inventory) != 0){
        while(iteration2 < Length(Inventory)){
            printf("%d. %s (%d)\n", iteration2+1, Nama(Get(Inventory, iteration2)), Jumlah(Get(Inventory, iteration2)));
            iteration2++;
        }
    } else {
        printf("Gagal gus masukin ke list :(\n");
    }

    return 0;


}