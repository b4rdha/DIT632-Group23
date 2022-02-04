// (C) Bassam Group: 23 (2022)
// Work package 2
// Exercise 4 part 1 (Packing bits)
// Submission code: 101zX!
//
/*
------------------------------------------------------------------
The program takes 5 arguments "Options" and pack them into a byte.
 the 8 bits are divided for 5 different options, each bit or group of bits means a specific option and its value:
engine_on       0..1     1      Is engine on or off . This is bit no 7
gear_pos        0..4     3      The position of the gear. Three bits means that we can have 23 == 7 positions
key_pos         0..2     2      Position of the key – 0 == stop, 1 == on, 2 == engine starter on
brake1          0..1     1      Position of the front brakes
brake2          0..1     1      Position of the rear brakes. Bit no 0 (LSB)
In case of running the program with no arguments or wrong digit values, the program shall prompt
 a message to the user guiding how to run the program correctly.
------------------------------------------------------------------
*/

// include libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function declaration

//Function which takes new bits and set them in a byte.
void set_bits (u_int8_t* old_bits, int new_bits, int n_shifts);

//Function which takes the program arguments and pack them in a byte.
void pack_arg_bits(u_int8_t* packed_bits_ptr, char** argv);

// Function which takes the packed or binary value to convert it to hexadecimal
void binary_to_hex(const u_int8_t* packed_bits_ptr);

// function that checks if each program argument is within it's limit.
int check_limits (char** argv);


// global variables
static char argument_failure [] = "\nYou might have not entered 5 arguments or entered more than 5 arguments. "
                                  "Type: \"./filename -h\" for help![on windows: \"filename.exe -h\"]";

static char help [] = "\nTo be able to run the program >>> \n- Type:  './<<name of your executable file>>', "
                      "a whitespace and \"<5 valid arguments eg (1 2 2 1 1> \" \nThe first value must be between 0-1, second 0-7, third 0-2, forth 0-1 and the last 0-1"
                      "[on windows: \"filename.exe <1 2 2 1 1>\" ]\n- If you wish to run this program in the pipeline then you should use the following command instead:\n"
                      "\t./thisFileName 1 2 2 1 1 | xargs ./theOtherFileName [on windows: \"./thisFileName.exe 1 2 2 1 1 | xargs -0 ./theOtherFileName.exe\" ]";


/**
 * Main function for the program.
 * @param argc - number of program arguments
 * @param argv - array of strings with program arguments, idexed from 0
 * @returns - 0 if ok, positive integer if there is an error code
 */
int main(int argc, char**argv){

    // the length of the args can't be less or higher than 5
    if (argc > 6 || argc < 6)
    {
        // print out a failure message to the user and the reason
        printf("%s , \n%s\n", argument_failure, "You must provide 5 arguments");

        //return -1 and exit the program
        return -1;
    }

    if (strcmp(argv[1], "-h") == 0)
    {
        // prompt to the user a guide message on how to run the program correctly.
        printf("%s\n", help);

        // return 0 and exit the program successfully.
        return 0;
    }


    // we check if each argument is within the limits by help of check_limits method
    if(check_limits (argv) == -1)
    {
        // if any argument is not with the limits return -1 and exit the program.
        return -1;
    }

    // else we run the program

    // initialize a byte to pack our bits in it
    u_int8_t packed_bits = 0;

    // create a pointer for the packed_bits to use it in other functions.
    u_int8_t* packed_bits_ptr;

    // assign the pointer with the packed bits address.
    packed_bits_ptr = &packed_bits;

    // Pack the given arguments into a byte with the help of pack_arg_bits in our packed_bits variable.
    pack_arg_bits(packed_bits_ptr, argv);

    // print out the packed bits to a hexadecimal value with binary_to_hex method.
    binary_to_hex(packed_bits_ptr);

    // return 0 and exit the program successfully.
    return 0;
}


/**
 * set_bits function. that take new bits and set it together with the old bits in a byte
 * @param old_bits - the bits that are already packed in a byte.
 * @param new_bits - the new bits that are given as argument
 * @param n_shifts - number of shifts to be bale to set the bits in the right pace in a byte
 * @returns - void
 */
void set_bits (u_int8_t* old_bits, int new_bits, int n_shifts)
{
    // take the new bits value, mask them with 0 ith the help of | bit operator
    // and then shift them to the right place where they should be packed in the byte
    new_bits = 0 | new_bits << n_shifts;

    // the old_bits will now be the value of the mask operation between the old bits and the new bits
    *old_bits = *old_bits | new_bits;
}


/**
 * pack_arg_bits function. that take each argument value and pack it in one byte
 * with the help of set_bits method.
 * @param packed_bits_ptr - a pointer to the already packed bits.
 * @param argv - a pointer to the program arguments
 * @returns - void
 */
void pack_arg_bits(u_int8_t* packed_bits_ptr, char** argv)
{
    // set the first argument bits
    set_bits((u_int8_t *) packed_bits_ptr, strtol(argv[1],NULL,10), 7);

    // set the second argument bits
    set_bits((u_int8_t *) packed_bits_ptr, strtol(argv[2],NULL,10), 4);

    // set the third argument bits
    set_bits((u_int8_t *) packed_bits_ptr, strtol(argv[3],NULL,10), 2);

    // set the forth argument bits
    set_bits((u_int8_t *) packed_bits_ptr, strtol(argv[4],NULL,10), 1);

    // set the fifth argument bits
    set_bits((u_int8_t *) packed_bits_ptr, strtol(argv[5],NULL,10), 0);

}


/**
 * binary_to_hex function. that takes the pack bits and prints it as hexadecimal value
 * @param packed_bits_ptr - a pointer to the already packed bits.
 * @returns - void
 */
void binary_to_hex( const u_int8_t* packed_bits_ptr) {

    // print out the value of the pointer as hexadecimal value.
    printf("%hhX\n", *packed_bits_ptr);
}


/**
 * check_limits function. that takes the program arguments and check if the limits of each argument is met.
 * @param argv - a pointer to the program arguments.
 * @returns - int where -1 is fail and 0 is okay
 */
int check_limits (char** argv)
{
    // loop for each argument
    for (int i = 0; i <6 ; ++i) {

        // check if the first arg is within limit
        if (atoi(argv[1]) < 0 || atoi(argv[1]) > 1 || !isdigit(argv[1][0]))
        {
            // print out the failure message and the specific reason for failure
            printf("%s, \n%s\n", argument_failure, "Your first argument must be between 0 and 1");
            //return -1 so the program get to exit in the main method.
            return -1;
        }
        // check if the second arg is within limit
        else if (atoi(argv[2]) < 0 || atoi(argv[2]) > 7 || !isdigit(argv[2][0]))
        {
            // print out the failure message and the specific reason for failure
            printf("%s, \n%s\n", argument_failure, "Your second argument must be between 0 and 7");
            //return -1 so the program get to exit in the main method.
            return -1;
        }
        // check if the third arg is within limit
        else if (atoi(argv[3]) < 0 || atoi(argv[3]) > 2 || !isdigit(argv[3][0]))
        {
            // print out the failure message and the specific reason for failure
            printf("%s, \n%s\n", argument_failure, "Your third argument must be between 0 and 2");
            //return -1 so the program get to exit in the main method.
            return -1;
        }
        // check if the forth arg is within limit
        else if (atoi(argv[4]) < 0 || atoi(argv[4]) > 1 || !isdigit(argv[4][0]))
        {
            // print out the failure message and the specific reason for failure
            printf("%s, \n%s\n", argument_failure, "Your forth argument must be between 0 and 1");
            //return -1 so the program get to exit in the main method.
            return -1;
        }
        // check if the fifth arg is within limit
        else if (atoi(argv[5]) < 0 || atoi(argv[5]) > 1 || !isdigit(argv[5][0]))
        {
            // print out the failure message and the specific reason for failure
            printf("%s, \n%s\n", argument_failure, "Your fifth argument must be between 0 and 1");
            //return -1 so the program get to exit in the main method.
            return -1;
        }
    }
    // return 0 and exit the program successfully.
    return 0;
}