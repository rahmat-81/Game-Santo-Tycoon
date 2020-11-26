#include "stdio.h"
#include "mesinkar.h"

char CC;
char Choice[100];
boolean EOP;
static FILE *pita;
static int retval;

void START() {
/* Mesin siap dioperasikan. Pita disiapkan ... */
/* Algoritma */
    pita = fopen("map.txt","r");
    ADV();
}
void ADV() {
/* Pita dimajukan satu karakter. ... */
/* Algoritma */
    retval = fscanf(pita,"%c",&CC);
    EOP = (CC == MARK);
    if (EOP) {
    fclose(pita);
}
}

