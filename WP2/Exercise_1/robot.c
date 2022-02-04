// (C) Bassam, Ediz -> Group: 23 (2022)
// Work package 2
// Exercise 1
// Submission code: 101zX

/*------------------------------------------------------------------------------
References:
    - C programming (course literature)
-------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 Controlling the robot movements through x & y axelns followed by determining 
 current directions "m" for move & "t" for turn instructions.
 NOTE: the exercise is rasking that the user shall enter the initial coordinates for the robot between 0 and 99
 but doesn't mention that the robot can move into negative values of x and y coordinates. 
 therefore the proram is designed to let the robot move in the negative x and y coordinate values.
 This could be edited to constraint the robot to just move in positive values for x and y coordinates 
 by adding an if (x or y = 0) {`don't update the coordinates} in method "void move()".
-------------------------------------------------------------------------------*/

// Used librarie headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Enum for the robot directions to be used later in the robot struct.
enum DIRECTION
{
    N, // north
    O, //east
    S, // south
    W  //west
};

// A struct to present the robot object and it's properities
typedef struct
{
    int x_position;         // the robot x coordinate
    int y_position;         // the robot y coordinate
    enum DIRECTION dir;     // the robot direction
} ROBOT; // the type name to be used to create a new robot

// Function declarations
void move(ROBOT *robot); // Funtion to move the robot
void turn(ROBOT *robot); // Function to turn the robot.  
int repeat(ROBOT* rob_ptr); // Funtion to give user a chance to continue the execution of instructions.
int get_coordinates ( int x_or_y); // Function to recieve the coordinates inputs.
void get_instructions (ROBOT* rob_ptr); // Function to receive the instructions input
void print_direction (ROBOT* robot); // Funtion to print final positions.

// Global instruction array
char instruction[50];

int main()
{

    // declare a new robot
    ROBOT my_robot;
    ROBOT *rob_ptr;

    rob_ptr = &my_robot; // Pointer is pointing robot.
    my_robot.dir = N; // start direction is always north

    repeat(rob_ptr); // Function call to continue the game.

    return 0; // Successfull termination of main.
}

// Function to turn the robot. 
void turn(ROBOT *robot)
{
    robot->dir++; // For every turn increment the direction by one
    if (robot->dir == 4){  // Direction is out of range is always set to North. 
        robot->dir = 0; // Direction is set to north.
    }
}

// Funtion to move the robot
void move(ROBOT *robot)
{
    // Statement conditions to determine the right direction
    if (robot->dir == 0) // if direction is 0 (north), increment y-axeln
    {
        robot->y_position++; // y-axeln incremented 
    }
    else if (robot->dir == 1) // if direction is 1 (east), increment x-axeln
    {
        robot->x_position++; // x-axeln incremented
    }
    else if (robot->dir == 2) // if direction is 2 (south), decrement y-axeln
    {
        robot->y_position--; // y-axeln decremented
    }
    else if (robot->dir == 3) // if direction is 3 (west), decrement y-axeln
    {
        robot->x_position--; // x-axeln decremented
    }
}

// Funtion to give user a chance to continue the execution of instructions.
int repeat(ROBOT* rob_ptr)
{
    char yn; // Declared variable for the yes or no input.

    do {
        rob_ptr->x_position = get_coordinates(0); // Received coordinates assigned to x_position

        rob_ptr->y_position = get_coordinates(1); // Received coordinates assigned to x_position

        printf("\nInitial position: \nX:%d, Y:%d, Direction:%d\n", rob_ptr->x_position, rob_ptr->y_position, rob_ptr->dir); // Printing a string to the console about starting positions

        get_instructions(rob_ptr); // Function call to receive move and turn instructions from user.

        print_direction (rob_ptr); // Function call to print the final position of the robot

        printf("Would you like to execute another command case (Y/N)? = "); // Printing out a string to the console for user input.

        // reset the robot settings
        rob_ptr->x_position = 0; // setes to  the x to the origo
        rob_ptr->y_position = 0; // set the y to the origo
        rob_ptr->dir = 0; // set the direction to the origo

    }while(scanf(" %c", &yn) == 1 && (yn == 'y' || yn == 'Y')); // The condition to continue execution of instructions.

    // Successful termination same as '#0'.
    return EXIT_SUCCESS;
}

// Function to recieve the coordinates inputs.
int get_coordinates (int x_or_y)
{
    char numbers[3]; // User coordinates for x & Y-axeln
    u_int8_t coordinate = 0; // 
    int option = x_or_y; // User choice to continue to execution assigned to option varibable through x_or_y

        // To receive user inputs for coordinates seperately for x and y
        if (option == 0)
        {
            printf("%s", "Please enter the starting coordinate x = "); // Printing a string to the console for user to receive x-coordinates.
        }
        else
        {
            printf("%s", "Please enter the starting coordinate y = "); // Printing a string to the console for user to receive y-coordinates.
        }

        scanf("%s", numbers); // To receive the input

        u_int8_t length = strlen(numbers); // Function to calculate the lenght is assigned to lenght identifier.

        // Nested statements to to keep the inut in certain interval
        if (!isalpha(numbers[0]) && !isalpha(numbers[1]) && length < 3){

            coordinate = strtol(numbers,NULL,10); // Function to convert long integer

            // corrdinates interval 
            if ( coordinate >= 0 && coordinate <= 99)
            {
                return coordinate; // Return coordinates if input is within the interval.
            }
        }
        else
        {
            coordinate = 0; // Otherwise reset 
            get_coordinates(option); // Function call to start over.
        }

    return coordinate; // Return coordinates

}

// Function to receive the instructions input
void get_instructions (ROBOT* rob_ptr)
{
    // User message for instructions
    printf("%s", "Please enter instructions for the robot ['m' for move forward, 't' for turning 90 degree clockwise] = ");

    // scan the user instruction input
    scanf("%s", instruction); 

    // loop an check the user input for each char in the instruction
    for (int i = 0; i < strlen(instruction); ++i)
    {
        // if char is t 
        if (instruction[i] == 't')
        {
            // handel the instructions turning instruction by calling function turn();
            turn(rob_ptr);
        }¨
        // if the char is m
        else if (instruction[i] == 'm')
        {
            // handle the instrcution moving by calling mfunction move();
            move(rob_ptr);
        }¨
        //if none of these leters then print and error message and ask the user to enter valid instructions
        else
        {
            printf("%s", "Error >>>> ");
            // start the process over
            get_instructions (rob_ptr);
        }
    }
}

// Funtion to print final positions.
// takes tobot pointer as a parameter to use the latest setting for the robot
void print_direction (ROBOT* robot)
{
    // print out the robot's final x and y positions. 
    printf("\nFinal position after command '%s': \nX:%d, Y:%d", instruction, robot->x_position,robot->y_position);

    // check what is the direction value for the robot. 
    if (robot->dir == 0)
    {
        // if 0 then it's North
        printf("%s\n" , " Direction is North");
    }
    if (robot->dir == 1)
    {
        // if 1 then it's East
        printf("%s\n" , " Direction is East");
    }
    if (robot->dir == 2)
    {
        // if it's 2 then it's South
        printf("%s\n" , " Direction is South");
    }
    if (robot->dir == 3)
    {
        // if it's 3 then it's West
        printf("%s\n" , " Direction is West");
    }
}