#include<stdio.h>
#include<stdlib.h>
#include "../stack/stack.h"
#include "../listdinamis/listardin.h"

void Shop (List* shop, List* Inventory, int saldo)
{
    int beli; /* pilihan yang ingin dibeli */
    int jumlah; /* jumlah yang ingin dibeli*/
    int totalharga;
    ElType komponen;

    /* Print komponen yang tersedia di shop */ 
    printf("Komponen yang tersedia: \n");
    if ((*shop).Neff > 0)
    {
        IdxType iteration = 0;
        if (Length(*shop) != 0)
        {
            while (iteration < Length(*shop))
            {
                printf("%d. %s - $(%d)\n", iteration+1, Nama((*shop).A[iteration]), Harga((*shop).A[iteration])); 
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
    printf("\n");
    printf("Masukkan jumlah yang ingin dibeli: ");
    scanf("%d", &jumlah);
    printf("\n");

    // cek apakah saldo mencukupi komponen yang ingin dibeli 
    komponen = Get(*shop, beli-1);
    totalharga = ((Harga(komponen)) * jumlah);
    if (totalharga <= saldo) // uang mencukupi
    {
        // cek apakah komponen sudah ada
        if (DoesComponentExist(List* Inventory, ElType* komponen) > -1)
        /* komponen sudah ada di inventory */
        {
            // menambahkan komponen yang sudah ada
            Jumlah(komponen) = Jumlah(komponen) + jumlah; /* coba di tes, jalan ato ngga */
        }
        else 
        {   
            // menambahkan komponen baru
            InsertLast (List* Inventory, ElType* komponen, int jumlah);
        }
        printf("Komponen berhasil dibeli!");
    }
    else 
    {
        printf ("Uang tidak cukup!");
    }
    
}
