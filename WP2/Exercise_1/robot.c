
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum DIRECTION
{
    N,
    O,
    S,
    W
};

typedef struct
{
    int x_position;
    int y_position;
    enum DIRECTION dir;
} ROBOT;

void turn(ROBOT *robot, char c);
void move(ROBOT *robot, char c);
int getint();
int choice();

char instruction[50];

int main()
{

    // declare a new robot
    ROBOT my_robot;
    ROBOT *rob_ptr;

    rob_ptr = &my_robot;

    // start direction is always north
    my_robot.dir = N;

    //    int x = 0;
    //    int y = 0;
    //
    //    // TODO: we need to check the number is a number not a sign or int -> DONE
    //    // TODO: The number must be between 0 and 99
    //
    printf("%s", "Please enter the starting coordinate x = ");
    rob_ptr->x_position = getint();

    //
    //    if (x < 0 || x > 99 || !isdigit(x))
    //    {
    //        // failure message
    //        printf("%s", "The x value must be between 0 and 99");
    //    }
    //    if ( y < 0 || y > 99 || !isdigit(x))
    //    {
    //        printf("%s", "The y value must be between 0 and 99");
    //    }

    printf("%s", "Please enter the starting coordinate y = ");
    rob_ptr->y_position = getint();
    printf("\nInitial position: \nX:%d, Y:%d, Direction:%d\n", my_robot.x_position, my_robot.y_position, my_robot.dir);

    // TODO: we need to check the string comtains just chars and not sign or ints
    // TODO: The chars must be handled so that they work with uppercase or lowercase.

    printf("%s", "Please enter instructions for the robot ['m' for move forward, 't' for turning 90 degree clockwise] = ");

    scanf("%s", instruction);

    for (int i = 0; i < strlen(instruction); ++i)
    {

        // TODO write info to the user that they can exit the program if the enter this sign '/'
        if (instruction[i] == 't')
        {
            // handel the instructions
            turn(rob_ptr, instruction[i]);
        }
        else
        {
            move(rob_ptr, instruction[i]);
            // so if the char '/' is seen then exit the program
            // return 0;
        }
    }

    printf("\nFinal position after command '%s': \nX:%d, Y:%d, Direction:%d\n", instruction, my_robot.x_position, my_robot.y_position, my_robot.dir);

    choice();

    return 0;
}

void turn(ROBOT *robot, char c)
{
    // TODO: change this to be dynamically incremented
    if (robot->dir == 0)
    {
        robot->dir = 1; // robot->dir+1 % 3;  /// 1 % 3 = 1
    }
    else if (robot->dir == 1)
    {
        robot->dir = 2; // robot->dir+1 % 3;  /// 1 % 3 = 1
    }
    else if (robot->dir == 2)
    {
        robot->dir = 3; // robot->dir+1 % 3;  /// 1 % 3 = 1
    }
    else if (robot->dir == 3)
    {
        robot->dir = 0; // robot->dir+1 % 3;  /// 1 % 3 = 1
    }
}

void move(ROBOT *robot, char c)
{
    if (robot->dir == 0)
    {
        robot->y_position++;
    }
    else if (robot->dir == 1)
    {
        robot->x_position++;
    }
    else if (robot->dir == 2)
    {
        robot->y_position--;
    }
    else if (robot->dir == 3)
    {
        robot->x_position--;
    }
}

// Function that evaluates whether the user input is an integer.
int getint()
{
    int integer;     // To keep integer values
    int string[10]; // To keep char values
    int index = 0;

    // scanf("format", argument) function to read the input data from the console.
    while (scanf("%d", &integer) != 1)
    {
        // Keep read characters in char array up to 10
        string[index] = getchar(); // getchar() reads characters from input and returns them.

        // Printing out a string to the console for user alert
        printf("You have not typed an integer! Please try again! = ", string);
        index++;
        // Filling the buffer until the next new line
        while (getchar() != '\n')
            ;
    }

    // Return the correct value to main
    return integer;
}

int choice()
{
    // Declared variable for the user input.
    char yn;

    // Printing out a string to the console for user input.
    printf("Would you like to execute another command case (Y/N)? = ");

    // Comparison of char with case-sensitiveness through scanf("format", argument) function to read the input data from the console,
    if (scanf(" %c", &yn) == 1 && (yn == 'y' || yn == 'Y'))
    {
        // Re-calling the main function
        main();
    }

    // otherwise, end the program.
    else
    {
        // Printing out a string to the console for farewell.
        printf("\n Exiting the program...\n");
    }

    // Successful termination same as '#0'.
    return EXIT_SUCCESS;
}