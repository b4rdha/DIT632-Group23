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
    do
    {
        printf("\n Please select one of the following options: \n");
        printf("1 Create a new and delete the old file.\n");
        printf("2 Add a new person to the file.\n");
        printf("3 Search for a person in the file.\n");
        printf("4 Print out all in the file.\n");
        printf("5 Exit the program.\n");

        scanf(" %d", &option);

        if(option == 1)
        {
                // create a new and delete the old file
                //open file
                if((fileptr=fopen("Database.dat","wb"))==NULL)
                {
                    printf("\n Can not create the file");
                    exit(1);
                }

                PERSON dummyPerson = {.firstname="John", .famname="Doe", .pers_number="1234567898765"};

                fwrite(&dummyPerson,sizeof(PERSON),1,fileptr);

                fclose(fileptr);

                //write dummy record PERSON 
                //Close 
        }
        else if(option == 2)
        {
                // Add a new person to the file.
                PERSON newPerson = {};

                printf("Write first name: ");
                scanf("%s", newPerson.firstname);
                printf("\n");

                printf("Write last name: ");
                scanf("%s", newPerson.famname);
                printf("\n");

                printf("Write personal number: ");
                scanf("%s", newPerson.pers_number);
                printf("\n");

                printf("%s %s numri personal: %s \n", newPerson.firstname, newPerson.famname, newPerson.pers_number);

                fileptr = fopen("database.dat", "ab");
                
                fwrite(&newPerson,sizeof(PERSON),1,fileptr);

                fclose(fileptr); 
        }
        else if(option == 3) 
        {
                char searchTerm[20]; 
                printf("Enter the name or lastname you want to search for:");
                scanf("%20s", &searchTerm);

                if((fileptr=fopen("Database.dat","rb"))==NULL)
                {
                    printf("\n File could not be accessed");
                    exit(1);
                }
                else
                {
                    PERSON temp;
                    while((fread(&temp,sizeof(PERSON),1,fileptr)==1))
                    {
                        if ((strcmp(temp.firstname,searchTerm) == 0) || strcmp(temp.famname,searchTerm) == 0)
                        {
                            printf("Name: %s Lastname: %s  Personal Number: %s\n", temp.firstname,temp.famname,temp.pers_number);
                        }
                    }
                }
                fclose(fileptr);
        }
        else if(option == 4)
        {
                if((fileptr=fopen("Database.dat","rb"))==NULL)
                {
                    printf("\n File could not be accessed");
                    exit(1);
                }
                else
                {
                    PERSON temp;
                    while((fread(&temp,sizeof(PERSON),1,fileptr)==1))
                    {
                        printf("Name: %s Lastname: %s  Personal Number: %s\n", temp.firstname,temp.famname,temp.pers_number);
                    }
                }
                fclose(fileptr);
        }
        else if(option == 5)
        {
            return 0;
        }

    } while (1);

    return (0);
}

