// (C) Ediz,         ,        -> Group: 23 (2022)
// Work package 1
// Exercise 5
// Submission code: ------

/*------------------------------------------------------------
References:

/*------------------------------------------------------------
Exercise 5

The system.........bla bla

--------------------------------------------------------------*/

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
    // int i, j, count;
    // int visited = -1;
    // int size = tab;

    // for (i = 0; i < tab; i++)
    // {
    //     count = 1;
    //     for (j = i + 1; j < tab; j++)
    //     {
    //         if (tab[i] == tab[j])
    //         {
    //             count++;
    //             freq[j] = visited;
    //         }
    //     }

    //     if (freq[i] != visited)
    //     {
    //         freq[i] = count;
    //     }
    // }

    // printf("\nThe frequency of all elements of array = \n");
    // for (int i = 0; i < tab; i++)
    // {
    //     if (freq[i] != visited)
    //     {
    //         printf("%d occurs %d times\n", tab[i], freq[i]);
    //     }
    // }

    // return 0;

    int arr[10] = {3, 3, 4, 1, 1, 3, 3, 4, 0, 0};

    int c[6];

    int i;
    int *ptr;
    ptr = arr;

    for (i = 0; i < 10; i++)
    {
        // (arr + i) = &freq[p]++;
        // freq[*ptr];
        // printf("%d-%d-%d\n", *ptr, freq[tab[i]], freq[*ptr++]);
        ptr++;

        if (*ptr == 0)
        {
            arr[0]++;
        }
        else if (*ptr == 1)
        {
            arr[1]++;
        }
        else if (*ptr == 2)
        {
            arr[2]++;
        }
        else if (*ptr == 3)
        {
            arr[3]++;
        }
        else if (*ptr == 4)
        {
            arr[4]++;
        }
        else if (*ptr == 5)
        {
            arr[5]++;
        }
        else if (*ptr == 6)
        {
            arr[6]++;
        }
        else if (*ptr == 7)
        {
            arr[7]++;
        }
        else if (*ptr == 8)
        {
            arr[8]++;
        }
        else if (*ptr == 9)
        {
            arr[9]++;
        }
        else if (*ptr == 10)
        {
            arr[10]++;
        }
        else if (*ptr == 11)
        {
            arr[11]++;
        }
        else if (*ptr == 12)
        {
            arr[12]++;
        }
        else if (*ptr == 13)
        {
            arr[13]++;
        }
        else if (*ptr == 14)
        {
            arr[14]++;
        }
        else if (*ptr == 15)
        {
            arr[15]++;
        }
        else if (*ptr == 16)
        {
            arr[16]++;
        }
        else if (*ptr == 17)
        {
            arr[17]++;
        }
        else if (*ptr == 18)
        {
            arr[18]++;
        }
        else if (*ptr == 19)
        {
            arr[19]++;
        }else{

        }

    }
    for ( i = 0; i < MAXNUMBER; i++)
    {
        printf("%d-%d\n", i, arr[i]);
    }
    

    // int i, j;
    // int table[MAX], n;
    // int frequency[MAXNUMBER];

    // // Dividing int data into bins
    // for (i = 0; i < tab; i++)
    // {
    //     for (j = 1; j <= freq; j++)
    //     {

    //         int bin_max = j / *freq;
    //         if (frequency[i] <= bin_max)
    //         {
    //             table[j]++;
    //             break;
    //         }
    //     }
    // }
}

/*int draw_histogram(int *freq)
{
    int count;
    int i, j;
    int table[MAX];
    int frequency[MAXNUMBER];
    // Plotting histogram
    printf("\nHistogram of int data\n");

    for (i = 1; i <= freq; i++)
    {
        count = table[i];
        printf("%d |", i - 1);
        for (j = 0; j < count; j++)
        {
            printf("%c", (char)88);
        }
        printf("\n");
    }
    return *freq;
} */

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