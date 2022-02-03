// (C) Ediz -> Group: 23 (2022)
// Work package 2
// Exercise 2
// Submission code: -----

/*------------------------------------------------------------------------------
References:
    - C programming (course literature)
    - https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/

-------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 - Random number generator into Linked List
 - Adding the new value in the front of the linked list.
-------------------------------------------------------------------------------*/

// Used librariy headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 5 // Determining the length of the Linked List
#define added_number 20 // Constant number to push to the front of the Linked list.

// ##### typedefs ####
typedef struct q
{
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Function declarations #####
REGTYPE *random_list(void); // Function to create random numbers from 0-100 as nodes.
REGTYPE *add_first(REGTYPE *temp, int data); // Function to insert a number as first node.
void printLinkedList(REGTYPE *act_post); // Function to print out the list before and after insertion.

//###### Main program #######
int main(int argc, char *argv[])
{
    // Variable declerations
    int nr = 0;
    REGTYPE *act_post, *head = NULL; // Declaration of the head and post positions of Linked list. 
    srand(time(0)); // Random seed

    head = random_list(); // Random list is assigned to the head.
    act_post = head; // Current head is assigned to act_post. 
    printf("%s", "\nList of random numbers\n"); // string heading for initial random numbers.
    printLinkedList(act_post); // printing out the list nodes.

    head = add_first(head, added_number); // assigning the new head by calling "add_first" function.
    act_post = head; // current head is assigned to act_post.
    printf("\nNumber %d added at the beginning of list\n", added_number); // string heading for random numbers after insertion.
    printLinkedList(act_post); // printing out the list nodes.

    // --- Free the allocated memory ---
    while ((act_post = head) != NULL)
    {
        head = act_post->next;
        free(act_post);
    }
    return 0;
}

// Function to create random numbers from 0-100 as nodes.
REGTYPE *random_list(void)
{
    // Variable declerations
    int nr, i; // "nr" for random numbers and "i" for iteration in the loop
    REGTYPE *top, *old, *item; // Decleration of "top" as first item and "old" as last item as nodes in LInked list and "item" as the new struct into linked list


    for (i = 0; i < MAX; i++) // Loop for iterating in Linked List.
    {
        top = (REGTYPE *)malloc(sizeof(REGTYPE)); // Allocating memory for "top" as the new struct.
        nr = rand() % 100; // Random number generating between 0-100. 
        top->number = nr; // Assigning the random numbers to number through top pointer
        top->prev = NULL; // prev is NULL as reference to the previous node.
        top->next = NULL; // next is NULL as reference to the next node.
        item = top; //top is assigned to item as the first node.
    }
    for (i = 1; i < MAX; i++) // Loop for iterating in Linked List.
    {
        old = item; // item is assigned to old as the last item 
        item = (REGTYPE *)malloc(sizeof(REGTYPE)); // Allocating memory for item as the new struct.
        nr = rand() % 100; // Random number generating between 0-100.
        item->number = nr; // Random numbers assigned to numbers through item
        old->next = item; // Assigned the new generated item to old as in last in linked list
        item->prev = old; // new generated item is assigned to old.
        item->next = NULL; // item-next is NULL as it is last item in the list
    }
    return (top); // return top to head in linked list
}

// Function to insert a number as first node.
REGTYPE *add_first(REGTYPE *temp, int data)
{
    REGTYPE *add = malloc(sizeof(REGTYPE)); // Allocate memory for insertion
    add->number = data; // Assigned data to newly added number
    add->next = temp; // Current temp with the new value in the linked list 
    temp = add; // New top of linked list

    return temp; // return temp to head in linked list
}

// Function to print out the list before and after insertion.
void printLinkedList(REGTYPE *act_post)
{
    // Loop to print all the nodes in the linked list
    while (act_post != NULL)
    {
        printf("%d \n", act_post->number); // Printing each current node in the linked list
        act_post = act_post->next; // Continue looping by assigning post to next in the linked list.
    }
}