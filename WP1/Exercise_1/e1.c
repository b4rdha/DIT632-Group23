#include <stdio.h>

int main() {
    char joke_1[]="If being ugly was a crime u would get a life sentence.";
    char joke_2[]="Some people think prison is one word…but to robbers it’s a whole sentence.";
    char joke_3[]="Is Google a girl or a boy? Obviously a Girl, because it won’t let you finish a sentence without making a suggestion";
    char joke_4[]="My doctor said I only have 1 year to live, so I killed him. Got sentenced to life in prison, problem solved!";
    char joke_5[]="Why did the police play baseball ? Why? He wanted to play catch.";
    int input;

    // Add do while to run the program until number is 1<n<5
    do {
        printf("%s\n","Please enter a number between 1 and 5");
        scanf("%d\n", &input);
        switch (input) {
            case 1: printf("%s\n",joke_1);
                break;
            case 2: printf("%s\n",joke_2);
                break;
            case 3: printf("%s\n",joke_3);
                break;
            case 4: printf("%s\n",joke_4);
                break;
            case 5: printf("%s\n",joke_5);
                break;
            default:printf("%s\n","The number you have entered does not fall between 1 and 5");
        }

    } while( );
    //To DO: Add switch case for checking input nr




    return 0;
}
