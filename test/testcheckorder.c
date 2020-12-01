#include "../command/checkorder.c"
/*
int main() {
    Komponen mobo, cpu, ram, cooler, casing, gpu, ssd, psu, build, mobo2;
    List Inventory;
    Inventory = MakeList();

    CreateComponent(&mobo, "Motherboard B450", 1, 150, 1);
    CreateComponent(&cpu, "Ryzen 5 4500X", 2, 400, 1);
    CreateComponent(&ram, "Kingston 16GB DDR4", 3, 150, 1);
    CreateComponent(&cooler, "Cooler Master Silent Cooler", 4, 50, 1);
    CreateComponent(&casing, "NZXT H510i", 5, 170, 1);
    CreateComponent(&gpu, "RTX 3090Ti", 6, 2000, 1);
    CreateComponent(&ssd, "Samsung EVO 980 1TB", 7, 200, 1);
    CreateComponent(&psu, "PSU 600W", 8, 70, 1);
    CreateComponent(&build, "Build #23", 9, 4300, 1);


    InsertLast(&Inventory, mobo);
    InsertLast(&Inventory, cpu);
    InsertLast(&Inventory, ram);
    InsertLast(&Inventory, cooler);
    InsertLast(&Inventory, casing);
    InsertLast(&Inventory, gpu);
    InsertLast(&Inventory, ssd);
    InsertLast(&Inventory, psu);
    InsertLast(&Inventory, build);

    printf("ada %d komponen\n", Length(Inventory));

    // cek Check order

    Order O, O1, O2;
    CreateOrder(&O, 0, Inventory, 25);
    O1 = GenerateOrder(Inventory, 2);
    O2 = GenerateOrder(Inventory, 3);
    Queue Q;
    CreateEmpty(&Q, 5);
    if(IsQEmpty(Q)) {
        printf("berhasul\n");
    }
    Enqueue(&Q, O);
    Enqueue(&Q, O1);
    Enqueue(&Q, O2);

    if(!IsQEmpty(Q)) {
        printf("NQ berhasul\n");
    }

    printf("nbelm %d\n", NBElmnt(Q));

    infotype X;
    printf("************antrian 1**********\n");
    CheckOrder(Q);
    
    Dequeue(&Q, &X);
    printf("nbelm %d\n", NBElmnt(Q));
    printf("************antrian 2**********\n");
    CheckOrder(Q);
        printf("nbelm %d", NBElmnt(Q));
    Dequeue(&Q, &X);
    printf("************antrian 3**********\n");
    CheckOrder(Q);


    printf("udah");
    return 0;
    
}

*/
int main() {
    Komponen mobo, cpu, ram, cooler, casing, gpu, ssd, psu, build, mobo2;
    List Inventory;
    Inventory = MakeList();

    CreateComponent(&mobo, "Motherboard B450", 1, 150, 1);
    CreateComponent(&cpu, "Ryzen 5 4500X", 2, 400, 1);
    CreateComponent(&ram, "Kingston 16GB DDR4", 3, 150, 1);
    CreateComponent(&cooler, "Cooler Master Silent Cooler", 4, 50, 1);
    CreateComponent(&casing, "NZXT H510i", 5, 170, 1);
    CreateComponent(&gpu, "RTX 3090Ti", 6, 2000, 1);
    CreateComponent(&ssd, "Samsung EVO 980 1TB", 7, 200, 1);
    CreateComponent(&psu, "PSU 600W", 8, 70, 1);
    CreateComponent(&build, "Build #23", 9, 4300, 1);

    if (IsEmpty(Inventory)){
        printf("Inventory masih kosong nih\n");
    }

    InsertLast(&Inventory, mobo, 1);
    InsertLast(&Inventory, cpu, 1);
    InsertLast(&Inventory, ram, 1);
    InsertLast(&Inventory, cooler, 1);
    InsertLast(&Inventory, casing, 1);
    InsertLast(&Inventory, gpu, 1);
    InsertLast(&Inventory, ssd, 1);
    InsertLast(&Inventory, psu, 1);
    InsertLast(&Inventory, build, 1);

    printf("ada %d komponen\n", Length(Inventory));

    // Check order

    Order O, O1, O2;
    CreateOrder(&O, 0, Inventory, 25);
    O1 = GenerateOrder(Inventory, 2);
    O2 = GenerateOrder(Inventory, 3);
    Queue Q;
    CreateEmpty(&Q, 5);
    if(IsQEmpty(Q)) {
        printf("berhasul\n");
    }
    Enqueue(&Q, O);
    Enqueue(&Q, O1);
    Enqueue(&Q, O2);

    if(!IsQEmpty(Q)) {
        printf("NQ berhasul\n");
    }
    infotype X;
    Dequeue(&Q, &X);
    Dequeue(&Q, &X);
    //Dequeue(&Q, &X);
    // Dequeue(&Q, &X);
    CheckOrder(Q);
    
    printf("udah");
    return 0;
    
}
