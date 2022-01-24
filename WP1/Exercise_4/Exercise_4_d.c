#include <stdio.h>
#include <stdlib.h>

// unsigned short int 16 bits --- 65,535
// unsigned long int  32 bits ==== 4294967295
// char 255 8 bits
#define MAX 9

int main(int argc, char *argv[]){

    char *ptr;
    unsigned long args = strtoul(argv[1],&ptr,10);
    if (args > 4294967295){
        printf("%s", "this number is bigger that long");
    }
    printf(" %lu \n", args);

    return 0;
}