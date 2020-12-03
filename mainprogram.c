
#include<stdio.h>
#include<stdlib.h>
#include "gamecommands.h"

//  gcc -o testmain mainprogram.c graf/graf.c komponen/komponen.c listdinamis/listdinamispoint.c listdinamis/listardin.c matrix/mapmatrix.c mesinkata/mesinkata.c order/order.c point/point.c queue/Queue.c stack/stack.c mesinkar/mesinkar.c command/command.c

int main(){
    // INISIALISASI VARIABEL PENTING DALAM GAME
    List ShopList = CreateShopList(); /* LIST DINAMIS UNTUK SHOPPING */

    int SaldoPlayer = 10000; /* SALDO AWAL USER */
    
    List PlayerInventory = MakeList(); /* INVENTORY KOSONG */
    
    Stack Build; /* STACK UNTUK BUILD */
    CreateEmptyStack(&Build);
    
    Queue QPesanan; /* Queue order pelanggan */
    CreateEmpty(&QPesanan, 8); /*MENERIMA 8 PESANAN MAKSIMAL */
    
    srand(time(0)); /*PSEUDORANDOM NUMBER GENERATOR SEED UNTUK GENERATE ORDER */
    
    POINT Player; /* POSISI PLAYER */

    boolean EndGame = false; /* menandakan bahwa game belum selesai */

    MATRIX Map; /* inisalisasi map game */

    AdjacencyMATRIX Graf;

    MATRIX ReadGraf; /* pembacaan file konfig untuk graf */

    boolean StartedBuild = false; /* menunjukkan bahwa build sudah dimulai */ 

    // PEMBACAAN FILE KONFIGURASI

    InisiasiCommand();
    START();
    int NB = BacaInteger(); /* BACA BARIS UKURAN MAP */
    ADV();
    int NK = BacaInteger(); /* BACA KOLOM UKURAN MAP */
    IgnoreBlank();
    int JumlahGedung = BacaInteger(); /* BACA JUMLAH GEDUNG PADA GAME */
    ADVNEW();
    ListPoint listpoint = MakeListPoint(JumlahGedung); /* MEMBUAT LIST OF KOORDINAT GEDUNG */
    MembuatGedung(JumlahGedung,&listpoint);
     /* inisialisasi posisi awal player */
    Player = listpoint.A[0]; /* player ada di base pada awal mula game */
    CreateEmptyMap(&Map, NB, NK); /* membuat map berdasarkan ukuran file konfigurasi */
    ListPointtoMatrix(listpoint, &Map); /* memasukkan koordinat ke map */
    
    // PrintMap(Map, Player); /* lolos uji */
    CreateGraph(&Graf, JumlahGedung); /* membuat graf dengan ukuran jumlahgedung x jumlahgedung */
    BacaFilekeMatriks(JumlahGedung,&ReadGraf);
    ConvertMatrixToGraph(ReadGraf, &Graf);
    //PrintGraph(Graf);
    // PrintGraph(Graf); /* lolos uji */

    // PERSIAPAN GAME
    int i = 0;
    UiAwal();
    while(i < 8){
        // generate 8 order sehari
        Order O = GenerateOrder(ShopList, JumlahGedung-2);
        Enqueue(&QPesanan, O);
        i++;
    }
    // MAIN PROGRAM
    while(!EndGame){
       char command[25];
        printf("ENTER COMMAND:");
        scanf("%s", command);
        system("cls");
        
        
        if(strcmp(command, MOVE.TabKata) == 0){
            Move(&Player, Graf, listpoint);
        } else if(strcmp(command, STATUS.TabKata) == 0){
            Status(SaldoPlayer, QPesanan, PlayerInventory, Player, listpoint, StartedBuild); 
        } else if(strcmp(command, CHECKORDER.TabKata) == 0){
            CheckOrder(QPesanan);
        } else if(strcmp(command, ADDCOMPONENT.TabKata) == 0){
            if(!StartedBuild){
                //  build belum dilakukan
                printf("Kamu belum melakukan build! Silakan lakukan STARTBUILD!\n");
            } else {
            AddComponent(&Build, &PlayerInventory);
            }
        } else if(strcmp(command, REMOVECOMPONENT.TabKata) == 0){
            if(!StartedBuild){
                //  build belum dilakukan
                printf("Kamu belum melakukan build! Silakan lakukan STARTBUILD!\n");
            } else {
                RemoveComponent(&Build, &PlayerInventory);
            }
        } else if(strcmp(command, SHOP.TabKata) == 0){
            if((Player.X == listpoint.A[1].X) && (Player.Y == listpoint.A[1].Y)){
                Shop(&ShopList, &PlayerInventory, &SaldoPlayer);
            } else {
                printf("Kamu belum berada di Shop! Silakan lakukan move terlebih dahulu ke SHOP!\n");
            }
        } else if(strcmp(command, DELIVER.TabKata) == 0){
            if (StartedBuild){
                printf("Kamu belum menyelesaikan Build, silakan menyelesaikan Build terlebih dahulu.\n");
            }
            else{
                Deliver(Player, Pemesan(InfoHead(QPesanan)), listpoint, &PlayerInventory, &QPesanan, &SaldoPlayer);
            }
            
        } else if (strcmp(command, END_DAY.TabKata) == 0){
            if(StartedBuild){
                printf("Kamu belum menyelesaikan build! Silakan selesaikan build terlebih dahulu!\n");
            } else {
                End_Day(&QPesanan, ShopList, JumlahGedung-2);
            }    
        }else if(strcmp(command, STARTBUILD.TabKata) == 0){
            StartBuild(listpoint, Player, QPesanan, &StartedBuild, &Build);
        }else if (strcmp(command, FINISHBUILD.TabKata) == 0){
            if(!StartedBuild){
                //  build belum dilakukan
                printf("Kamu belum melakukan build! Silakan lakukan STARTBUILD!\n");
            } else {
                FinishBuild(Build,InfoHead(QPesanan),&PlayerInventory, &StartedBuild);
            }
        } else if(strcmp(command, MAP.TabKata) == 0){
            MapPlayer(Map, Player);
            printf("\n");
        } else if(strcmp(command, EXIT.TabKata) == 0){
            EndGame = true;
        } else {
            printf("Command tidak valid! Masukkan command yang valid!\n");
        }
        
    }
}

