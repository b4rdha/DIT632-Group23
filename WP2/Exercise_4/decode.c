// (C) Bassam Group: 23 (2022)
// Work package 2
// Exercise 4 part 2 (Unpacking bits)
// Submission code: 101zX!
/*
------------------------------------------------------------------
The program takes one hexadecimal argument value and unpack the bits into predefined options from exercise 4 part 1.
 the 8 bits are divided for 5 different options, each bit or group of bits means a specific option and its value:
engine_on       0..1     1      Is engine on or off . This is bit no 7
gear_pos        0..4     3      The position of the gear. Three bits means that we can have 23 == 7 positions
key_pos         0..2     2      Position of the key – 0 == stop, 1 == on, 2 == engine starter on
brake1          0..1     1      Position of the front brakes
brake2          0..1     1      Position of the rear brakes. Bit no 0 (LSB)
In case of running the program with no arguments or wrong digit values, the program shall prompt
 a message to the user guiding how to run the program correctly.
------------------------------------------------------------------

References:
 - https://www.geeksforgeeks.org/program-for-hexadecimal-to-decimal/?ref=gcse
--------------------------------------------------------------
*/


// include libraries
#include <stdio.h>
#include <string.h>


// definitions
#define f_bit 1     // to be able to mask the bits with the first bit to check if it's filled "1s".
#define f_2_bits 3  // to be able to mask the bits with the first 2 bits to check if any of them filled "1".
#define f_3_bits 7  // to be able to mask the bits with the first 3 bits to check if any of them filled "1".


// enums for bits values

// motor value can be between 0 and 1
enum MOTOR { off , on };
// gear value can be between 0 and 7
enum GEAR { zero , one, two, three, four, five , six, seven};
// key position value can be between 0 and 2
enum KEY_P { stop , key_on, motor_start_on };
// break value can be between 0 and 1
enum BREAK_1 { front_zero , front_one };
// rear break value can be between 0 and 1
enum REAR_BREAK {rear_zero, rear_one};


// function declarations

// function that converts the program argument to a hexadecimal value.
u_int8_t hexadecimalToDecimal(const char* hexadecimal_values);

// function that gets specific bits from a byte
int find_bits (const u_int8_t* my_bits, u_int8_t to_unpack_bits, u_int8_t n_shifts);

//function that unpack the bits from a byte and print out the value
void unpack_bits(u_int8_t* packed_bits_ptr);



// global variables
static char argument_failure [] = "\nYou might have not entered one argument or entered more than one argument. "
                                  "Type: \"./filename -h\" for help![on windows: \"filename.exe -h\"]";

static char help [] = "\nTo be able to run the program >>> \n- Type:  './<<name of your executable file>>', "
                      "a whitespace and \"< valid hexadecimal argument eg (AB)> \" \n"
                      "[on windows: \"filename.exe <AB>\" ]\n- If you wish to run this program in the pipeline then you should use the following command instead:\n"
                      "\t./thisFileName AB | xargs ./theOtherFileName [on windows: \"./thisFileName.exe AB | xargs -0 ./theOtherFileName.exe\" ]";



/**
 * Main function for the program.
 * @param argc - number of program arguments
 * @param argv - array of strings with program arguments, idexed from 0
 * @returns - 0 if ok, positive integer if there is an error code
 */
int main (int argc, char** argv){

    // the length of the args can't be less or higher than 5
    if (argc > 2 || argc < 2)
    {
        // print out a failure message to the user
        printf("\n%s\n", argument_failure);
        // return -1 and exit the program
        return -1;
    }

    // if the user asks for help
    if (strcmp(argv[1], "-h") == 0)
    {
        // prompt to the user a guide message on how to run the program correctly.
        printf("%s\n", help);

        // return 0 and exit the program successfully.
        return 0;
    }


    // loop just for the first 2 characters in the program argument
    for (int i = 0; i < 2 ; ++i) {

        // if the value of argv[1][i] is not within the hexadecimal values it fails
        if (
                !(argv[1][i] >= 'A' && argv[1][i] <= 'F') &&
                !(argv[1][i] >= '0' && argv[1][i] <= '9')
                )
        {
            // print out a failure message to the user
            printf("%s, \n%s\n", argument_failure, "the values you have entered are not hexadecimal values");
            // return -1 and exit the program
            return -1;
        }
        // if values are within the hex_values run the program
        else
        {
            // initialise a byte and assign the hexadecimal value to it
            u_int8_t packed_bits = hexadecimalToDecimal(argv[1]);
            // create a pointer to the hexadecimal value byte to use it in other functions
            u_int8_t* packed_bits_ptr;
            // assign the pointer value to the packed_bits address.
            packed_bits_ptr = &packed_bits;
            // unpack the packed_bits and print out the values
            unpack_bits(packed_bits_ptr);

            // return 0 and exit the program successfully.
            return 0;
        }
    }
}


/**
 * find_bits function. that take packed bits and get some specific bit/s value from it
 * @param my_bits - pointer to the bits that are already packed in a byte.
 * @param to_unpack_bits - the bits which we need to extract
 * @param n_shifts - number of shifts to be bale to get the bits from the right pace in a byte
 * @returns - int .. it returns the value of the bit or bytes we search for
 */
int find_bits (const u_int8_t* my_bits, u_int8_t to_unpack_bits, u_int8_t n_shifts)
{

    // the bits to return will be th result of shifting
    // the packed bits to the front places of the byte eg, 0b 0000 0001 LSB
    // and then we will mask these bits with the bits we want to get the value for using the bits & operator.
    // eg, 0b 0000 00101 & 0b 0000 00111 = 0b 0000 00101  = decimal 5
    u_int8_t bits = to_unpack_bits & (*my_bits >> n_shifts);

    // return the bits
    return bits;
}

/**
 * unpack_bits function. that take packed bits in a byte and unpack all the bits values
 * with help of find_bits method
 * @param packed_bits_ptr - pointer to the bits that are already packed in a byte.
 * @returns - void
 */
void unpack_bits(u_int8_t* packed_bits_ptr)
{
    // initialise the enums
    enum MOTOR state;
    enum GEAR gear;
    enum KEY_P key;
    enum BREAK_1 break_1;
    enum REAR_BREAK rear_break;


    // set the motor state.
    state = find_bits(packed_bits_ptr, f_bit,7);
    // set the gear position.
    gear = (find_bits(packed_bits_ptr, f_3_bits,4));
    // set the key position
    key = (find_bits(packed_bits_ptr, f_2_bits,2));
    // set the break position
    break_1 = (find_bits(packed_bits_ptr, f_bit,1));
    // set the rear break position
    rear_break = (find_bits(packed_bits_ptr, f_bit,0));

    // plot the results for each value
    printf("%s\t\t%s\n", "Name", "  Value");
    printf("%s\n", "-----------------------------------------------");
    printf("%s\t\t%d\n", "Engine on", state);
    printf("%s\t\t%d\n", "Gear_pos", gear);
    printf("%s\t\t\t%d\n", "Key_pos", key);
    printf("%s\t\t\t%d\n", "Break_1", break_1);
    printf("%s\t\t%d\n", "Rear_break", rear_break);
}



/**
 * hexadecimalToDecimal function. that take a hexadecimal value and convert it to decimal
 * @param hexadecimal_values - pointer to the hexadecimal_values.
 * @returns - void
 * adopted from https://www.geeksforgeeks.org/program-for-hexadecimal-to-decimal/?ref=gcse
 */
u_int8_t hexadecimalToDecimal(const char* hexadecimal_values)
{

    int base = 1; // initialise the base to 1
    u_int8_t decimal_value = 0; // initialise the decimal value to 0

    for (int i = 1 ; i >= 0; i--) {// loop for the given hexadecimal argument

        // check if each given char is within the hexadecimal values.
        if (hexadecimal_values[i] >= '0' && hexadecimal_values[i] <= '9') {

            // if the value between 0 and 9 we get the integer value of the char by subtracting 48 and
            // assign it to the decimal value
            decimal_value = decimal_value + ((int)hexadecimal_values[i] - 48) * base;

            base = base * 16; // multiply the base with 16 as each decimal value is base 16
        }

        // if the value within A and F then we need to extract the integer from the char subtracting -55
        else if (hexadecimal_values[i] >= 'A' && hexadecimal_values[i] <= 'F') {

            decimal_value = decimal_value + ((int)hexadecimal_values[i] - 55) * base; // assign it to the decimal value

            base = base * 16; // multiply the base with 16 as each decimal value is base 16
        }
    }

    // return the converted decimal value
    return decimal_value;
}