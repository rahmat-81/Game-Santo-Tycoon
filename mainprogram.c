
#include<stdio.h>
#include<stdlib.h>
#include "gamecommands.h"

//  gcc -o testmain mainprogram.c graf/graf.c komponen/komponen.c listdinamis/listdinamispoint.c listdinamis/listardin.c matrix/mapmatrix.c mesinkata/mesinkata.c order/order.c point/point.c queue/Queue.c stack/stack.c mesinkar/mesinkar.c gamecommands.c

int main(){
    UiAwal();
    boolean NewGame = false;
    char choose;
    printf("Start a new game? ... (y/n):");
    scanf("%c", &choose);
    if(choose == 'y' || choose == 'Y'){
        NewGame = true;
    } else {
        NewGame = false;
    }

    if (NewGame){
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
        
        CreateGraph(&Graf, JumlahGedung); /* membuat graf dengan ukuran jumlahgedung x jumlahgedung */
        BacaFilekeMatriks(JumlahGedung,&ReadGraf);
        ConvertMatrixToGraph(ReadGraf, &Graf);

        // PERSIAPAN GAME
        int i = 0;
        
        while(i < 8){
            // generate 8 order sehari
            Order O = GenerateOrder(ShopList, JumlahGedung-2);
            Enqueue(&QPesanan, O);
            i++;
        }
        // MAIN PROGRAM
        while(!EndGame){
            char command[25];
            printf("LIST OF AVAILABLE COMMANDS:\n");
            printf("1. MOVE\n");
            printf("2. STATUS\n");
            printf("3. STARTBUILD\n");
            printf("4. FINISHBUILD\n");
            printf("5. CHECKORDER\n");
            printf("6. ADDCOMPONENT\n");
            printf("7. REMOVECOMPONENT\n");
            printf("7. SHOP\n");
            printf("9. DELIVER\n");
            printf("10. END_DAY\n");
            printf("11. MAP\n");
            printf("12. EXIT\n");
            printf("13. MANUAL\n");
            printf("ENTER COMMAND:");
            scanf("%s", command);
            system("cls || clear");
            
                //  FUNGSI MOVE
            if(strcmp(command, MOVE.TabKata) == 0){
                Move(&Player, Graf, listpoint);
            } else if(strcmp(command, STATUS.TabKata) == 0){
                // FUNGSI STATUS
                Status(SaldoPlayer, QPesanan, PlayerInventory, Player, listpoint, StartedBuild); 
            } else if(strcmp(command, CHECKORDER.TabKata) == 0){
                // FUNGSI CHECKORDER
                CheckOrder(QPesanan);
            } else if(strcmp(command, ADDCOMPONENT.TabKata) == 0){
                // FUNGSI ADDCOMPONENT
                if(!StartedBuild){
                    //  build belum dilakukan
                    printf("Kamu belum melakukan build! Silakan lakukan STARTBUILD!\n");
                } else {
                    // build sudah dilakukan
                    if(Player.X == listpoint.A[0].X && Player.Y == listpoint.A[0].Y){
                        AddComponent(&Build, &PlayerInventory);
                    } else {
                        printf("Silakan lakukan Add Component di Base!\n");
                    }
                }
            } else if(strcmp(command, REMOVECOMPONENT.TabKata) == 0){
                //  FUNGSI STARTBUILD
                if(!StartedBuild){
                    //  build belum dilakukan
                    printf("Kamu belum melakukan build! Silakan lakukan STARTBUILD!\n");
                } else {
                    //  build sudah dilakukakn
                    RemoveComponent(&Build, &PlayerInventory);
                }
            } else if(strcmp(command, SHOP.TabKata) == 0){
                // FUNGSI SHOP
                if((Player.X == listpoint.A[1].X) && (Player.Y == listpoint.A[1].Y)){
                    //  posisi player sudah ada di shop
                    Shop(&ShopList, &PlayerInventory, &SaldoPlayer);
                    // system("cls||clear");
                } else {
                    //  posisi player belum berada di shop
                    printf("Kamu belum berada di Shop! Silakan lakukan move terlebih dahulu ke SHOP!\n");
                }
            } else if(strcmp(command, DELIVER.TabKata) == 0){
                // FUNGSI DELIVER
                if (StartedBuild){
                    // Build belum diselesaikan (belum finish build)
                    printf("Kamu belum menyelesaikan Build, silakan menyelesaikan Build terlebih dahulu.\n");
                }
                else{
                    // sudah dilakukan finishbuild
                    Deliver(Player, Pemesan(InfoHead(QPesanan)), listpoint, &PlayerInventory, &QPesanan, &SaldoPlayer);
                }
                
            } else if (strcmp(command, END_DAY.TabKata) == 0){
                // FUNGSI END DAY
                if(StartedBuild){
                    //  masih melakukan build
                    printf("Kamu belum menyelesaikan build! Silakan selesaikan build terlebih dahulu!\n");
                } else {
                    // tidak ada build yang dilakukan
                    End_Day(&QPesanan, ShopList, JumlahGedung-2);
                }    
            }else if(strcmp(command, STARTBUILD.TabKata) == 0){
                // FUNGSI STARTBUILD
                StartBuild(listpoint, Player, QPesanan, &StartedBuild, &Build);

            }else if (strcmp(command, FINISHBUILD.TabKata) == 0){
                // FUNGSI FINISHBUILD
                if(!StartedBuild){
                    //  build belum dilakukan
                    printf("Kamu belum melakukan build! Silakan lakukan STARTBUILD!\n");
                } else {
                    // build sudah dilakukan, melakukan pengecekan build
                    FinishBuild(Build,InfoHead(QPesanan),&PlayerInventory, &StartedBuild);
                }

            } else if(strcmp(command, MAP.TabKata) == 0){
                // FUNGSI MAP
                MapPlayer(Map, Player);
                printf("\n");
            } else if(strcmp(command, EXIT.TabKata) == 0){
                // FUNGSI EXIT MENGUBAH STATE GAME
                EndGame = true;
            } else if(strcmp(command, "MANUAL") == 0) {
                printf("Pak Santo adalah seorang mahasiswa informatika yang sangat senang memprogram. Selama\n");
                printf("berkuliah, beliau sangat menikmati berbagai aktivitas belajar dan sangat berniat mengerjakan\n");
                printf("tugas. Namun, seiring berjalannya waktu, beliau lelah terhadap berbagai tugas yang diberikan\n");
                printf("karena tidak sesuai dengan minat asli beliau. Oleh sebab itu, pada tahun terakhir kuliahnya, beliau\n");
                printf("memutuskan untuk mengerjakan skripsi dengan seadanya dan fokus untuk lulus secepat mungkin.\n");
                printf("Setelah Pak Santo lulus, beliau pun memutuskan untuk membuka toko komputer saja karena\n");
                printf("sudah terlanjur kehilangan minat terhadap dunia pemrograman.\n\n");
                printf("Kamu akan bermain sebagai Pak Santo, dan akan menjalankan toko komputernya!\n");
                printf("Kamu dapat melakukan banyak kegiatan seperti berjalan menuju toko, membuat PC, memasang komponen\n");
                printf("berbelanja dan lain-lain!\n");
            }else {
                // COMMAND YANG TIDAK VALID
                printf("Command tidak valid! Masukkan command yang valid!\n");
            }
        
        }
        printf("Thanks for playing Santo Tycoon!\n"); 
    }
    printf("Exiting game....\n");

}
    


