/*This code is an ecryption and decryption software that will work for a
rotation or substitution cipher*/
/*STEP 1:
You will read either a 0 or 1 from the user to choose 
Rotation of Substitution cipher*/
/*STEP 2:
You will read either a 0 or 1 from the user to choose
encryption or decryption
This will run the respective code and print
the encyption/decryption to the screen*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int firstchoice;
    int secondchoice;
    printf("Do you want Rotation cipher or Substitution cipher? Enter (0/1): "); 
    //This will decide whether the rotaion cipher or substitution cipher is run
    scanf("%d\n", &firstchoice);
    
    if (firstchoice==0) //This is the rotation chipher
    {
        printf("Do you want to encrypt of decrypt? Enter (0/1): ");  
        scanf("%d", &secondchoice);
        int x = secondchoice;
        if (x==0)
        {
            //runs encryption
            int k;
            printf("Enter encryption key: ");
            //This will determine how much the message is rotated
            scanf("%d\n", k);
            if (k < -25 || k > 25) //To make the maths easier
            {
                k/2;
            }
            
        }
        if (x==1)
        {
            //runs decryption
        }
        else printf("Unknown input");
    }
    if (firstchoice==1) //This is the Substitution cipher
    {
        printf("Do you want to encrypt of decrypt? Enter (0/1): ");  
        scanf("%d\n", &secondchoice);
        int x =secondchoice
        if (x==0)
        {
            //runs encryption
        }
        if (x==1)
        {
            //runs decryption
        }
        else printf("Unknown input");
    }
    else printf("Unknown input");
    return 0;
}

