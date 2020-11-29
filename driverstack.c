#include<stdio.h>
#include"stack.h"
#include "listardin.h"
#include "komponen.h"

int main(){
    Stack Build;
    Komponen mobo, cpu, ram, cooler, casing, gpu, ssd, psu, build;
    List pasang;
    CreateComponent(&mobo, "Motherboard B450", 1, 150, 1);
    // CreateComponent(&cpu, "Ryzen 5 4500X", 2, 400, 1);
    // CreateComponent(&ram, "Kingston 16GB DDR4", 3, 150, 1);
    // CreateComponent(&cooler, "Cooler Master Silent Cooler", 4, 50, 1);
    // CreateComponent(&casing, "NZXT H510i", 5, 170, 1);
    // CreateComponent(&gpu, "RTX 3090Ti", 6, 2000, 1);
    // CreateComponent(&ssd, "Samsung EVO 980 1TB", 7, 200, 1);
    // CreateComponent(&psu, "PSU 600W", 8, 70, 1);
    // CreateComponent(&build, "Build #23", 9, 4300, 1);

    // InsertLast(&pasang, mobo);
    // InsertLast(&pasang, cpu);
    // InsertLast(&pasang, ram);
    // InsertLast(&pasang, cooler);
    // InsertLast(&pasang, casing);
    // InsertLast(&pasang, gpu);
    // InsertLast(&pasang, ssd);
    // InsertLast(&pasang, psu);
    // InsertLast(&pasang, build);


    CreateEmptyStack(&Build);
    printf("%d\n", NBAssembled(Build)); /* harus 0 */
    
    if(IsStackEmpty(Build)){
        printf("Masih kosong\n");
    } else {
        printf("Udah ada isinya?\n");
    }
    Push(&Build, mobo);
    printf("%d\n", NBAssembled(Build)); /* harus 0 */
    PrintStack(Build);


}