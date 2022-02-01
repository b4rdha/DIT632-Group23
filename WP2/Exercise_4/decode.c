
#include <stdio.h>
#include <string.h>
#include <ctype.h>


//TODO: organize the order here
enum MOTOR { off , on };
enum GEAR { zero , one, two, three, four, five , six, seven, eight };
enum KEY_P { stop , key_on, motor_start_on };
enum BREAK_1 { front_zero , front_one };
enum REAR_BREAK {rear_zero, rear_one};



int find_bits (const u_int8_t* my_bits, u_int8_t to_unpack_bits, u_int8_t n_shifts);
void unpack_bits(u_int8_t* packed_bits_ptr);
u_int8_t hexadecimalToDecimal(const char* hexadecimal_values);




#define f_bit 1
#define f_2_bits 3
#define f_3_bits 7

// global variables
static char failure [] = "\nConversion failed! You have not entered a correct number argument. "
                         "Type: \"./filename -h\" for help![on windows: \"filename.exe -h\"]";

static char argument_failure [] = "\nYou might have not entered an argument or entered more than one argument. "
                                  "Type: \"./filename -h\" for help![on windows: \"filename.exe -h\"]";


//TODO: edit the documentation and this help message
static char help [] = "\nTo be able to run the program >>> \n- Type:  './<<name of your executable file>>', "
                      "a whitespace and \"<valid number between (0 - 4294 967 295)> \"the maximum value of "
                      "type unsigned long\"\n\tlook at this example\" [i.e.= \"./filename <number>\" ], "
                      "[on windows: \"filename.exe <number>\" ]\n- If you wish to run this program in the pipeline then you should use the following command instead:\n"
                      "\t./thisFileName <12> | xargs ./theOtherFileName [on windows: \"./thisFileName.exe 14 | xargs -0 ./theOtherFileName.exe\" ]";


int main (int argc, char** argv){

    // the length of the args can\t be less or higher than 5
    if (argc > 2 || argc < 2)
    {
        printf("%s , \n%s\n", argument_failure, "You must provide exactly one argument");

        return 2;
    }

    if (strcmp(argv[1], "-h") == 0)
    {
        // prompt to the user a guide message on how to run the program correctly.
        printf("%s\n", help);

        // return 0 and exit the program successfully.
        return 0;
    }

    for (int i = 0; i < 2 ; ++i) {

        if (
                !(argv[1][i] >= 'A' && argv[1][i] <= 'F') &&
                !(argv[1][i] >= '0' && argv[1][i] <= '9')
                )
        {
            printf("%s, \n%s\n", argument_failure, "Here too");
            return 2;
        }
        else
        {
            u_int8_t packed_bits = hexadecimalToDecimal(argv[1]);
            u_int8_t* packed_bits_ptr;
            packed_bits_ptr = &packed_bits;
            unpack_bits(packed_bits_ptr);

            return 0;
        }
    }

}

int find_bits (const u_int8_t* my_bits, u_int8_t to_unpack_bits, u_int8_t n_shifts)
{

    //to know how many to shift then will cast the argument to int .
    // the new value will be shifted with the 0
    u_int8_t a = to_unpack_bits & (*my_bits >> n_shifts);
    return a;

}


void unpack_bits(u_int8_t* packed_bits_ptr)
{
    // set the first argument bits
    enum MOTOR state;
    enum GEAR gear;
    enum KEY_P key;
    enum BREAK_1 break_1;
    enum REAR_BREAK rear_break;


    state = (find_bits(packed_bits_ptr, f_bit,7));

    printf("%s\t\t%s\n", "Name", "  Value");
    printf("%s\n", "-----------------------------------------------");

    printf("%s\t\t%d\n", "Engine on", state);

    gear = (find_bits(packed_bits_ptr, f_3_bits,4));
    printf("%s\t\t%d\n", "Gear_pos", gear);

    key = (find_bits(packed_bits_ptr, f_2_bits,2));
    printf("%s\t\t\t%d\n", "Key_pos", key);

    break_1 = (find_bits(packed_bits_ptr, f_bit,1));
    printf("%s\t\t\t%d\n", "Break_1", break_1);

    rear_break = (find_bits(packed_bits_ptr, f_bit,0));
    printf("%s\t\t%d\n", "Rear_break", rear_break);

}


// adopted from https://www.geeksforgeeks.org/program-for-hexadecimal-to-decimal/?ref=gcse
u_int8_t hexadecimalToDecimal(const char* hexadecimal_values)
{
    int base = 1;

    u_int8_t dec_val = 0;

    for (int i = 1 ; i >= 0; i--) {

        if (hexadecimal_values[i] >= '0' && hexadecimal_values[i] <= '9') {

            dec_val = dec_val + ((int)hexadecimal_values[i] - 48) * base;

            base = base * 16;
        }

        else if (hexadecimal_values[i] >= 'A' && hexadecimal_values[i] <= 'F') {
            dec_val = dec_val + ((int)hexadecimal_values[i] - 55) * base;

            base = base * 16;
        }
    }

    return dec_val;
}