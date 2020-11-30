#include<stdio.h>
#include<stdlib.h>
#include "../stack/stack.h"
#include "../listdinamis/listardin.h"

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
        while(Categ(pasang) != Top(*S)+1){
            /* cek apakah komponen yang akan dipasang sudah sesuai urutan */
            printf("Komponen tidak kompatibel dengan urutannya! Pilih komponen sesuai urutan: ");
            scanf("%d", &pilihan); 
            pasang = Get(*Inventory, pilihan-1);
            // kalo gapunya inventory?
        }
        printf("\n");
        Push(S, pasang);
        DeleteComponent(Inventory, pasang);
    } else {
        printf("Build sudah lengkap. Silakan lakukan finish build!\n");
    }
}

    

