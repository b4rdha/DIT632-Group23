// (C) Bassam Group: 23 (2022)
// Work package 1
// Exercise 4 part 2 (Binary to Hexadecimal convertor)
// Submission code: TODO
// TODO: ask if we need to check if the binary value is higher than long type value!!

/*
------------------------------------------------------------------
A program using the GNU Compiler Collections(GCC) through provided
arguments and error handling for the major possible cases.

A program takes a binary input to convert to hexadecimal format.
The program takes a binary value and convert to hexadecimal format.

In case of running the program with no arguments or wrong digit values, the program shall prompt
 a message to the user guiding how to run the program correctly.
------------------------------------------------------------------
*/


//-----------------------------Included libraries------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//-------------------------------------------------------------------------------------



//-----------------------------function declaration------------------------------------
int binaryToHec(char binary_array[]);
//-------------------------------------------------------------------------------------



//-----------------------------global variables------------------------------------
static char conversion_failure [] = "Conversion failed! You have not entered a correct number argument. "
                                    "Type: \"./filename -h\" for help![on windows: \"filename.exe -h\"]";

static char argument_failure [] = "You might have not entered an argument or entered more than one argument. "
                                  "Type: \"./filename -h\" for help![on windows: \"filename.exe -h\"]";

static char conversion_interrupted [] = "Conversion interrupted due to non-binary value in your argument. "
                                    "Type: \"./filename -h\" for help![on windows: \"filename.exe -h\"]";

static char help [] = "To be able to run the program >>> \nType:  './<<name of your executable file>>', "
                      "a whitespace and \"<valid number between (0 - 4294 967 295)> \"the maximum value of "
                      "type unsigned long\"\nlook at this example\" [i.e.= \"./filename <number>\" ], "
                      "[on windows: \"filename.exe <number>\" ]\n";

//-------------------------------------------------------------------------------------



// main function
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
        if ((!isdigit(argv[1][i])))
        {
            // if any char is not a digit >> prompt to the user a conversion failure message and guide to run the help command.
            printf ("%s\n", conversion_failure);

            // return 2 and exit the program.
            return 2;
        }
    }

    // run the conversion and check if we have any digit that is not binary
    // in case of non-binary digits the binaryToHec function will return 2, then we end the process here with code 2 also and
    // binaryToHec method will also prompt a conversion_interrupted message to the user and to run the help command.
    if (binaryToHec(argv[1]) == 2)
    {

        // return 2 and end the process.
        return 2;
    }

    // else return 0 if successful and exit the program
    return 0;
}



/*
* Function which converts a binary value to hexadecimal value.
* takes in parameter an array of binary digits to convert
* to hexadecimal value
* @param binary_array - array holding the binary digits to convert.
*/
int binaryToHec(char binary_array[])
{
    // create array to divide and group the given binary_array to smaller groups of 4 bits.
    char bits_group [4];

    // loop over the given binary_array till last index
    for (int i = 0; i <= strlen(binary_array )- 1; i++)
    {
        // if each binary bit in the given binary_array is a binary digit or not
        if (binary_array[i] == '1' || binary_array[i] == '0'){

            // if it's binary digit then push it to the bits_group array of 4 bits
            // using the module operator to push it in the right index.
            bits_group[i % 4] = binary_array[i];


            // checks if we have already a group of 4 bits
            if ((i % 4) == 3){

                //  convert the digits in bits_group array to long type suing strol function
                //  the string
                // of chars created in bits_group array.
                unsigned long x = strtol(bits_group, NULL, 2);

                // print out the long value x as a lX (long hexadecimal) value.
                printf ("%lX", x);
            }
        }
        else
        {
            // in case of a non-binary digit in the given binary_array, prompt to the user a conversion_interrupted message
            // and guide to help command
            printf ("\n%s\n", conversion_interrupted);

            // return 2 to exit the function
            return 2;
        }
    }

    // in case of successful conversion this message will be coming after the hexadecimal value.
    printf("%s%s%s\n" , " is the (", binary_array, ")'s hexadecimal value.");

    // return 0 when a conversion is successful.
    return 0;
}
