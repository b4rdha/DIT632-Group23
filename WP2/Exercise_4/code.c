
#include <stdio.h>
#include <stdlib.h>

void set_bits (u_int8_t* old_bits, int new_bits, int n_shifts);
void pack_arg_bits(u_int8_t* packed_bits_ptr, char** argv);
int binaryToHec(const u_int8_t* packed_bits_ptr);

//// SIGSEGV error when not entering args >> to be fixed


int main (int argc, char** argv){

    u_int8_t packed_bits = 0;

    u_int8_t* packed_bits_ptr;

    packed_bits_ptr = &packed_bits;

    pack_arg_bits(packed_bits_ptr, argv);

    binaryToHec(packed_bits_ptr);

}


void set_bits (u_int8_t* old_bits, int new_bits, int n_shifts)
{

    //to know how many to shift then will cast the argument to int .
    // the new value will be shifted with the 0
    new_bits = 0 | new_bits << n_shifts;
    //printB( new_bits);

    // then it will be | with the old value
    *old_bits = *old_bits | new_bits;

}


void pack_arg_bits(u_int8_t* packed_bits_ptr, char** argv)
{
    // set the first argument bits
    set_bits((u_int8_t *) packed_bits_ptr, strtol(argv[1],NULL,10), 7);
    //printf("\n%c" ,  *(u_int8_t *) (char **) &argv[2]);

    // set the second argument bits
    set_bits((u_int8_t *) packed_bits_ptr, strtol(argv[2],NULL,10), 4);
    //printf("%d\n" , strtol(argv[1],NULL,10));

    // set the third argument bits
    //printf("%d\n" , *(u_int8_t*) argv[3]);
    set_bits((u_int8_t *) packed_bits_ptr, strtol(argv[3],NULL,10), 2);

    // set the third argument bits
    set_bits((u_int8_t *) packed_bits_ptr, strtol(argv[4],NULL,10), 1);
    //printf("%d\n" , *(u_int8_t*) argv[4]);

    // set the third argument bits
    set_bits((u_int8_t *) packed_bits_ptr, strtol(argv[5],NULL,10), 0);
    //printf("%d\n" , *(u_int8_t*) argv[5]);

}


int binaryToHec( const u_int8_t* packed_bits_ptr) {
    // print out the long value x as a lX hexadecimal value using strol method.
    // passing the bits_group array
    printf("%hhX\n", *packed_bits_ptr);

    //printf("\n%s\n", " is the hexadecimal value for the number you have entered");
    return 0;
}