#include <stdio.h>

int main() {
    //Define 5 char- sentences that will be printed based on input
    char joke_1[]="What's the best way to throw a birthday party on Mars? \n You planet!";
    char joke_2[]="Some people think prison is one word…but to robbers it’s a whole sentence";
    char joke_3[]="What's a really sad strawberry called? \n A blueberry.";
    char joke_4[]="My doctor said I only have 1 year to live, so I killed him. Got sentenced to life in prison, problem solved!";
    char joke_5[]="Why did the police play baseball ? \n Why? He wanted to play catch.";
    int input;

    // Add do while to run the program until number is 1<n<5
    do {
        printf("%s\n","Please enter a number between 1 and 5");
        scanf("%d", &input);
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

    } while(input<5);

    return 0;
}
