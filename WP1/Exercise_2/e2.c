// (C) Bardha -> Group: 23 (2022)
// Work package 1
// Exercise 2
// Submission code: ------

/*------------------------------------------------------------
References:
    - C programming (course literature)
--------------------------------------------------------------*/

/*------------------------------------------------------------
EXERCISE 2
The system encrypts messages that are inputted by the user
 via console. To do so, it requires as input the message as well
 as the encryption key (i.e. the shift step). 
--------------------------------------------------------------*/
#include<stdio.h>

int main()
{
    /*global variables
     message- user inputted text, to be encrypted
     ch message characters
     shift- set to shift by 13 positions in the ASCII code, as predefined by assignment
    */
    char message[100]; //allocate space for a message of 100 characters
    char ch;
    int i;
    int shift;

    do{
        printf("Enter the message you want to encrypt: \n");
        //get message from user
        //scanf("%s", &message)
        fgets (message, 100, stdin);

        //get encryption key from the user
        printf("Enter the encryption key (shift): \n");
        scanf("%d", &shift);

        /*read through each character in message
          for each of them provide a new encrypted value
        */
        for(i = 0; message[i] != '\0'; i++){
            ch = message[i];
            if(ch >= 'A' && ch <= 'Z'){
                ch = ch - 'A';
                ch = (ch + shift) % 26 + 'A'; //bound encryption to alphabet (exclude -)
                //give each of the characters a new value which will be ch+13
                message[i] = ch;
            }
                //include lowercase letters
            else if (ch >= 'a' && ch <= 'z'){//
                ch = ch - 'a';
                ch = (ch + shift) % 26 + 'a';
                message[i] = ch;
            }
            else if (ch==' '){
                message[i]=' ';
            }
        }
        printf("Your encrypted message is: %s \n", message, "\n");
    } while(ch!=EOF);

    return 0;
}