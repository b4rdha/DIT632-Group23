// (C) Ediz,         ,        -> Group: 23 (2022)
// Work package 1
// Exercise 5
// Submission code: ------

/*------------------------------------------------------------
References:

*------------------------------------------------------------
Exercise 5

The system.........bla bla

//--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100      // Defines the maximum number of the values in the table
#define MAXNUMBER 20 // Defines the maximum value of random numbers

// ------ Function declarations ----------
// This function generates a set of random numbers
// and fills the table *tab with these numbers
int create_random(int *tab);

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
int count_frequency(int *tab, int *freq);

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
int draw_histogram(int *freq);

int create_random(int *tab)
{
    int index = 0;
    srand(time(0));

    while (index < MAX)
    {
        int randomNumber = rand() % MAXNUMBER;
        tab[index] = randomNumber;
        index++;
    }
    return 0;
}

int count_frequency(int *tab, int *freq)
{

    //int c[6];

    // set the array to 0s to clean up
    for (int i = 0; i < MAXNUMBER; ++i) {
        freq[i] = 0;
        printf("%d " , freq[i]);
    }

    printf("\n%s" , "\n");

    int *ptr;
    ptr = tab;

    for (int i = 0; i < MAX; i++)
    {

        freq[*ptr % MAXNUMBER] ++;
        printf("%d ", *ptr);
        ptr++;

    }

    printf("\n%s\n" , "result");

    // print
    for ( int i = 0; i < MAXNUMBER; i++)
    {
        printf("%d-  \t%d\n", i, freq[i]);
    }


    return  0;
}


//
//int draw_histogram(int *freq)
//{
//    int count;
//    int i, j;
//    int table[MAX];
//    int frequency[MAXNUMBER];
//    // Plotting histogram
//    printf("\nHistogram of int data\n");
//
//    for (i = 1; i <= freq; i++)
//    {
//        count = table[i];
//        printf("%d |", i - 1);
//        for (j = 0; j < count; j++)
//        {
//            printf("%c", (char)88);
//        }
//        printf("\n");
//    }
//    return *freq;
//}

// ------ Function definitions ----------
// ------ Main --------------------------
// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main(void)
{

    int table[MAX], n;
    int frequency[MAXNUMBER];

    create_random(table);
    count_frequency(table, frequency);

    // for (int i = 0; i < MAXNUMBER; i++)
    // {
    //     printf("%d\n", frequency[i]);
    // }

    // printf("%d\n", sizeof(table) / sizeof(table[0]));

    /*     n = draw_histogram(MAXNUMBER);
        printf("%d", n); */

    return 0;
}