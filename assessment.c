#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Rotcipher(char input);
char Subcipher(char input);

int main()
{
    int firstchoice;
    int secondchoice;
    printf("Do you want Rotation cipher or Substitution cipher? Enter (0/1): "); 
    scanf("%d\n", &firstchoice);
    if (firstchoice==0)
    {
        printf("Do you want to encrypt of decrypt? (0/1): ");  
        int x = scanf("%d", &secondchoice);
        if (x==0)
        {
            //run encryption
        }
        if (x==1)
        {
            //run decryption
        }
        else printf("Unknown input");
    }
    if (firstchoice==1)
    {
        printf("Do you want to encrypt of decrypt? (0/1): ");  
        int x = scanf("%d\n", &secondchoice);
        if (x==0)
        {
            //run encryption
        }
        if (x==1)
        {
            //run decryption
        }
        else printf("Unknown input");
    }
    else printf("Unknown input");
    return 0;
}

