// (C) Ediz, Bassam, Bardha -> Group: 23 (2022)
// Work package 1
// Exercise 1
// Submission code: aB-5311

/*------------------------------------------------------------
References:
    - C programming (course literature)
--------------------------------------------------------------*/

/*------------------------------------------------------------
EXERCISE 1
The system produces prints out the different senteces due to user input within 1 to 5.
--------------------------------------------------------------*/

// Used libraries headers
#include <stdio.h>

// The main entry point for the program
int main()
{

    // Variable for the user input
    int input;

    // 5 char-sentences that will be printed based on input
    char joke_1[75] = "- What's the best way to throw a birthday party on Mars? \n You planet!";
    char joke_2[80] = "- Some people think prison is one word \nbut.. to robbers it's a whole sentence";
    char joke_3[60] = "- What's a really sad strawberry called? \n A blueberry.";
    char joke_4[110] = "- My doctor said I only have 1 year to live, so I killed him. Got sentenced to life in prison, problem solved!";
    char joke_5[70] = "- Why did the police play baseball? \n Why? \nHe wanted to play catch.";

    // Loop to print the sentences continiously within the interval 1 to 5 until any other number is typed to exit the program.
    do
    {

        // Printing a string to the console to get the input range
        printf("%s", "\nPlease enter a number between 1 and 5 = ");

        // scanf("format", argument) function to read the input data from the console
        scanf("%d", &input);

        // if-statement conditions to address the input to differantiate the sentences
        if (input == 1)
        {
            // Printing out a string to the console for the user
            printf("%s\n", joke_1);
        }
        // 2nd condition for sentence #2
        else if (input == 2)
        {
            // Printing out a string to the console for the user
            printf("%s\n", joke_2);
        }
        // 3nd condition for sentence #3
        else if (input == 3)
        {
            // Printing out a string to the console for the user
            printf("%s\n", joke_3);
        }
        // 4nd condition for sentence #4
        else if (input == 4)
        {
            // Printing out a string to the console for the user
            printf("%s\n", joke_4);
        }
        // 5nd condition for sentence #5
        else if (input == 5)
        {
            // Printing out a string to the console for the user
            printf("%s\n", joke_5);
        }
        // otherwise exit the program after printing out a string for the user 
        else
        {
            // Printing out a string to the console.
            printf("%s", "\nThe number you have entered does not fall between 1 and 5! \nExiting the program.");

            // In case of this condition exit the program
            break;
        }

        // condition to keep the interval between 1 to 5
    } while (input <= 5 && input >= 1);

    // Printing out a string to the console for the user.
    printf("%s", "\nThank you for participating!\n");

    // Succesful termination of the program.
    return 0;
}
