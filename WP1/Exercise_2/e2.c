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
    int shift=13;

    do{
        printf("Enter the message you want to encrypt: ");
        //get message from user
        scanf("%s", &message);

        /*read through each character in message
          for each of them provide a new encrypted value
        */

        for(i = 0; message[i] != '\0'; i++){
            ch = message[i];
            if(ch >= 'A' && ch <= 'Z'){
                ch = ch - 'A';
                ch = (ch + shift) % 26 + 'A'; //give each of the characters a new value which will be ch+13
                message[i] = ch;
            }
                //include lowercase letters
            else if (ch >= 'a' && ch <= 'z'){//
                ch = ch - 'a';
                ch = (ch + shift) % 26 + 'a';
                message[i] = ch;
            }
            else{
                return -1;
            }
        }
        printf("Your encrypted message is: %s \n", message, "\n");
    } while(ch!=EOF);

    return 0;
}