#include<stdio.h>


int chartoint(char c){
    return (c - '0');
}
int main(){
    char angka = '3';
    printf("%d", chartoint(angka));
}