// (C) Bassam Group: 23 (2022)
// Work package 1
// Exercise 4 part 2 (Binary to Hexadecimal convertor)
// Submission code: aB-5311
/*
------------------------------------------------------------------
A program takes a binary input to convert to hexadecimal format.
The program takes a binary value and convert to hexadecimal format.

In case of running the program with no arguments or wrong digit values, the program shall prompt
 a message to the user guiding how to run the program correctly.
------------------------------------------------------------------
*/


//Included libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



//function declaration

//Function which converts a binary value to hexadecimal value.
//takes in parameter an array of binary digits to convert
//to hexadecimal value
int binaryToHec( const char binary_array[], int length);




//global variables
static char conversion_failure [] = "\nConversion failed! You have not entered a correct number argument. "
                                    "Type: \"./filename -h\" for help![on windows: \"filename.exe -h\"]";

static char argument_failure [] = "\nYou might have not entered an argument or entered more than one argument. "
                                  "Type: \"./filename -h\" for help![on windows: \"filename.exe -h\"]";

static char help [] = "\nTo be able to run the program >>> \n- Type:  './<<name of your executable file>>', "
                      "a whitespace and \"<binary number>\"""\n\tlook at this example\" [i.e.= \"./filename <00001111>\" ], "
                      "[on windows: \"filename.exe <00001111>\" ]\n- If you wish to run this program in the pipeline then you should use the following command instead:\n"
                      "\t./thisFileName <00001111> | xargs ./theOtherFileName\n";




/**
 * Main function for the program.
 * @param argc - number of program arguments
 * @param argv - array of strings with program arguments, idexed from 0
 * @returns - 0 if ok, positive integer if there is an error code
 */
int main(int argc, char* argv[]){

    // check if we have no arguments given or if we have more than one argument given.
    if (argv[1] == NULL)
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

    // initial length of argv[1]
    int length = 0;

    //loop over the argument till we reach the null sign.
    while (argv[1][length] != '\0'){
        length ++;
    }

    // a char array to hold the binary values given
    // this is made for the reason in case the file will be running in a pipeline
     char bin_values [32];


    // loop over the given argument
    for (int i = 0; i < length; ++i) {

        // loop over the argv[1] to get the binary values to be converted *extract just 1s or 0s.
        if (!(isdigit(argv[1][i])) && !(argv[1][i] == '0' || argv[1][i] == '1'))
        {

            // if any char is not a digit >> prompt to the user a conversion failure message and guide to run the help command.
            printf ("%s\n", conversion_failure);

            // failure, return 2 and exit the program.
            return 2;

        }
        // if the length of the argv[1] is less than 8 then the conversion is failed.
        else if (length < 8)
        {
            // if any char is not a digit >> prompt to the user a conversion failure message and guide to run the help command.
            printf ("%s\n", conversion_failure);

            // failure, return 2 and exit the program.
            return 2;
        }
        else
        {
            // copy the binary values in the bin_values array
            bin_values [i] =  argv[1][i];
        }
    }

    // Use the helper method binaryToHec to convert the binary number "char array"
    binaryToHec(bin_values, length);

    // else return 0 if successful and exit the program
    return 0;
}





/**
* Function which converts a binary value to hexadecimal value.
* takes in parameter an array of binary digits to convert
* to hexadecimal value
* @param binary_array - array holding the binary digits to convert.
*/

int binaryToHec(const char binary_array[], int length) {

    // create array to divide and group the given binary_array to smaller groups of 4 bits.
    char bits_group[4];

    // loop over the given binary_array till last index
    for (int i = 0; i < length; i++) {

            // if it's binary digit then push it to the bits_group array of 4 bits
            // using the module operator to push it in the right index.
            bits_group[i % 4] = binary_array[i];

            // checks if we have already a group of 4 bits using the module operator
            if ((i % 4) == 3) {

                // print out the long value x as a lX hexadecimal value using strol method.
                // passing the bits_group array
                printf("%lX", strtol(bits_group, NULL, 2));
            }
    }
    printf("%s\n", " is the hexadecimal value for the number you have entered");
    return 0;
}