// (C) Ediz -> Group: 23 (2022)
// Work package 1
// Exercise 3
// Submission code: ------

/*------------------------------------------------------------
References:
    - C programming (course literature)
    - https://www.javatpoint.com/random-function-in-c
    - https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
    - https://www.tutorialspoint.com/c_standard_library/c_function_getchar.htm
--------------------------------------------------------------*/

/*------------------------------------------------------------
GUESS THE NUMBER GAME

The system produces a different random number in every execution between 1 to 100.
The player is given 5 chances to guess the number right. In case of failure, player can
start over a new game to be able to play until to be A WINNER.
--------------------------------------------------------------*/

// Used libraries headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declared function
int choice();

// Definition of Macros
#define MIN 1
#define MAX 100
#define EXIT_SUCCESS 0

/*
A function whether the game is going to continue.
User has been given chance to start over the game.
*/
int choice()
{
    // Declared variable for the user input.
    char yn;

    // Printing out a string to the console for user input.
    printf("\nYou could not guess the number this time. Your round is finished! Would you like to start a new game? [Y/N] = ");

    // Comparison of char with case-sensitiveness through scanf("format", argument) function to read the input data from the console,
    if (scanf(" %c", &yn) == 1 && (yn == 'y' || yn == 'Y'))
    {
        // Re-calling the main function
        main();
    }

    // otherwise end the program.
    else
    {
        // Printing out a string to the console for farewell.
        printf("\nGood game. Thank you for participating!\n");
    }

    // Succesfull termination same as '#0'.
    return EXIT_SUCCESS;
}

// Function that evaluates whether the user input is an integer.
int getint()
{
    int integer; // To keep integer values
    char string[10]; // To keep char values

    // Printing out a string to the console for user input.
    printf("\nType your number = ");

    // scanf("format", argument) function to read the input data from the console.
    while (scanf("%d", &integer) != 1)
    {
        // Keep read characters in char array up to 10
        string[10] = getchar(); // getchar() reads characters from input and returns them.

        // Printing out a string to the console for user alert
        printf("You have not typed an integer! ", string);

        // Filling the buffer until the next new line
        while (getchar() != '\n');

        // Printing out a string to the console for user input.
        printf("\nType your number = ");
    }

    // Return the correct value to main
    return integer;
}

// The main function for the execution of the system.
int main()
{
    // Declared variables.
    int randomNumber;      // Variable for random number
    int userNumber, guess; // Variable for user inputs
    int round = 5;         // Variable for the number of rounds.
    char string;

    // Printing out a string to the console for welcoming the users.
    printf("\n---------------------------------------------------------------");
    printf("\n\tWelcome to the guess the number game! Ready!\n");
    // Printing out a string to the console for the main game rule.
    printf("Thinking of a number between 1 to 100! Try to guess the number!\n");
    printf("---------------------------------------------------------------\n");

    /* time(value) returns a time value every time srand() function call which sets
    the starting point to produce continous random numbers in each execution.
    srand() should be only seeded once prior to rand() or execution of the program.*/
    srand(time(0));

    // declared variable for random number and assigning the rand() with range of two integers.
    randomNumber = rand() % MAX + MIN; // used rand() function to get the random number between 1 to 100.

    /*
    // Printing out (if needed) a string of random number to the console.
    printf("%s%d", "\nThe random number is = ", randomNumber);
    */

    // Loop for the continous guessing until one of the condtions met.
    do
    {
        // Store the user input which is returned from getint() function.
        userNumber = getint();

        // Increase the number of guess by one in each try.
        guess++;

        // Increase the number of round count by one in each try.
        round--;

        // First check of nested statements whether the user has any right left to continue the game,
        if (round > 0 && round < 5)
        {
            // Second check of nested statements whether to see user input is smaller than the random number,
            if (userNumber < randomNumber)
            {
                // Third check of nested statement whether to see user input is within the range,
                if (userNumber >= MIN)
                {
                    // Printing out a string to the console to inform the user.
                    printf("Your guess[#%d] is too low. Guess again! [%d Round left]\n", guess, round);
                }

                // otherwise printing out a string to the console for user warning and decrease number of guesses and rounds.
                else
                {
                    // Printing out a string to the console to inform the user.
                    printf("You have typed a number out of range! Please try again [1 to 100]!\n");

                    // Decrease the number of guesses by one in each time when the value is out of range.
                    guess--;

                    // Decrease the number of rounds by one in each time when the value is out of range.
                    round++;
                }
            }

            // continuous check of nested statements whether the input is higher than the random number,
            else if (userNumber > randomNumber)
            {
                // Third check of nested statement whether to see user input is within the range,
                if (userNumber <= MAX)
                {
                    // Printing out a string to the console to inform the user.
                    printf("Your guess[#%d] is too high. Guess again! [%d Round left]\n", guess, round);
                }

                // otherwise printing out a string to the console for user warning and decrease number of guesses and rounds.
                else
                {
                    // Printing out a string to the console to inform the user.
                    printf("You have typed a number out of range! Please try again [1 to 100]!\n");

                    // Decrease the number of guesses by one in each time when the value is ou of range.
                    guess--;

                    // Decrease the number of rounds by one in each time when the value is ou of range.
                    round++;
                }
            }

            // continuous check of nested statements whether the input is equal to the random number,
            else if (userNumber == randomNumber)
            {
                // Printing out a string to the console to inform the user.
                printf("\nCONGRATULATIONS! You have guessed %d times. Game Over!", guess);

                // Succesfull termination same as '#0'.
                return EXIT_SUCCESS;
            }

            // otherwise print a string to the console to inform the user.
            else
            {
                // Printing out a string to the console to inform the user.
                printf("You have typed a number out of range! Please try again [1 to 100]!");
            }
        }

        // otherwise redirect to function call to restart the game.
        else
        {

            // Calling the function to give the user another choice.
            choice();
        }

        // Loop condition until the random number guessed within given number of rounds.
    } while (userNumber != randomNumber && (round <= 5 && round > 0));

    // Succesfull termination same as '#0'.
    return EXIT_SUCCESS;
}
