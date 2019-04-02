#include <stdio.h>



int main()
{
int firstchoice;
int secondchoice;
printf("Do you want Rotation cipher or Substitution cipher? (0/1): %d\n");
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

