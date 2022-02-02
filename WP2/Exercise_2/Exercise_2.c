// (C) Ediz -> Group: 23 (2022)
// Work package 2
// Exercise 2
// Submission code: -----

/*------------------------------------------------------------
References:
    - C programming (course literature)
    - https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/

--------------------------------------------------------------*/

/*------------------------------------------------------------
Random number generator into Linked List


--------------------------------------------------------------*/

// Used librariy headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 5
#define initial_string "\nList of random numbers\n"
#define added_number 20
#define second_string "\nNumber %d added at the beginning of list\n"

// ##### typedefs ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations #####
REGTYPE *random_list(void);
REGTYPE *add_first(REGTYPE *temp, int data);
void printLinkedList(act_post);

//###### Main program #######
int main(int argc, char *argv[])
{
    int nr = 0;
    REGTYPE *act_post, *head = NULL;
    srand(time(0)); // Random seed

    head = random_list();
    act_post = head;
    printf(initial_string);
    printLinkedList(act_post);

    head = add_first(head, added_number);
    act_post = head;
    printf(second_string, added_number);
    printLinkedList(act_post);

    // --- Free the allocated memory ---
    while ((act_post = head) != NULL)
    {
        head = act_post->next;
        free(act_post);
    }
    return 0;
}
// ==== End of main ======================================

REGTYPE *random_list(void)
{
    int nr, i;
    REGTYPE *top, *old, *item;

    for (i = 0; i < MAX; i++)
    {
        top = (REGTYPE *)malloc(sizeof(REGTYPE));
        nr = rand() % 100;
        top->number = nr;
        top->prev = NULL;
        top->next = NULL;
        item = top;
    }
    for (i = 0; i < MAX; i++)
    {
        old = item;
        item = (REGTYPE *)malloc(sizeof(REGTYPE));
        nr = rand() % 100;
        item->number = nr;
        item->prev = old;
        item->next = NULL;
        old->next = item;
    }
    return (top);
}
//==========================================================

REGTYPE *add_first(REGTYPE *temp, int data)
{
    REGTYPE *add = malloc(sizeof(REGTYPE));
    add->number = data;
    add->next = temp;
    temp = add;
}

void printLinkedList(REGTYPE *act_post)
{
    REGTYPE *temp = act_post;

    while (temp != NULL)
    {
        printf("%d \n", temp->number);
        temp = temp->next;
    }
}