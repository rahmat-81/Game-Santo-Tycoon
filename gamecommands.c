#include <stdio.h>
#include<stdlib.h>


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