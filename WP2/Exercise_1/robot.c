
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

void turn(ROBOT *robot);
void move(ROBOT *robot);
int get_coordinates ( int x_or_y);
void get_instructions (ROBOT* rob_ptr);
int repeat(ROBOT* rob_ptr);
void print_direction (ROBOT* robot);

char instruction[50];

int main()
{

    // declare a new robot
    ROBOT my_robot;
    ROBOT *rob_ptr;

    rob_ptr = &my_robot;

    // start direction is always north
    my_robot.dir = N;

    repeat(rob_ptr);

    return 0;
}

void turn(ROBOT *robot)
{
    robot->dir++;
    if (robot->dir == 4){
        robot->dir = 0;
    }
}

void move(ROBOT *robot)
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


int repeat(ROBOT* rob_ptr)
{
    // Declared variable for the user input.
    char yn;

    do {
        rob_ptr->x_position = get_coordinates(0);

        rob_ptr->y_position = get_coordinates(1);

        printf("\nInitial position: \nX:%d, Y:%d, Direction:%d\n", rob_ptr->x_position, rob_ptr->y_position, rob_ptr->dir);

        get_instructions(rob_ptr);

        print_direction (rob_ptr);

        // Printing out a string to the console for user input.
        printf("Would you like to execute another command case (Y/N)? = ");

        // reset the robot settings
        rob_ptr->x_position = 0;
        rob_ptr->y_position = 0;
        rob_ptr->dir = 0;

    }while(scanf(" %c", &yn) == 1 && (yn == 'y' || yn == 'Y'));

    // Successful termination same as '#0'.
    return EXIT_SUCCESS;
}

int get_coordinates (int x_or_y)
{
    char numbers[3];
    u_int8_t coordinate = 0;
    int option = x_or_y;

        if (option == 0)
        {
            printf("%s", "Please enter the starting coordinate x = ");
        }
        else
        {
            printf("%s", "Please enter the starting coordinate y = ");
        }

        scanf("%s", numbers);

        u_int8_t length = strlen(numbers);

        if (!isalpha(numbers[0]) && !isalpha(numbers[1]) && length < 3){

            coordinate = strtol(numbers,NULL,10);

            if ( coordinate >= 0 && coordinate <= 99)
            {
                return coordinate;
            }
        }
        else
        {
            coordinate = 0;
            get_coordinates(option);
        }

    return coordinate;

}


void get_instructions (ROBOT* rob_ptr)
{
    printf("%s", "Please enter instructions for the robot ['m' for move forward, 't' for turning 90 degree clockwise] = ");

    scanf("%s", instruction);

    for (int i = 0; i < strlen(instruction); ++i)
    {
        if (instruction[i] == 't')
        {
            // handel the instructions
            turn(rob_ptr);
        }
        else if (instruction[i] == 'm')
        {
            move(rob_ptr);
        }
        else
        {
            printf("%s", "Error >>>> ");
            get_instructions (rob_ptr);
        }
    }

}

void print_direction (ROBOT* robot)
{
    printf("\nFinal position after command '%s': \nX:%d, Y:%d", instruction, robot->x_position,robot->y_position);
    if (robot->dir == 0)
    {
        printf("%s\n" , " Direction is North");
    }
    if (robot->dir == 1)
    {
        printf("%s\n" , " Direction is East");
    }
    if (robot->dir == 2)
    {
        printf("%s\n" , " Direction is South");
    }
    if (robot->dir == 3)
    {
        printf("%s\n" , " Direction is West");
    }
}