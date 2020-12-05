#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif
#include "save.h"

void Save(int Saldo, Queue *Order, List Inventory, POINT player){
    char str[25];
    printf("Lokasi save file:");
    scanf("%s",&str);
    printf("%s",str);
    printf("\n");
    FILE * fp;
    fp = fopen ("saldo.txt","w");
    fprintf(fp,"%d",Saldo);
    fclose(fp);
    fp = fopen ("posisi.txt","w");
    fprintf(fp,"%d",player.X);
    fprintf(fp,"%c",' ');
    fprintf(fp,"%d",player.Y);
    fclose(fp);
    fp = fopen ("order.txt","w");
    while(!IsQEmpty(*Order)){
        fprintf(fp,"%d",InfoHead(*Order).HargaInvoice);
        fprintf(fp,"%c",'\n');
        for(int i=0;i<8;i++){
            fprintf(fp,"%d",InfoHead(*Order).ListKomponen.A[i].Harga);
            fprintf(fp,"%c",' ');
            fprintf(fp,"%d",InfoHead(*Order).ListKomponen.A[i].Jumlah);
            fprintf(fp,"%c",' ');
            fprintf(fp,"%d",InfoHead(*Order).ListKomponen.A[i].Kategori);
            fprintf(fp,"%c",' ');
            fprintf(fp,"%s",InfoHead(*Order).ListKomponen.A[i].NamaBarang);
            fprintf(fp,"%c",' ');
            fprintf(fp,"%d",InfoHead(*Order).ListKomponen.A[i].Pemilik);
            fprintf(fp,"%c",'\n');
            
        }
        QInfo X;
        Dequeue(&Order,&X);
    }
    fprintf(fp,"%c",'\n');
    fclose(fp);
    fp = fopen ("inventory.txt","w");
    IdxType iteration = 0;
    if(Length(Inventory) != 0){
        while(iteration < Length(Inventory)){
            fprintf(fp,"%s",Nama(Inventory.A[iteration]));
            fprintf(fp,"%s",Jumlah(Inventory.A[iteration]));
            fprintf(fp,"%c",'\n');
            iteration++;
        }
    fclose(fp);

}
// void Save(int Saldo, Queue Order, List Inventory, POINT player, ListPoint Point, boolean startedbuild) {
//     char* str;
//     printf("Lokasi save file:");
//     scanf("%s",&str);
//     printf("\n");
//     FILE * fp;
//     fp = fopen (str,"w");
//     char* diprint;
//     asprintf(&diprint, "Uang tersisa: $%d\n", Saldo); 
//     fprintf(fp,"%s",diprint);
//     fprintf(fp,"%s","Build yang sedang dikerjakan: ");
//     if(!startedbuild){
//         fprintf(fp,"%s","Belum ada\n");
//     } else {
//         asprintf(&diprint,"Pesanan %d untuk Pelanggan %d\n", NomorOrder(InfoHead(Order)), Pemesan(InfoHead(Order))); 
//         fprintf(fp,"%s",diprint);
//     }
//     fprintf(fp,"%s","Lokasi: Pemain sedang berada pada ");
//     boolean found = false;
//     int i = 0;
    
//     while (!found && i < LengthPoint(Point)) {
//         if (player.X == Point.A[i].X && player.Y == Point.A[i].Y) {
//             found = true;
//         }
//         else
//         {
//             i++;
//         }
        
//     }

//     if (found) {
//         if (i==0) {
//             fprintf(fp,"%s","Base\n");
//         }
//         else if (i==1) {
//             fprintf(fp,"%s","Shop\n");
//         }
//         else
//         {
//             fprintf(fp,"%s","Gedung %d\n", i-1);
//         }
        
//     }

//     fprintf(fp,"%s","Inventory Anda:\n");
//     IdxType iteration = 0;
//     if(Length(Inventory) != 0){
//         while(iteration < Length(Inventory)){
//             asprintf(&diprint, "%d. %s (%d)\n", iteration+1, Nama(Inventory.A[iteration]), Jumlah(Inventory.A[iteration])); 
//             fprintf(fp,"%s",diprint);
//             iteration++;
//         }
//     } else {
//         fprintf(fp,"%s","Kosong\n");
//     }
//     printf("Game berhasil di save!\n");
//     fclose(fp);
// }

