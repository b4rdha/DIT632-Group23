// (C) Bassam Group: 23 (2022)
// Work package 1
// Exercise 4 part 1 (Decimal to Binary convertor)
// Submission code: TODO

/*
------------------------------------------------------------------
A program using the GNU Compiler Collections(GCC) through provided
arguments and error handling for the major possible cases.

A program takes a decimal input to convert to binary format.
The program takes a maximum value for unsigned long type (from 0 to 4294 967 295) and convert to binary format as follows:
    unsigned long int  (65 535 - 4294 967 295)      = 32 bits.
    unsigned short int (255 - 65 535)               = 16 bits.
    unsigned char      (0 - 255)                    = 8 bits.
In case of running the program with no arguments or wrong digit values, the program shall prompt
 a message to the user guiding how to run the program correctly.
------------------------------------------------------------------
*/

// Included libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


// function declaration
void decimalToBinary(unsigned long n, int bits);


// global variables
static char conversion_failure [] = "Conversion failed! You have not entered a correct number argument. "
                                    "Type: \"./filename -h\" for help![on windows: \"filename.exe -h\"]";

static char argument_failure [] = "You might have not entered an argument or entered more than one argument. "
                                  "Type: \"./filename -h\" for help![on windows: \"filename.exe -h\"]";

static char help [] = "To be able to run the program >>> \nType:  './<<name of your executable file>>', "
                      "a whitespace and \"<valid number between (0 - 4294 967 295)> \"the maximum value of "
                      "type unsigned long\"\nlook at this example\" [i.e.= \"./filename <number>\" ], "
                      "[on windows: \"filename.exe <number>\" ]\n";



int main(int argc, char *argv[]){


    // check if we have no arguments given or if we have more than one argument given.
    if (argv[1] == NULL || argc > 2)
    {
        // prompt to the user an argument failure message and guide to run the help command.
        printf("%s\n", argument_failure);

        // return 2 and exit the program.
        return 2;
    }


    // check if the given argument -h which means help.
    if (strcmp(argv[1], "-h") == 0)
    {
        // prompt to the user a guide message on how to run the program correctly.
        printf("%s\n", help);

        // return 0 and exit the program successfully.
        return 0;
    }

    // loop over the given argument
    for (int i = 0; i < strlen(argv[1]); ++i) {

        // check if any char in the argument is not a digit
        if (!isdigit(argv[1][i]))
        {
            // if any char is not a digit >> prompt to the user a conversion failure message and guide to run the help command.
            printf ("%s\n", conversion_failure);

            // // return 2 and exit the program.
            return 2;
        }
    }

    // used for the strtoul() function to indicate where the conversion stopped.
    char *ptr;

    // if we reach this step then the argument is a valid number
    // convert the taken argument and store it in unsigned long type.
    unsigned long args_to_digits = strtoul(argv[1],&ptr,10);

    // check if this number value is 32 bits format
    if (args_to_digits > 65535 && args_to_digits <= 4294967295)
    {
        // prompt a message with the number given and which binary format it will apply
        printf("%s%lu %s\n", "this number ( ", args_to_digits, ")'s binary value is (32 bits)");

        // use decimalToBinary method to do conversion given the unsigned long value and the bits format to convert to.
        decimalToBinary(args_to_digits, 32);
    }

        // check if this number value is 16 bits format
    else if (args_to_digits > 255 && args_to_digits <= 65535)
    {
        // prompt a message with the number given and which binary format it will apply
        printf("%s%lu %s\n", "this number ( ", args_to_digits, ")'s binary value is (16 bits)");

        // use decimalToBinary method to do conversion given the unsigned long value and the bits format to convert to.
        decimalToBinary(args_to_digits, 16);
    }
        // check if this number value is 8 bits format
    else if (args_to_digits >= 0 && args_to_digits <= 255)
    {
        // prompt a message with the number given and which binary format it will apply
        printf("%s%lu %s\n", "this number ( ", args_to_digits, ")'s binary value is (8 bits)");

        // use decimalToBinary method to do conversion given the unsigned long value and the bits format to convert to.
        decimalToBinary(args_to_digits, 8);
    }
    else
    {
        // if the value of the number is higher or less than unsigned long typ (from 0 to 4294 967 295) then
        // prompt a conversion failure message and guide to run the help command.
        printf("%s\n", conversion_failure);

        // return 2 and exit the program.
        return 2;
    }

    // free all the global variables
    //free(no_correct_number); !!

    // else return 0 if successful and exit the program
    return 0;
}




/*
* Function which converts a decimal to binary.
* takes as a first param decimal number to convert and another param bits
* to determine the bits format if it's 8 bits, 16 bits or 32 bits
* @param Num_to_convert - which decimal number to convert.
* @param bits - how many bits we want to convert the number to.
*/
void decimalToBinary(unsigned long Num_to_convert, int bits)
{
    // loop for the number of bits (e.g 8 bits >> then loop 8 times)
    for (int i = bits-1; i >= 0; i--) {

        // each loop we divide Num_to_convert on 2 to the power to i and get the result.
        // another way to do it:  int result = Num_to_convert >> i; with the right shift operator
        int result = Num_to_convert / pow(2,i);

        // check if the result is equal to 1 for the value and also bitwise using the & operator to check bitwise.
        // the output shall be 1 or 0 which maps to true or false.
        printf("%d", ( result & 1 ));
    }
}
