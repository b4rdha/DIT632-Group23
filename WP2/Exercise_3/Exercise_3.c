// (C) Bardha -> Group: 23 (2022)
// Work package 2
// Exercise 3
// Submission code: ------

/*------------------------------------------------------------
References:
    - C programming (course literature)
--------------------------------------------------------------*/

/*------------------------------------------------------------
EXERCISE 3
The system allows uesers to create, read and update a file. 
The file can also be searched by term. 
--------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// -----typedefs -------
typedef struct
{
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;


int main(void)
{
    PERSON ppost;
    FILE *fileptr;

    int option;
    //Provide menu with options
    do
    {
        printf("\n Please select one of the following options: \n");
        printf("1 Create a new and delete the old file.\n");
        printf("2 Add a new person to the file.\n");
        printf("3 Search for a person in the file.\n");
        printf("4 Print out all in the file.\n");
        printf("5 Exit the program.\n");

        scanf(" %d", &option);

        if(option == 1) //go through user choices 
        {
                // create a new and delete the old file
                // open file in binary write mode, if it doesn't exist, create it
                // checking if it can't be created 
                if((fileptr=fopen("Database.dat","wb"))==NULL)
                {
                    printf("\n Can not create the file");
                    exit(1);
                }
                //first dummy entry
                PERSON dummyPerson = {.firstname="John", .famname="Doe", .pers_number="1234567898765"};
                //populate, i.e write it in the specified file
                fwrite(&dummyPerson,sizeof(PERSON),1,fileptr);
                //close the process
                fclose(fileptr);

        }
        else if(option == 2) // Add a new person to the file.
        {
               
                PERSON newPerson = {};
                //allow user to enter new data through console
                printf("Write first name: ");
                scanf("%s", newPerson.firstname);
                printf("\n");

                printf("Write last name: ");
                scanf("%s", newPerson.famname);
                printf("\n");

                printf("Write personal number: ");
                scanf("%s", newPerson.pers_number);
                printf("\n");

                //show the newly added user
                printf("Name: %s  Lastname: %s Personal number: %s \n", newPerson.firstname, newPerson.famname, newPerson.pers_number);
                //append new user to the records file
                fileptr = fopen("database.dat", "ab");
        
                fwrite(&newPerson,sizeof(PERSON),1,fileptr);
                //close
                fclose(fileptr); 
        }
        else if(option == 3) //searching for a record
        {
                char searchTerm[20]; 
                //get search term from user via console
                printf("Enter the name or lastname you want to search for:");
                scanf("%20s", &searchTerm);
                
                //access the file
                if((fileptr=fopen("Database.dat","rb"))==NULL)
                {
                    printf("\n File could not be accessed");
                    exit(1);
                }
                else
                {   //check if the entered term matches any stored record and print it
                    PERSON temp;
                    while((fread(&temp,sizeof(PERSON),1,fileptr)==1))
                    {
                        if ((strcmp(temp.firstname,searchTerm) == 0) || strcmp(temp.famname,searchTerm) == 0)
                        {
                            printf("Name: %s Lastname: %s  Personal Number: %s\n", temp.firstname,temp.famname,temp.pers_number);
                        }
                        else
                        //show if search didn't match any record 
                        {
                            printf("The person is not found in our records ");
                        }
                    }
                }
                fclose(fileptr);
        }
        else if(option == 4) //Show all records 
        {       
                //access file
                if((fileptr=fopen("Database.dat","rb"))==NULL)
                {
                    printf("\n File could not be accessed");
                    exit(1);
                }
                else
                {
                    //print all records found in file
                    PERSON temp;
                    while((fread(&temp,sizeof(PERSON),1,fileptr)==1))
                    {
                        printf("Name: %s Lastname: %s  Personal Number: %s\n", temp.firstname,temp.famname,temp.pers_number);
                    }
                }
                fclose(fileptr);
        }
        else if(option == 5) //option to exit the program 
        {
            return 0;
        }

    } while (1);

    return (0);
}

