#include <stdio.h>

//function prototypes:

char menusystem(void);
char rotnEncryption(char* message);
char rotnDecryption(char* rotnmessage);

int main()
{
    menusystem();
    
//Task 1: Encryption with a rotation cipher given plain text and key
    
    char message[1024]; //the message entered by the user
    
    printf("Enter a message to encrypt (in capital letters):\n");//the console tells the user to input a message
    scanf("%[^\n]", message);//the user inputs a message
    
    rotnEncryption(message);//the message is encrypted by calling the function rotnEncryption

//Task 2: Decryption with a rotation cipher given cipher text and key

    char rotnmessage[1024]; //the encrypted message entered by the user
    
    printf("Enter an encrypted message to decrypt (in capital letters):\n");//the console tells the user to input an encrypted message
    scanf("%[^\n]", rotnmessage);//the user inputs the encrypted message
    
    rotnDecryption(rotnmessage);//the message is decrypted by calling the function rotnDecryption

}

//Function definitions:

    char menusystem(void)
{
    int taskNumber;
    
    printf("Please select a task (1, 3, 4, 5, 6 or 7): \n"); // Asks user which task they would like performed
    printf("(1) Encryption with a rotation cipher given plain text and key\n");
    printf("(2) Decryption with a rotation cipher given cipher text and key\n");
    printf("(3) Encryption with a substitution ciper given plain text and key\n");
    printf("(4) Decryption with a substitution cipher given cipher text and key\n");
    printf("(5) Decryption of a previously unseen cipher text encrypted with a rotation cipher\n");
    printf("(6) Decryption of a day-1 provided block of cipher text encrypted with a substitution cipher\n");
    printf("(7) Decryption of a day-1 provided block of cipher text encrypted with a substitution cipher\n");
    printf("Selection: ");
    
    scanf("%d", &taskNumber);  //This reads the user's input
    // Write switch statements to ues input to select task.
    
    switch(taskNumber)
    {
        case 1: 
            printf("You have selected task (1).");
            //task1(); (somehow get task 1 to run)
            break;
        case 2:
            printf("You have selected task (2).");
            //task1(); (somehow get task 2 to run)
            break;
        case 3:
            printf("You have selected task (3).");
            //task1(); (somehow get task 3 to run)
            break;
        case 4:
            printf("You have selected task (4).");
            //task1(); (somehow get task 4 to run)
            break;
        case 5:
            printf("You have selected task (5).");
            //task1(); (somehow get task 5 to run)
            break;
        case 6:
            printf("You have selected task (6).");
            //task1(); (somehow get task 6 to run)
            break;
        case 7:
            printf("You have selected task (7).");
            //task1(); (somehow get task 7 to run)
            break;
        default: printf("Unknown option %d\nPlease enter 1, 2, 3, 4, 5, 6 or 7\n", taskNumber);
    }


char rotnEncryption(char* message)
{
    int rotnKey;//the key of encryption (the number of letters the unser decides to shift by)
    int index = 0;
    char encryptedletter; // the corresponding ASCII letter after rotation encryption calculation
    
    printf("Please enter a key (a number from 1 to 25) to shift the letters by: ");//the console asks the user to input a key
    scanf("%d", &rotnKey);//the user inputs a key
    
    //for loop that takes the message input by the user and reads it one character at a time until the terminating character '\0' is reached:
    for(message[index]; message[index] != '\0'; index ++)
    {
        if(message[index] == 32)//if the character entered is a space (ASCII number 32), it is not encrypted but still printed as a space
        {
            printf(" ");//print a space
        }
        else if(message[index] != 32)//this accounts for all other cases where the characters are not spaces
        {
            encryptedletter = ((message[index]-65) + rotnKey)%26 + 65;
            //the corresponding ASCII value of each character in the user's message is subtracted by 65, shifted by the given key then 65 id added
            printf("%c", encryptedletter);//each character of the message is printed after being encrypted
        }
    }   
}    


char rotnDecryption(char* rotnmessage)
{
    int rotnKey;//the key of encryption (the known number of characters the rotation cipher has been shifted by)
    int index = 0;
    char decryptedletter; // the corresponding ASCII letter after rotation encryption calculation
    
    printf("Please enter the key (a number from 1 to 25) that the letters have been shifted by: ");//the console asks the user to input a key
    scanf("%d", &rotnKey);//the user inputs the key
    
    //for loop that takes the encrypted message input by the user and reads it one character at a time until the terminating character '\0' is reached:
    for(rotnmessage[index]; rotnmessage[index] != '\0'; index ++)
    {
        if(rotnmessage[index] == 32)//if the character entered is a space (ASCII number 32), it is not encrypted but still printed as a space
            printf(" ");//prints original encrypted character
        else if(rotnmessage[index] == 65)
            printf("Y");
        else if(rotnmessage[index] == 66)
            printf("Z");
        else
        {
            decryptedletter = ((rotnmessage[index]-65) - rotnKey)%26 + 65;
            //the corresponding ASCII value of each character in the user's encrypted message is subtracted by 65, shifted by the given key then 65 is added
            printf("%c", decryptedletter);//each character of the message is printed after being decrypted
        }
    }   
}    

/*
Task 2: Decryption with a rotation cipher given cipher text and key

Task 3: Encryption with a substitution ciper given plain text and key

Task 4: Decryption with a substitution cipher given cipher text and key

Task 5: Decryption of a previously unseen cipher text encrypted with a rotation cipher

Task 6: Decryption of a day-1 provided block of cipher text encrypted with a substitution cipher

Task 7: Decryption of an unseen block of cipher text on marking day


 */

