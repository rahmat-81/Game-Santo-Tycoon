#include "stdio.h"
#include <stdlib.h>

int main(){
    FILE *fp;
    fp=fopen("test.txt","w");
    fprintf(fp,"%s","test\n");
    return 0;
}