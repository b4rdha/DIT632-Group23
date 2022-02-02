
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum DIRECTION {N,O,S,W};

typedef struct {
    int x_position;
    int y_position;
    enum DIRECTION dir;
} ROBOT;

void turn (ROBOT* robot, char c);
void move (ROBOT* robot, char c);


char instruction [50];


int main ()
{

    // declare a new robot
    ROBOT my_robot;
    ROBOT* rob_ptr;

    rob_ptr = &my_robot;

    // start direction is always north
    my_robot.dir = N;

    int x = 0;
    int y = 0;

    // TODO: we need to check the number is a number not a sign or int
    // TODO: The number must be between 0 and 99

    printf("%s", "Please enter the starting coordinate x");
    scanf("%d", &x); // parse to int 0-99
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

    printf("%s", "Please enter the starting coordinate y");
    scanf("%d", &rob_ptr->y_position); // parse to int 0-99

    printf("%d %d %d\n", my_robot.x_position, my_robot.y_position, my_robot.dir);


    // TODO: we need to check the string comtains just chars and not sign or ints
    // TODO: The chars must be handled so that they work with uppercase or lowercase.

    printf("%s", "Please enter instructions for the robot");

    scanf("%s", instruction);


    for (int i = 0; i < 50; ++i) {

        // TODO write info to the user that they can exit the program if the enter this sign '/'
        if(instruction[i] != '/')
        {
            // handel the instructions
            turn (rob_ptr, instruction[i]);
            move(rob_ptr, instruction[i]);
        }
        else
        {
            // so if the char '/' is seen then exit the program
            return 0;
        }
    }

    printf("%d %d %d\n", my_robot.x_position, my_robot.y_position, my_robot.dir);
    return 0;
}

void turn (ROBOT* robot, char c)
    //TODO: change this to be dynamically incremented
    if (c == 't' && robot->dir == 0 )
    {
        robot->dir = 1; //robot->dir+1 % 3;  /// 1 % 3 = 1
    }
    else if (c == 't' && robot->dir == 1 )
    {
        robot->dir = 2; //robot->dir+1 % 3;  /// 1 % 3 = 1
    }
    else if (c == 't' && robot->dir == 2 )
    {
        robot->dir = 3; //robot->dir+1 % 3;  /// 1 % 3 = 1
    }
    else if (c == 't' && robot->dir == 3 )
    {
        robot->dir = 0; //robot->dir+1 % 3;  /// 1 % 3 = 1
    }
}

void move (ROBOT* robot, char c)
{
    if (c == 'm' && robot->dir == 0)
    {
        robot->y_position++;
    }
    else if (c == 'm' && robot->dir == 1)
    {
        robot->x_position++;
    }
    else if (c == 'm' && robot->dir == 2)
    {
        robot->y_position--;
    }
    else if (c == 'm' && robot->dir == 3)
    {
        robot->x_position--;
    }
}


