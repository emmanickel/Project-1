#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototypes:

char rotnEncryption(void);//This function is called in task 1 for rotation encryption
char rotnDecryption(void);//This function is called in task 2 for rotation decryption
char subnEncryption(void);//This function is called in task 3 for substitution encryption
char subnDecryption(void);//This function is called in task 4 for substitution decryption

int main()
{
//int taskNumber; // The variable containing the task number selected by the user
    
    FILE *taskSelection; // Declaration of file for user's selection of task
    
    /*Print a user friendly message if their is an error opening the file.
    This avoids a segmentation fault occurring in attempting to access a NULL stream.
    if(taskSelection == NULL)
    {
    perror("fopen()");
    return;
    }*/

    /*User friendly menu system*/
    printf("User friendly menu system:\n");
    printf("    (1) Encryption with a rotation cipher given plain text and key\n"); //prints the description of each task to stdout
    printf("    (2) Decryption with a rotation cipher given cipher text and key\n");
    printf("    (3) Encryption with a substitution ciper given plain text and key\n");
    printf("    (4) Decryption with a substitution cipher given cipher text and key\n");
    printf("    (5) Decryption of a previously unseen cipher text encrypted with a rotation cipher\n");
    printf("    (6) Decryption of a day-1 provided block of cipher text encrypted with a substitution cipher\n");
    printf("    (7) Decryption of a day-1 provided block of cipher text encrypted with a substitution cipher\n\n");
    
    /*Prompt the user to select a task*/
    printf("Please select a task (1, 2, 3, 4, 5, 6 or 7). Please enter your selection into 'menusystemfile.txt'.\n\n");  

    /*Open a file for the user to input selection*/
    taskSelection = fopen("taskSelection.txt", "r");
    int taskNumber;
    
    /*Check file has opened correctly*/
    /*Print a user friendly message if their is an error opening the file.
    This avoids a segmentation fault occurring in attempting to access a NULL stream.
    if(taskSelection == NULL)
    {
    perror("fopen()");
    return;
    }*/
   
    /*User inputs their selection*/
    fscanf(taskSelection, "%d", &taskNumber);
  
    //If the user selects an invalid task, they are prompted to select again
    /*if(taskNumber < 1 || taskNumber > 7)
    {
        printf("Unknown option %d.\nPlease select a task (1, 2, 3, 4, 5, 6 or 7). Please enter your selection into 'menusystemfile.txt: ", taskNumber);
        
        fscanf(taskSelection, "%d", &taskNumber);//Reads the user's input again
    }*/


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
    
    }
    
    fclose(taskSelection);

}
    
//Function definitions:

//Task 1 (rotation encryption) function definition:

char rotnEncryption(void)
{
    char message[1024]; //the message entered by the user
    //int rotnKey;//the key of encryption (the number of letters the unser decides to shift by)
    int index = 0;
    char encryptedletter; // the corresponding ASCII letter after rotation encryption calculation
    
    FILE *enterMessage, *enterRotnKey;
    
    printf("\n\nEnter a message to encrypt (in capital letters) into the file 'message.txt'.\n");//the console tells the user to input a message
  
    enterMessage = fopen("enterMessage.txt", "r");
    
    /*if(enterMessage == NULL)
    {
        perror("fopen()");
        return;
    }*/
   
    //char message[1024]; //the message entered by the user
   
    fscanf(enterMessage, "%[^\n]", message);//the user inputs a message
    
    //fclose(enterMessage);
    
    printf("\nThe message entered was:\n\n%s\n\n", message);

    printf(" Enter a key of rotation into the file 'enterRotnKey.txt'.\n\n");
     
    //fclose(enterMessage);
     
    enterRotnKey = fopen("enterRotnKey.txt", "r");
    
    int rotnKey;//the key of encryption (the number of letters the unser decides to shift by)
    
    fscanf(enterRotnKey, "%d", &rotnKey);//the user inputs a key

    //fclose(enterRotnKey);

    printf("The key entered was %d.\n\n", rotnKey);
    
    printf("The encrypted message is: \n\n");
    
    //the following for loop takes the message input by the user and reads it one character at a time until the terminating character '\0' is reached:
    for(message[index]; message[index] != '\0'; index ++)
    {
        if(message[index] < 65 || message[index] > 90) 
        
            /*if the ASCII character entered does not have a corresponding integer within the range assigned to capital letters,
            no encryption will take place*/ 
            
             printf("%c", message[index]);//the character entered by the user is printed unchanged
        
        else if(message[index] >= 65 || message[index] <= 90)
        {
            /*if the ASCII character entered does have a corresponding integer within the range assigned to capital letters,
            the character will be encrypted according to the shift entered by the user*/
            
            encryptedletter = ((message[index]-65) + rotnKey)%26 + 65;
            
            /*65 is subtracted from the assigned integer for each ASCII character to convert it to the form A=0, B=1, C=2 and so on.
            The integer values are shifted by the key entered by the user then the modulus (remainder) is taken. 65 is added to bring the integers back to the range of ASCII characters
            corresponding to capital letters*/
            
            printf("%c", encryptedletter);//each character of the encrypted message is printed
        }
    } 
}    

//Task 2 (rotation decription) function definition:

char rotnDecryption(void)
{
    char rotnmessage[1024]; //the encrypted message entered by the user
    int rotnKey;//the key of encryption (the known number of characters the rotation cipher has been shifted by)
    int index = 0;
    char decryptedletter; // the corresponding ASCII letter after rotation encryption calculation
    
    FILE *enterMessage, *enterRotnKey;
        
    printf(" Enter an encrypted message to decrypt (in capital letters) into the file 'enterMessage.txt'.\n\n");//the console tells the user to input an encrypted message
   
   enterMessage = fopen("enterMessage.txt", "r");
   
   fscanf(enterMessage, "%[^\n]", rotnmessage);//the user inputs the encrypted message
    
    printf("The encrypted message entered was:\n\n%s\n\n", rotnmessage);
    
    printf("Please enter the key (a number from 1 to 25) that the letters have been shifted by into the file 'enterRotnKey.txt'.\n\n");//the console asks the user to input a key
    
    enterRotnKey = fopen("enterRotnKey.txt", "r");
    
    fscanf(enterRotnKey, "%d", &rotnKey);//the user inputs the key
    
    printf("The key entered was %d.\n\n", rotnKey);
   
   printf("The decrypted message is:\n\n");
    
    //for loop that takes the encrypted message input by the user and reads it one character at a time until the terminating character '\0' is reached:
    for(rotnmessage[index]; rotnmessage[index] != '\0'; index ++)
    {
        if(rotnmessage[index] < 65 || rotnmessage[index] > 90)
        { 
            
            /*if the ASCII character entered does not have a corresponding integer within the range assigned to capital letters,
            no decryption will take place*/ 
            
             printf("%c", rotnmessage[index]);//the character entered by the user is printed unchanged
        } 
        else if(rotnmessage[index] >= 65 || rotnmessage[index] <= 90)
        {
            /*if the ASCII character entered does have a corresponding integer within the range assigned to capital letters,
            the character will be decrypted according to the shift entered by the user*/
            
            decryptedletter = (rotnmessage[index] - 65 - rotnKey)%26 + 65;
            
            /*65 is subtracted from the assigned integer for each ASCII character to convert it to the form A=0, B=1, C=2 and so on.
            The integer values are shifted back by the key of encryption given by the user then the modulus (remainder) is taken.
            65 is added to bring the integers back to the range of ASCII characters corresponding to capital letters*/
            
            if(decryptedletter < 65)
                decryptedletter = decryptedletter + 26;
            /*if the character being decrypted holds a position in the alphabet of lower value than the selected key, the calculation
            will result in the decrypted character being outside (less than) the range of the capital letters. To resolve this, characters
            in this position have 26 added after the calculation to ensure they remain in the range (the rotation decryption 'wraps' around the
            alphabet)*/
            
            printf("%c", decryptedletter);//each decrypted character is printed to the console
        }
    }  
}    

//Task 3 (substitution encryption) function definition:

char subnEncryption(void)
{
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//array of a string containing all capital letters of the alphabet in order
    char subalphabet[26];//array that will contain the key substitution alphabet entered as a string by the user
    char message[1024];//array that will contain the message entered by the user to be encrypted
    int subindex;//integer value that will act as a counter for the subalphabet array
    int index = 0;//integer value that will act as a counter for each character in the message entered by the user
    char encryptedletter;//new character printed after encryption

    FILE *enterSubnKey, *enterMessage;

    printf("\n\nPlease enter a substitution (26 capital letters) into the file 'enterSubnKey'.\n\n"); //console asks user to enter substitution key
    
    enterSubnKey = fopen("enterSubnKey.txt", "r");
    
    fscanf(enterSubnKey, "%s", subalphabet);//user inputs a substitution key
    
    printf("The substitution key entered was:\n\n%s\n\n", subalphabet);
    
    //subalphabet[subindex];//declaration that subindex is the 'counter' for subalphabet
    
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
   
    printf("Please enter a message to encrypt into the file 'enterMessage.txt'.\n\n"); //console asks the user to enter a message to encrypt
    
    enterMessage = fopen("enterMessage.txt", "r");
    
    fscanf(enterMessage, "\n%[^\n]", message);//user inputs a message to encrypt
    
    printf("The message entered was:\n\n%s\n\n", message);
    
    printf("The encrypted message is:\n\n");//the encrypted message is printed after this
    
    //encryption:
    for(message[index]; message[index] != '\0'; index ++)
    {
        if(message[index] < 65 || message[index] > 90)
        printf("%c", message[index]);//characters outside the ASCII integer range of capital letters are not encrypted
                                    
        else if(message[index] >= 65 || message[index] <= 90)//characters in the range of capital letters are encrypted
        {
            subindex = message[index] - 65;
            /*65 is substracted from the first character in the message to bring it back to the form A=0, B=1, C=2 and so on.
            This integer value is assigned to subindex (the counter for the substitution alphabet)*/
            encryptedletter = subalphabet[subindex];
            /*The character of subalphabet corresponding to the 'counter' subindex is assigned to the encrypted letter*/
            printf("%c", encryptedletter);//the encrypted letter is printed to the console
        }//this process continues for each character in the message entered by the user until the termintating character is reached
    }
}

//Task 4 (substitution decryption) function decryption:

char subnDecryption(void)
{
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//An array of a string containing all of the capital letters in order
    char subalphabet[26];//An array that will contain the substitution key entered by the user
    char submessage[1024];//The message encrypted with a substitution cipher entered by the user
    int subindex = 0;//A counter for each character of the encrypted message, used in the for loop
    char decryptedletter;//The decrypted character determined after substitution decryption

    FILE *task4;
    task4 = fopen("task1.txt", "r");

    printf("Please enter a substitution (26 capital letters):\n"); //console asks user to enter substitution keyprintf("\nPlease enter a message to encrypt:"); //console asks the user to enter a message to encrypt
    printf("\nPlease enter a message to encrypt:"); //console asks the user to enter a message to encrypt
    fscanf(task4, "%s", subalphabet);//user inputs a substitution key
    
    //subalphabet[subindex];
    
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
   
    printf("\nPlease enter a message to decrypt:"); //console asks the user to enter a message to decrypt
    fscanf(task4, "\n%[^\n]", submessage);//user inputs a message to decrypt
    
    printf("The decrypted message is: \n");//the decrypted message will be printed after this
    
    for(submessage[subindex]; submessage[subindex] != '\0'; subindex ++)
    {
        if(submessage[subindex] < 65 || submessage[subindex] > 90)
        return submessage[subindex];
        /*Characters outside the range of capital letters are printed unchanged
        (no decryption necessary)*/
        
        else if(submessage[subindex] >= 65 || submessage[subindex] <= 90)
        /*characters within the range of capital letters require decryption*/
        {
            decryptedletter = alphabet[subindex];
            /*The character of the ordered alphabet corresponding to the 
            oucounter subindex is assigned to be the decrypted character*/
            
            return decryptedletter;//The decrypted character is printed to the console
        }
        /*This process continues through all the characters of the encrypted message until
        the terminating character '\0' is reached and the full decrypted message has been 
        printed to the console.*/
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
    //Using dictionary containting known words


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
Task 2: Decryption with a rotation cipher given cipher text and key

Task 3: Encryption with a substitution cipher given plain text and key

Task 4: Decryption with a substitution cipher given cipher text and key

Task 5: Decryption of a previously unseen cipher text encrypted with a rotation cipher

Task 6: Decryption of a day-1 provided block of cipher text encrypted with a substitution cipher

Task 7: Decryption of an unseen block of cipher text on marking day


 */



