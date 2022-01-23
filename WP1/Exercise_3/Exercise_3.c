#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

#define EXIT_SUCCESS 0

/*------------------------------------------------------------

Author: Ediz

References:
    - C programming (course literature)
    - https://www.javatpoint.com/random-function-in-c
    - https://www.programiz.com/c-programming/c-input-output#:~:text=In%20C%20programming%2C%20scanf(),standard%20input%20such%20as%20keyboards
    - https://www.techonthenet.com/c_language/standard_library_functions/stdlib_h/exit.php
    - https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/


Exercise_3: GUESS THE NUMBER GAME

--------------------------------------------------------------*/

// void main()
// {
//     int guessTheNumber();
//     char yn;
//     printf("Your round is finished! Would you like to start over? [Y/N] = ");
//     scanf("%c", &yn);
//     if (strcmp(&yn, 0) == 'y' || strcmp(&yn, 0) == 'Y'){
//         int guessTheNumber();
//     }
//     else
//     {
//     }
// }

int main()
{

    printf("\n---------------------------------------------------------------");
    printf("\n\tWelcome to the guess the number game! Ready!\n");
    printf("Thinking of a number between 1 to 100! Try to guess the number!\n");
    printf("---------------------------------------------------------------\n");

    srand(time(0));
    int randomNumber = rand() % 100 + 1; // used rand() function to get the random number between 1 to 100.
    printf("%s%d", "The random number is = ", randomNumber);
    int userNumber, guess;

    do
    {
        printf("\nType your number = ");
        scanf("%d", &userNumber);
        guess++;


        if (userNumber <= randomNumber)
        {
            printf("Your number is low. Guess again!");
        }else if (userNumber >= randomNumber)
        {
            printf("Your number is high. Guess again!");
        }else if (userNumber <= randomNumber && guess == 3)
        {
            printf("Your number is low and 3 guesses left in your tab!");
        }else if (userNumber >= randomNumber && guess == 3)
        {
            printf("Your number is high and 3 guesses left in your tab!");
        }else
        {
            printf("CONGRATULATIONS! You have guessed the number. Guessed at %d times.", &guess);
            exit(EXIT_SUCCESS);  
        }
        
    } while (userNumber != randomNumber || guess != 9);

    return 0;
}
