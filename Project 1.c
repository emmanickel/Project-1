#include <stdio.h>

char encryptRotate(char str, int index);
int main()
{
   // int taskNumber;

//User friendly task selection menu system

    /*printf("Please select a task(1, 3, 4, 5, 6 or 7): \n"); // Asks user which task they would like performed
    printf("(1) Encryption with a rotation cipher given plain text and key\n");
    printf("(2) Decryption with a rotation cipher given cipher text and key\n");
    printf("(3) Encryption with a substitution ciper given plain text and key\n");
    printf("(4) Decryption with a substitution cipher given cipher text and key\n");
    printf("(5) Decryption of a previously unseen cipher text encrypted with a rotation cipher\n");
    printf("(6) Decryption of a day-1 provided block of cipher text encrypted with a substitution cipher\n");
    printf("(7) Decryption of a day-1 provided block of cipher text encrypted with a substitution cipher\n");
    printf("Selection: ");
    
    //scanf("%d", &taskNumber);  This reads the user's input. NB: scanf() doesn't work right now!
    // Write switch statements to ues input to select task.
    
    switch(taskNumber)
    {
        case 1: Task1(); break;
        case 2: Task2(); break;
        case 3: Task3(); break;
        case 4: Task4(); break;
        case 5: Task5(); break;
        case 6: Task6(); break;
        case 7: Task7(); break;
        default: printf("Unknown option %d\nPlease enter 1, 2, 3, 4, 5, 6 or 7\n", taskNumber);
    }*/
    


/*Project Planning:

Task 1: Encryption with a rotation cipher given plain text and key
- Input message to encrypt
- Input key
- Encrypt text
- Print encrypted text*/

    //int rotateKey = 5; /*This is the key of encryption - the number of letters by which the alphabet is rotated to
                         //calculate the substitution (temporarily hardcoded to 5 at the moment without scanf)*/
    char str[1024] = "Hello"; //This initialises the user's input as a string. Should it be a constant?? Temporarily hardcoded

    printf("Please enter a message to encrypt:\n");
    //scanf("%s\n", str); // Note: NO & REQUIRED! The user's message is entered as a string
    //Note: Need to use uppercase letters only, and all white space, punctuation and numerals need to be ignored.
    
    printf("Please enter a key to shift the letters by: ");
    //scanf("%d, &rotateKey");
    
    printf("Encrypted message is: ");
    printf("%s", str);
    
}

    char encryptRotate(char str, int index) //Index is the ASCII value of a letter a given time
    {
        int rotateKey = 5;
    
        for(index = 65; (index < 100 && index != 0); index++)
        {
            str[index] = (str[index] + rotateKey); // Encryption calculation
            return str;
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

