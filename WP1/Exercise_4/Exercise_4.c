// (C) Bassam Group: 23 (2022)
// Work package 1
// Exercise 4 part 1 (Decimal to Binary convertor)
// Submission code: aB-5311
//
/*
------------------------------------------------------------------
The program takes a decimal input to convert to binary format.
It takes a maximum value for unsigned long type (from 0 to 4294 967 295) and convert to binary format as follows:
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


// function declaration

//Function which converts a decimal to binary.
//takes as a first param decimal number to convert and another param bits
//to determine the bits format if it's 8 bits, 16 bits or 32 bits
void decimalToBinary(char* toConvert [], int bits);



// global variables
static char conversion_failure [] = "\nConversion failed! You have not entered a correct number argument. "
                                    "Type: \"./filename -h\" for help![on windows: \"filename.exe -h\"]";

static char argument_failure [] = "\nYou might have not entered an argument or entered more than one argument. "
                                  "Type: \"./filename -h\" for help![on windows: \"filename.exe -h\"]";

static char help [] = "\nTo be able to run the program >>> \n- Type:  './<<name of your executable file>>', "
                      "a whitespace and \"<valid number between (0 - 4294 967 295)> \"the maximum value of "
                      "type unsigned long\"\n\tlook at this example\" [i.e.= \"./filename <number>\" ], "
                      "[on windows: \"filename.exe <number>\" ]\n- If you wish to run this program in the pipeline then you should use the following command instead:\n"
                      "\t./thisFileName <12> | xargs ./theOtherFileName";




/**
 * Main function for the program.
 * @param argc - number of program arguments
 * @param argv - array of strings with program arguments, idexed from 0
 * @returns - 0 if ok, positive integer if there is an error code
 */
int main(int argc, char *argv[]){


    // check if we have no arguments given or if we have more than one argument given.
    if (argv[1] == NULL || argc > 2)
    {
        // prompt to the user an argument failure message and guide to run the help command.
        printf("%s\n", argument_failure);

        // failure, so return 2 and exit the program
        return 2;
    }

    // get the length of argv[1]
    int length = 0;

    //loop over the argument till we reach the null sign.
    while (argv[1][length] != '\0'){
        length ++;
    }

    // check if the given argument -h which means help.
    if (strcmp(argv[1], "-h") == 0)
    {
        // prompt to the user a guide message on how to run the program correctly.
        printf("%s\n", help);

        // return 0 and exit the program successfully.
        return 0;
    }

    // loop over the given argument to check if each char is a digit and find an appropriate data type.
    for (int i = 0; i < length; ++i) {

        // check if any char in the argument is not a digit
        if (!isdigit(argv[1][i]))
        {
            // if any char is not a digit >> prompt to the user a conversion failure message and guide to run the help command.
            printf ("%s\n", conversion_failure);

            // failure, return 2 and exit the program.
            return 2;
        }
    }

    // if the length is less than 3 then the data type shall be unsigned char
    // But if the length is <= 3 then we check for each digit if it's < than the highest value of unsigned char
    // If it's equal then we check for the next digit.
    // if so then the data type is Unsigned char which means binary format 8 bits
    //unsigned char      (0 - 255)                    = 8 bits.
    if ( ( length >= 0 && length < 3 ) || (length <= 3 && (
            ( (  (unsigned int) argv[1][0] - '0') < 2) ||
            ( (( (unsigned int) argv[1][0] - '0') < 3) && (( (unsigned int) argv[1][1] - '0') < 5) ) ||
            ( (( (unsigned int) argv[1][0] - '0') < 3) && (( (unsigned int) argv[1][1] - '0') <= 5) && (( (unsigned int) argv[1][2] - '0') <= 5) )
            )
            )
            )
    {
        // use decimalToBinary helper method to convert to the desired binary format (8 bits) from the given number
        decimalToBinary((char **) argv[1], 8);
    }

        // else if
        // if the length is less than 5 then the data type shall be unsigned INT
        // But if the length is <= 5 then we check for each digit if it's < than the highest value of unsigned INT
        // If it's equal then we check for the next digit.
        // if so then the data type is Unsigned INT which means binary format 8 bits
        //unsigned short int (255 - 65 535)               = 16 bits.

    else if ( (length >= 3 && length < 5)  || ( length <= 5 && (
            ( (  (unsigned int) argv[1][0] - '0') < 6) ||
            ( (( (unsigned int) argv[1][0] - '0') <= 6) && (( (unsigned int) argv[1][1] - '0') < 5) ) ||
            ( (( (unsigned int) argv[1][0] - '0') <= 6) && (( (unsigned int) argv[1][1] - '0') <= 5) && (( (unsigned int) argv[1][2] - '0') < 5) ) ||
            ( (( (unsigned int) argv[1][0] - '0') <= 6) && (( (unsigned int) argv[1][1] - '0') <= 5) && (( (unsigned int) argv[1][2] - '0') <= 5) && (( (unsigned int) argv[1][3] - '0') < 3) ) ||
            ( (( (unsigned int) argv[1][0] - '0') <= 6) && (( (unsigned int) argv[1][1] - '0') <= 5) && (( (unsigned int) argv[1][2] - '0') <= 5) && (( (unsigned int) argv[1][3] - '0') <= 3) && (( (unsigned int) argv[1][4] - '0') <= 5) )
            )
            )
            )
    {
        // use decimalToBinary helper method to convert to the desired binary format (8 bits) from the given number
        decimalToBinary((char **) argv[1], 16);
    }

        // else if
        // if the length is less than 10 then the data type shall be unsigned Long
        // But if the length is <= 10 then we check for each digit if it's < than the highest value of unsigned Long
        // If it's equal then we check for the next digit.
        // if so then the data type is Unsigned Long which means binary format 8 bits
        //unsigned long int  (65 535 - 4294 967 295)      = 32 bits.
    else if (  (length >= 5 && length < 10) || ( length <= 10 && (
            ( (  (unsigned int) argv[1][0] - '0') < 4) ||
            ( (( (unsigned int) argv[1][0] - '0') <= 4) && (( (unsigned int) argv[1][1] - '0') < 2) ) ||
            ( (( (unsigned int) argv[1][0] - '0') <= 4) && (( (unsigned int) argv[1][1] - '0') <= 2) && (( (unsigned int) argv[1][2] - '0') < 9) ) ||
            ( (( (unsigned int) argv[1][0] - '0') <= 4) && (( (unsigned int) argv[1][1] - '0') <= 2) && (( (unsigned int) argv[1][2] - '0') <= 9) && (( (unsigned int) argv[1][3] - '0') < 4) ) ||
            ( (( (unsigned int) argv[1][0] - '0') <= 4) && (( (unsigned int) argv[1][1] - '0') <= 2) && (( (unsigned int) argv[1][2] - '0') <= 9) && (( (unsigned int) argv[1][3] - '0') <= 4) && (( (unsigned int) argv[1][4] - '0') < 9) ) ||
            ( (( (unsigned int) argv[1][0] - '0') <= 4) && (( (unsigned int) argv[1][1] - '0') <= 2) && (( (unsigned int) argv[1][2] - '0') <= 9) && (( (unsigned int) argv[1][3] - '0') <= 4) && (( (unsigned int) argv[1][4] - '0') <= 9) && (( (unsigned int) argv[1][5] - '0') < 6) ) ||
            ( (( (unsigned int) argv[1][0] - '0') <= 4) && (( (unsigned int) argv[1][1] - '0') <= 2) && (( (unsigned int) argv[1][2] - '0') <= 9) && (( (unsigned int) argv[1][3] - '0') <= 4) && (( (unsigned int) argv[1][4] - '0') <= 9) && (( (unsigned int) argv[1][5] - '0') <= 6) && (( (unsigned int) argv[1][6] - '0') < 7) ) ||
            ( (( (unsigned int) argv[1][0] - '0') <= 4) && (( (unsigned int) argv[1][1] - '0') <= 2) && (( (unsigned int) argv[1][2] - '0') <= 9) && (( (unsigned int) argv[1][3] - '0') <= 4) && (( (unsigned int) argv[1][4] - '0') <= 9) && (( (unsigned int) argv[1][5] - '0') <= 6) && (( (unsigned int) argv[1][6] - '0') <= 7) && (( (unsigned int) argv[1][7] - '0') < 2) ) ||
            ( (( (unsigned int) argv[1][0] - '0') <= 4) && (( (unsigned int) argv[1][1] - '0') <= 2) && (( (unsigned int) argv[1][2] - '0') <= 9) && (( (unsigned int) argv[1][3] - '0') <= 4) && (( (unsigned int) argv[1][4] - '0') <= 9) && (( (unsigned int) argv[1][5] - '0') <= 6) && (( (unsigned int) argv[1][6] - '0') <= 7) && (( (unsigned int) argv[1][7] - '0') <= 2) && (( (unsigned int) argv[1][8] - '0') < 9) ) ||
            ( (( (unsigned int) argv[1][0] - '0') <= 4) && (( (unsigned int) argv[1][1] - '0') <= 2) && (( (unsigned int) argv[1][2] - '0') <= 9) && (( (unsigned int) argv[1][3] - '0') <= 4) && (( (unsigned int) argv[1][4] - '0') <= 9) && (( (unsigned int) argv[1][5] - '0') <= 6) && (( (unsigned int) argv[1][6] - '0') <= 7) && (( (unsigned int) argv[1][7] - '0') <= 2) && (( (unsigned int) argv[1][8] - '0') <= 9) && (( (unsigned int) argv[1][9] - '0') <= 5)  )
            )
            )
            )
    {

        // use decimalToBinary helper method to convert to the desired binary format (8 bits) from the given number
        decimalToBinary((char **) argv[1], 32);

    }

        // if not any case of the previous ones then the number is higher than the allowed value which we won't accept and return 2 with error message
    else
    {
        // if the value of the number is higher or less than unsigned long typ (from 0 to 4294 967 295) then
        // prompt a conversion failure message and guide to run the help command.
        printf("%s\n", conversion_failure);
        printf("%s\n", "The number must be between 0 - 4294 967 295");

        // failure, return 2 and exit the program.
        return 2;
    }


    // return 0 if successful and exit the program
    return 0;
}


/**
* Function which converts a decimal to binary.
* takes as a first param decimal number to convert and another param bits
* to determine the bits format if it's 8 bits, 16 bits or 32 bits
* @param toConvert - array of chars holding the decimal number to convert.
* @param bits - how many bits we want to convert the number to.
*/
void decimalToBinary(char* toConvert [], int bits)
{
    // loop for the number of bits (e.g 8 bits >> then loop 8 times)
    for (int i = bits-1; i >= 0; i--) {



        // which binary format we convert the number to 8 bits or 16 bits
        if (bits == 8 || bits == 16)
        {
            // each loop we divide the number "toConvert" on 2 to the power to i and get the result.
            // which is the same as shifting the bits to the right (number_to_convert >> i)
            // check if the result is equal to 1 for the value and also bitwise using the & operator.
            printf("%d", ( atoi((char* )toConvert) >> i & 1));
        }
            // otherwise, 32 bits
        else
        {
            // shifting the bits
            printf("%lu", (strtol(( char *) toConvert, NULL, 10) >> i & 1));
        }
    }
    printf("%s", "\n");
}