// (C) Ediz, Bassam, Bardha -> Group: 23 (2022)
// Work package 1
// Exercise 1
// Submission code: ------

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

        // switch-case to address the input
        switch (input)
        {

        // each case to differantiate the sentences
        case 1:
            printf("%s\n", joke_1);

            // exit after the specific sentence for the case printed out
            break;
        case 2:
            printf("%s\n", joke_2); // as in case-1's comment
            break;                  // as in case-1's comment
        case 3:
            printf("%s\n", joke_3); // as in case-1's comment
            break;                  // as in case-1's comment
        case 4:
            printf("%s\n", joke_4); // as in case-1's comment
            break;                  // as in case-1's comment
        case 5:
            printf("%s\n", joke_5); // as in case-1's comment
            break;                  // as in case-1's comment

        // Ptinting out a string to the console for default case in case the user type out of range (1 to 5).
        default:
            printf("%s", "\nThe number you have entered does not fall between 1 and 5! \nExiting the program.");
        }

        // condition to keep the interval between 1 to 5
    } while (input <= 5 && input >= 1);

    // Printing out a string to the console for the user.
    printf("%s", "\nThank you for participating!\n");

    // Succesful termination of the program.
    return 0;
}
