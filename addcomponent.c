#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "listardin.h"

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
        printf("\n");
        pasang = Get(*Inventory, pilihan-1);

        // jumlah = 2
        // harga(beli) = 200
        // 2 *200 < saldo?
        // insertlast(inventory)
        while(Categ(pasang) != NBAssembled(*S) + 1){
            /* cek apakah komponen yang akan dipasang sudah sesuai urutan */
            printf("Komponen tidak kompatibel dengan urutannya! Pilih komponen sesuai urutan: ");
            scanf("%d", &pilihan);
        }
        printf("\n");
        Push(S, pasang);
        DeleteComponent(Inventory, pasang);
    } else {
        printf("Build sudah lengkap. Silakan lakukan finish build!\n");
    }

    

}