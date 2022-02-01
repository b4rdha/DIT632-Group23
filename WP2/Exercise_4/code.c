
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void set_bits (u_int8_t* old_bits, int new_bits, int n_shifts);
void pack_arg_bits(u_int8_t* packed_bits_ptr, char** argv);
int binaryToHec(const u_int8_t* packed_bits_ptr);



// global variables
static char failure [] = "\nConversion failed! You have not entered a correct number argument. "
                                    "Type: \"./filename -h\" for help![on windows: \"filename.exe -h\"]";

static char argument_failure [] = "\nYou might have not entered 5 arguments or entered more than 5 arguments. "
                                  "Type: \"./filename -h\" for help![on windows: \"filename.exe -h\"]";


//TODO: edit the documentation and this help message
static char help [] = "\nTo be able to run the program >>> \n- Type:  './<<name of your executable file>>', "
                      "a whitespace and \"<valid number between (0 - 4294 967 295)> \"the maximum value of "
                      "type unsigned long\"\n\tlook at this example\" [i.e.= \"./filename <number>\" ], "
                      "[on windows: \"filename.exe <number>\" ]\n- If you wish to run this program in the pipeline then you should use the following command instead:\n"
                      "\t./thisFileName <12> | xargs ./theOtherFileName [on windows: \"./thisFileName.exe 14 | xargs -0 ./theOtherFileName.exe\" ]";



int main(int argc, char**argv){

    // the length of the args can\t be less or higher than 5
    if (argc > 6 || argc < 6)
    {
        printf("%s , \n%s\n", argument_failure, "You must provide 5 arguments");

        return 2;
    }

    if (strcmp(argv[1], "-h") == 0)
    {
        // prompt to the user a guide message on how to run the program correctly.
        printf("%s\n", help);

        // return 0 and exit the program successfully.
        return 0;
    }

    // check if each arg is not null and the value of each arg is within limit
    for (int i = 0; i <6 ; ++i) {

        if (atoi(argv[1]) < 0 || atoi(argv[1]) > 1 || !isdigit(argv[1][0]))
        {
            printf("%s, \n%s\n", argument_failure, "Your first argument must be between 0 and 1");
            return 2;
        }
        else if (atoi(argv[2]) < 0 || atoi(argv[2]) > 7 || !isdigit(argv[2][0]))
        {
            printf("%s, \n%s\n", argument_failure, "Your second argument must be between 0 and 7");
            return 2;
        }
        else if (atoi(argv[3]) < 0 || atoi(argv[3]) > 2 || !isdigit(argv[3][0]))
        {
            printf("%s, \n%s\n", argument_failure, "Your third argument must be between 0 and 2");
            return 2;
        }
        else if (atoi(argv[4]) < 0 || atoi(argv[4]) > 1 || !isdigit(argv[4][0]))
        {
            printf("%s, \n%s\n", argument_failure, "Your forth argument must be between 0 and 1");
            return 2;
        }
        else if (atoi(argv[5]) < 0 || atoi(argv[5]) > 1 || !isdigit(argv[5][0]))
        {
            printf("%s, \n%s\n", argument_failure, "Your fifth argument must be between 0 and 1");
            return 2;
        }
    }


    // run the program
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