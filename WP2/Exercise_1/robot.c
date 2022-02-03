
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
u_int8_t get_coordinates ( u_int8_t x_or_y);
void get_instructions (ROBOT* rob_ptr);
int choice(ROBOT* rob_ptr);

char instruction[50];

int main()
{

    // declare a new robot
    ROBOT my_robot;
    ROBOT *rob_ptr;

    rob_ptr = &my_robot;

    // start direction is always north
    my_robot.dir = N;

    choice(rob_ptr);

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


int choice(ROBOT* rob_ptr)
{
    // Declared variable for the user input.
    char yn;

    do {
        rob_ptr->x_position = get_coordinates(0);

        rob_ptr->y_position = get_coordinates(1);

        printf("\nInitial position: \nX:%d, Y:%d, Direction:%d\n", rob_ptr->x_position, rob_ptr->y_position, rob_ptr->dir);

        get_instructions(rob_ptr);

        printf("\nFinal position after command '%s': \nX:%d, Y:%d, Direction:%d\n", instruction, rob_ptr->x_position,rob_ptr->y_position, rob_ptr->dir);

        // Printing out a string to the console for user input.
        printf("Would you like to execute another command case (Y/N)? = ");

    }while(scanf(" %c", &yn) == 1 && (yn == 'y' || yn == 'Y'));

    // Successful termination same as '#0'.
    return EXIT_SUCCESS;
}

u_int8_t get_coordinates (u_int8_t x_or_y)
{
    char numbers[3];
    u_int8_t coordinate;
    u_int8_t true_false = 0;

    do {
        if (x_or_y == 0)
        {
            printf("%s", "Please enter the starting coordinate x = ");
        }
        else
        {
            printf("%s", "Please enter the starting coordinate y = ");
        }

        scanf("%s", numbers);

        if (!isalpha(numbers[0]) && !isalpha(numbers[1])){
            coordinate = strtol(numbers,NULL,10);
            if ( coordinate >= 0 && coordinate <= 99)
            {
                true_false = 1;
            }
            else
            {
                true_false = 0;
            }
        }
    } while (true_false == 0);

    return coordinate;

}


void get_instructions (ROBOT* rob_ptr)
{
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
        else if (instruction[i] == 'm')
        {
            move(rob_ptr, instruction[i]);
        }
        else
        {
            //printf("%s", "Error >>>> Please enter instructions for the robot ['m' for move forward, 't' for turning 90 degree clockwise] = ");
            get_instructions (rob_ptr);
        }
    }

}