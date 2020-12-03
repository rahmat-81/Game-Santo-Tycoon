#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(){
    char* namapesanan;
    asprintf(&namapesanan, "Build untuk pesanan #%d", 3); 
    printf("%s",namapesanan);
}