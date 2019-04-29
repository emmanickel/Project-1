#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototypes:

void rotnEncryption(void);//Prototype for function called in task 1 for rotation encryption
void rotnDecryption(void);//Prototype for function called in task 2 for rotation decryption
void subnEncryption(void);//Prototype for function called in task 3 for substitution encryption
void subnDecryption(void);//Prototype for function called in task 4 for substitution decryption

int main()
{
    int taskNumber; // The variable containing the task number selected by the user
    FILE *taskSelection; // Declaration of file for user's selection of task
    
    /* Print a user friendly message if their is an error opening the file (avoids a segmentation fault if a NULL stream is accessed).*/
    if(taskSelection == NULL)
    {
    perror("fopen()");
    return;
    }

    /*User friendly menu system*/
    printf("User friendly menu system:\n\n");
    printf("    (1) Encryption with a rotation cipher given plain text and key\n"); //prints the description of each task to stdout
    printf("    (2) Decryption with a rotation cipher given cipher text and key\n");
    printf("    (3) Encryption with a substitution ciper given plain text and key\n");
    printf("    (4) Decryption with a substitution cipher given cipher text and key\n");
    printf("    (5) Decryption of a previously unseen cipher text encrypted with a rotation cipher\n");
    printf("    (6) Decryption of a day-1 provided block of cipher text encrypted with a substitution cipher\n");
    printf("    (7) Decryption of a day-1 provided block of cipher text encrypted with a substitution cipher\n\n");
    
    /*Prompt the user to select a task*/
    printf("Please select a task (1, 2, 3, 4, 5, 6 or 7) and enter your selection into 'taskSelection.txt'.\n\n");  

    /*File opens for the user to input their selection*/
    taskSelection = fopen("taskSelection.txt", "r");
    
    /*Print a user friendly message if their is an error opening the file (avoids a segmentation fault if a NULL stream is accessed)*/
    if(taskSelection == NULL)
    {
    perror("fopen()");
    return;
    }
   
    /*User inputs their selection into the file*/
    fscanf(taskSelection, "%d", &taskNumber);
    
    /*Switch statement directs task selected by the user to run*/
    switch(taskNumber)
    {
        case(1): 
            printf("You have selected task (1).");
            rotnEncryption(); // task 1 runs
            break;
        case(2):
            printf("You have selected task (2).");
            rotnDecryption(); // task 2 runs
            break;
        case(3):
            printf("You have selected task (3).");
            subnEncryption(); // task 3 runs
            break;
        case(4):
            printf("You have selected task (4).");
            subnDecryption(); // task 4 runs
            break;
        case(5):
            printf("You have selected task (5).");
            break;
        case(6):
            printf("You have selected task (6).");
            break;
        case(7):
            printf("You have selected task (7).");
            break;
        default: /*If the user enters an invalid task number, they are prompted to select again*/
            printf("Unknown option %d.\n\nPlease select a task (1, 2, 3, 4, 5, 6 or 7) and enter your selection into 'taskSelection.txt.\n\n", taskNumber);
            fscanf(taskSelection, "%d", &taskNumber);//Reads the user's input from file again
    }
}
    
//Function definitions:

//Task 1 (rotation encryption) function definition:

/*
– Inputs: The message entered by user (string) and key of rotation entered by the user (integer)
– Return value: There is no return value
– Purpose of function: To perform encryption with a rotation cipher given plain text and key
– Limitations: The message entered must be an array of chars less than 1025 characters in length. The key entered by the user needs to be
    an integer between 0 and 26 (0 and 26 result in no encryption)
*/

void rotnEncryption(void)
{
    char message[1024]; // The message to be encrypted entered by the user
    int rotnKey; // The key of encryption (the number of letters the unser decides to shift by)
    int index = 0; // Counter to be used in for loop during the encryption process
    char encryptedletter; // The corresponding ASCII letter after rotation encryption calculation
    
    FILE *enterMessage, *enterRotnKey; // Declaration of files to be used in this function
    
    /*Console prompts user to enter a message*/
    printf("\n\nEnter a message to encrypt (in capital letters) into the file 'message.txt'.\n");
  
    /*File opens for user to enter their selection*/
    enterMessage = fopen("enterMessage.txt", "r");
    
    /*Print a user friendly message if their is an error opening the file (avoids a segmentation fault if a NULL stream is accessed)*/
    if(enterMessage == NULL)
    {
        perror("fopen()");
        return;
    }
   
    /*Read the message entered by the user into the file*/
    fscanf(enterMessage, "%[^\n]", message);
    
    /*Print the message entered by the user*/
    printf("\nThe message entered was:\n\n%s\n\n", message);
    
    /*Prompt the user to enter a key of rotation into a file*/
    printf("Enter a key of rotation (an number from 1 to 25) into the file 'enterRotnKey.txt'.\n\n");
   
    /*File opens for user to input their chosen key*/
    enterRotnKey = fopen("enterRotnKey.txt", "r");
    
    /*Read the key entered by the user*/
    fscanf(enterRotnKey, "%d", &rotnKey);

    /*Print the key entered by the user to stdout*/
    printf("The key entered was %d.\n\n", rotnKey);
    
    printf("The encrypted message is: \n\n");
    
    /*The for loop below reads one character at a time of the message entered by the user until the terminating character
    '\0' is reached*/
    for(message[index]; message[index] != '\0'; index ++)
    {
        if(message[index] < 65 || (message[index] > 90 && message[index] < 97) || message[index] > 122) 

            /*If the ASCII character entered does not have a corresponding integer within the range assigned to letters,
            no encryption will take place*/
            printf("%c", message[index]); // The character entered by the user is printed unchanged
        
        else if(message[index] >= 65 || message[index] <= 90)
        {
            /*If the ASCII character entered does have a corresponding integer within the range assigned letters (both lowercase
            and capital), the letter is firstly converted into a capital if it is not already one*/
             if(message[index] > 96 && message[index] < 123) // Character is in the range of lowercase letters
                 message[index] = message[index] - 32; // Subraction of lowercase letter by 32 converts it to capital

            /*The characters of the message now within the ASCII range of capital letters are encrypted by the calculation below*/
            encryptedletter = ((message[index]-65) + rotnKey)%26 + 65;
            
            /*Explanation of calculation: 65 is subtracted from the assigned integer for each ASCII character to convert it to the form
            A=0, B=1, C=2 and so on. The integer values are then shifted by the key entered by the user. The modulus (remainder) when
            this value is divided by 26 is then taken. 65 is added to bring the integers back to the range of ASCII characters
            corresponding to capital letters*/
            
            printf("%c", encryptedletter); // Each encrypted character is printed to stdout
        }
    } 
}    

//Task 2 (rotation decription) function definition:

/*
– Inputs: The encrypted message entered by user (string) and key of rotation entered by the user (integer)
– Return value: There is no return value
– Purpose of function: To perform decryption with a rotation cipher given plain text and key
– Limitations: The encrypted message entered must be an array of chars less than 1025 characters in length.
    The key entered by the user needs to be an integer between 0 and 26 (0 and 26 result in no decryption)
*/

void rotnDecryption(void)
{
    char rotnmessage[1024]; // The encrypted message entered by the user
    int rotnKey; // The key of encryption (the known number of characters the rotation cipher has been shifted by)
    int index = 0; // The counter used in the for loop which allows the characters of the encrypted message to be read one at a time
    char decryptedletter; // The corresponding ASCII letter after rotation encryption calculation
    
    /*Declaration of files to be used in this function*/
    FILE *enterMessage, *enterRotnKey; 
    
    /*Prompt user to enter an encrypt message to decrypt*/
    printf("\n\nEnter an encrypted message to decrypt (in capital letters) into the file 'enterMessage.txt'.\n\n");//the console tells the user to input an encrypted message
   
    /*Open a file for user to enter their message*/
    enterMessage = fopen("enterMessage.txt", "r");
   
    /*Read message entered by user from file*/
    fscanf(enterMessage, "%[^\n]", rotnmessage);
    
    /*Print encrypted message entered by user to stdout*/
    printf("The encrypted message entered was:\n\n%s\n\n", rotnmessage);
    
    /*Prompt user to enter a key of rotation*/
    printf("Please enter the key (a number from 1 to 25) that the letters have been shifted by into the file 'enterRotnKey.txt'.\n\n");//the console asks the user to input a key
    
    /*File opens for user to enter their key*/
    enterRotnKey = fopen("enterRotnKey.txt", "r");
    
    /*Read key entered by user to file*/
    fscanf(enterRotnKey, "%d", &rotnKey);//the user inputs the key
    
    /*Print key entered by user to stdout*/
    printf("The key entered was %d.\n\n", rotnKey);
   
    printf("The decrypted message is:\n\n");
    
    /*The for loop below that takes the encrypted message entered by the user and reads it one character at a time until
    the terminating character '\0' is reached*/
    for(rotnmessage[index]; rotnmessage[index] != '\0'; index ++)
    {
        if(rotnmessage[index] < 65 || (rotnmessage[index] > 90 && rotnmessage[index] < 97) || rotnmessage[index] > 122) 
         { 
            
            /*if the ASCII character entered does not have a corresponding integer within the range assigned to letters,
            no decryption will take place*/ 
            
            printf("%c", rotnmessage[index]);//the character entered by the user is printed unchanged
        } 
        else if(rotnmessage[index] >= 65 || rotnmessage[index] <= 90)
        {
            /*If the ASCII character entered does have a corresponding integer within the range assigned letters (both lowercase
            and capital), the letter is firstly converted into a capital if it is not already one*/
            if(rotnmessage[index] > 96 && rotnmessage[index] < 123)
                 rotnmessage[index] = rotnmessage[index] - 32;
           
            /*The characters of the encrypted message now within the ASCII range of capital letters are decrypted by the calculation below*/
            decryptedletter = (rotnmessage[index] - 65 - rotnKey)%26 + 65;
            /*Explanation of calculation: 65 is subtracted from the assigned integer for each ASCII character to convert it to the form A=0, B=1, C=2 and so on.
            The integer values are shifted back by the key of decryption given by the user. The modulus (remainder) when this value is
            divided by 26 is then taken. 65 is added to bring the integers back to the range of ASCII characters corresponding to capital
            letters*/
            
            if(decryptedletter < 65)
                decryptedletter = decryptedletter + 26;
            /*if the character being decrypted holds a position in the alphabet of lower value than the selected key, the calculation
            will result in the decrypted character being outside (less than) the range of the capital letters. To resolve this, characters
            in this position have 26 added after the calculation to ensure they remain in the range (the rotation decryption 'wraps' around the
            alphabet)*/
            
            printf("%c", decryptedletter);// Each decrypted character is printed to the console one at time
        }
    }  
}    

//Task 3 (substitution encryption) function definition:

/*
– Inputs: The message entered by user (string) and key of substitution entered by the user (string)
– Return value: There is no return value
– Purpose of function: To perform encryption with a substitution cipher given plain text and key
– Limitations: The message entered must be an array of chars less than 1025 characters in length.
    The key entered by the user needs to be an array of 26 chars. It may contain repeats.
*/

void subnEncryption(void)
{
    char subalphabet[26]; // Array that will contain the key substitution alphabet entered as a string by the user
    char message[1024]; // Array that will contain the message entered by the user to be encrypted
    int index = 0; //integer value that will act as a counter for each character in the message entered by the user
    int subindex; // Integer value that will act as a counter for each character of the encrypted message
    char encryptedletter; // Encrypted character printed after the encryption calculation

    /*Declaration of files to be used in this function*/
    FILE *enterSubnKey, *enterMessage;

    /*Prompt user to enter a substitution key into a file*/
    printf("\n\nPlease enter a substitution (26 capital letters) into the file 'enterSubnKey.txt'.\n\n"); 
    
    /*File opens for user input*/
    enterSubnKey = fopen("enterSubnKey.txt", "r");
    
    /*Read key entered by user from file*/
    fscanf(enterSubnKey, "%s", subalphabet);
    
    /*Print key entered by user to stdout*/
    printf("The substitution key entered was:\n\n%s\n\n", subalphabet);
      
   //this set of if, else if statements ensures that the user enters a valid key (26 letters)
   /*if(subindex < 26 || subindex > 26)
   {
            printf("Error: too few or too many letters were entered. Please enter a substitution (26 capital letters):\n");//console asks user to enter substitution key
            scanf("%s", subalphabet);//user inputs a substitution key
   }
   if(subalphabet[index] < 65 || subalphabet[index] > 90)
   {
            printf("Error: the characters entered were not within the range of capital letters (A to Z). Please enter a substitution (26 capital letters):\n");
            //console asks user to enter substitution key
            scanf("%s", subalphabet);//user inputs a substitution key
   }
   else 
        continue;*/
    
    //if the user correctly enters 26 capital letters for the key, the program continues
   
    /*Prompt user to enter a message to be encrypted into a file*/
    printf("Please enter a message to encrypt into the file 'enterMessage.txt'.\n\n"); //console asks the user to enter a message to encrypt
    
    /*File opens for user input*/
    enterMessage = fopen("enterMessage.txt", "r");
    
    /*Read user input from file*/
    fscanf(enterMessage, "\n%[^\n]", message);
    
    /*Print message entered by user to stdout*/
    printf("The message entered was:\n\n%s\n\n", message);
    
    printf("The encrypted message is:\n\n");//the message is printed after this
    
    /*The for loop below reads one character at a time of the message entered by the user until the terminating character '\n' is reached*/
    for(message[index]; message[index] != '\0'; index ++)
    {
        /*Any character of the message that is not a letter is printed to stdout unchanged*/
        if(message[index] < 65 || (message[index] > 90 && message[index] < 97) || message[index] > 122) 
            printf("%c", message[index]);
            
        /*Characters of the message that are letters are encrypted*/                           
        else if(message[index] >= 65 || message[index] <= 90)
        {
            /*If the letter entered is lowercase, it is converted into a capital letter*/
            if(message[index] > 96 && message[index] < 123)
                 message[index] = message[index] - 32;
                 
            /*65 is then subtracted from the capital letters so they are shifted back to the form A=0, B=1, C=2 and so on.
            The corresponding integer value is assigned to 'subindex' (the counter for the substitution alphabet)*/
            subindex = message[index] - 65;
                  
            /*The encrypted letter is assigned to be the character of the key entered by the user corresponding to the counter
            'subindex'*/
            encryptedletter = subalphabet[subindex];
     
            /*The encrypted letter is printed to stdout*/
            printf("%c", encryptedletter);
        }
    }
}

//Task 4 (substitution decryption) function decryption:

/*
– Inputs: The encrypted message entered by user (string) and key of substitution entered by the user (string)
– Return value: There is no return value
– Purpose of function: To perform decryption with a substitution cipher given plain text and key
– Limitations: The encrypted message entered must be an array of chars less than 1025 characters in length.
    The key entered by the user needs to be an array of 26 chars. It may contain repeats.
*/

void subnDecryption(void)
{
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // An array of a string containing all capital letters in order
    char subalphabet[26]; // An array that will contain the substitution key entered by the user
    char submessage[1024]; // The encrypted message entered by the user
    int subindex = 0; // An integer value that acts as a counter of the encrypted message (used in the for loop)
    char decryptedletter; // The decrypted character determined after the substitution decryption calculation

    /*Declaration of files used in this function*/
    FILE *enterSubnKey, *enterMessage;
    
    /*Prompt user to enter a key of substitution*/
    printf("\n\nPlease enter a substitution (26 capital letters) into the file 'enterSubnKey.txt'.\n\n"); 
    
    /*File opens for user to enter key*/
    enterSubnKey = fopen("enterSubnKey.txt", "r");
   
    /*Read user input from file*/
    fscanf(enterSubnKey, "%s", subalphabet);
    
   //this set of if, else if statements ensures that the user enters a valid key (26 letters)
   /*if(subindex < 26 || subindex > 26)
   {
            printf("Error: too few or too many letters were entered. Please enter a substitution (26 capital letters):\n");//console asks user to enter substitution key
            scanf("%s", subalphabet);//user inputs a substitution key
   }
   if(subalphabet[index] < 65 || subalphabet[index] > 90)
   {
            printf("Error: the characters entered were not within the range of capital letters (A to Z). Please enter a substitution (26 capital letters):\n");
            //console asks user to enter substitution key
            scanf("%s", subalphabet);//user inputs a substitution key
   }
   else 
        continue;*/
   
   //if the user correctly enters 26 capital letters for the key, the program continues
   
    /*Print the key entered by the user to stdout*/
    printf("The substitution key entered was:\n\n%s\n\n", subalphabet);
   
    /*Prompt the user to enter an encrypted message to file*/
    printf("Please enter a message to decrypt into the file 'enterMessage.txt'.\n\n"); 
    
    /*File opens for user to enter encrypted message*/
    enterMessage = fopen("enterMessage.txt", "r");
    
    /*Read input by user from file*/
    fscanf(enterMessage, "%[^\n]", submessage);//user inputs a substitution key
    
    /*Print message entered by user to stdout*/
    printf("The message entered was:\n\n%s\n\n", submessage);
   
    printf("The decrypted message is:\n\n");//the decrypted message will be printed after thi
    
    /*The for loop below reads one character at a time of the encrypted message entered by the user until the terminating character
    '\n' is reached*/
    for(submessage[subindex]; submessage[subindex] != '\0'; subindex ++)
    {
        /*Any character of the message that is not a letter is printed to stdout unchanged*/
        if(submessage[subindex] < 65 || (submessage[subindex] > 90 && submessage[subindex] < 97) || submessage[subindex] > 122) 
            printf("%c", submessage[subindex]);
        
        /*Characters of the message that are letters are encrypted*/                           
        else if(submessage[subindex] >= 65 || submessage[subindex] <= 90)
        {
            /*If the letter entered is lowercase, it is converted into a capital letter*/
            if(submessage[subindex] > 96 && submessage[subindex] < 123)
                submessage[subindex] = submessage[subindex] - 32;

            /*The decrypted character is assigned to be the character in the alphabet corresponding to the counter 'subindex'*/
            decryptedletter = alphabet[subindex];
            
            /*The decrypted character is printed to stdout*/
            printf("%c", decryptedletter);
        }
    }
} 

//Task 5:Decryption with a substitution cipher given cipher text and key
/*File *stream;
while (!feof(stream))
{
    //read from file
    //do stuff

char rotnDecryption(void)
{
    char rotnmessage[1024]; //the encrypted message entered by the user
    int rotnKey;//the key of encryption (the known number of characters the rotation cipher has been shifted by)
    int index = 0;
    char decryptedletter; // the corresponding ASCII letter after rotation encryption calculation
    
    FILE *task5;
    task5 = fopen("task1.txt", "r");
    
    printf("Enter an encrypted message to decrypt (in capital letters):\n");//the console tells the user to input an encrypted message
    fscanf(task5, "%[^\n]", rotnmessage);//the user inputs the encrypted message
    
    //Figuring out the key:
//Method 1: Frequency of the letter 'e' (then t,a,o,i,n,,s,h,r,d,l,u...)
    //Assume most frequent character is 'e', then determine the shift from there.
//Method 2: Try all 26 possible rotations (brute force)
    //Method 2.5: Each word contains a vowel (or 'y') which narrows it down...
//Method 3: One letter word must be 'I' or 'a'
//Method 4: Known plaintext attack 
    //Using dictionary containing known words


    printf("The decrypted message is:\n");
    
    //for loop that takes the encrypted message input by the user and reads it one character at a time until the terminating character '\0' is reached:
    for(rotnmessage[index]; rotnmessage[index] != '\0'; index ++)
    {
        if(rotnmessage[index] < 65 || rotnmessage[index] > 90)
        { 
            
            if the ASCII character entered does not have a corresponding integer within the range assigned to capital letters,
            no decryption will take place 
           
            //return rotnmessage[index];//the character entered by the user is printed unchanged
      /*  } 
        else if(rotnmessage[index] >= 65 || rotnmessage[index] <= 90)
        {
            if the ASCII character entered does have a corresponding integer within the range assigned to capital letters,
            the character will be decrypted according to the shift entered by the user
            
           // decryptedletter = (rotnmessage[index] - 65 - rotnKey)%26 + 65;
            
            /*65 is subtracted from the assigned integer for each ASCII character to convert it to the form A=0, B=1, C=2 and so on.
            The integer values are shifted back by the key of encryption given by the user then the modulus (remainder) is taken.
            65 is added to bring the integers back to the range of ASCII characters corresponding to capital letters*/
            
            //if(decryptedletter < 65)
              //  decryptedletter = decryptedletter + 26;
            /*if the character being decrypted holds a position in the alphabet of lower value than the selected key, the calculation
            will result in the decrypted character being outside (less than) the range of the capital letters. To resolve this, characters
            in this position have 26 added after the calculation to ensure they remain in the range (the rotation decryption 'wraps' around the
            alphabet)*/
            
            //return decryptedletter;//each decrypted character is printed to the console
       // }
   // }   
//}    


//}

/*

Task 6: Decryption of a day-1 provided block of cipher text encrypted with a substitution cipher

Task 7: Decryption of an unseen block of cipher text on marking day


 */



