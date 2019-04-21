/*This code is an ecryption and decryption software that will work for a
rotation or substitution cipher*/
/*STEP 1:
Type a meesage to the notepad file on desktop
it doesnt matter whether it needs to be 
encrypted or decrypted
However this message must be in 'ALL CAPS'*/
/*STEP 2:
The compiler will read either a 0 or 1 from the user to choose 
Rotation of Substitution cipher*/
/*STEP 3:
the compiler will read either a 0 or 1 from the user to choose
encryption or decryption
This will run the respective code and print
the encyption/decryption to the screen*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*Not all of these libraries are used but i have included them incase
i wanted to make adjustments to my code*/


int main()
{
    int firstchoice;
    int secondchoice;
    int thirdchoice;
    printf("Do you want Rotation cipher or Substitution cipher? Enter (0/1): "); 
    //This will decide whether the rotaion cipher or substitution cipher is run
    scanf("%d", &firstchoice);
    
    if (firstchoice==0) //This is the Rotation chipher
    {
        printf("Do you want to encrypt of decrypt? Enter (0/1): ");  
        scanf("%d", &secondchoice);
        if (secondchoice == 0) //runs encryption
        {
            int k;
            printf("Enter encryption key [0 to 26]: ");
            //This will determine how much the message is rotated
            scanf("%d", &k);
            FILE *input;
            input = fopen("input.txt", "r");
            //Will read from the file data.txt
            if(input == NULL) 
            {
                perror("fopen()");
                return 0;
                //This is a safety net incase its reads from the file incorrectly
            }
            while (feof(input) == 0)
            {
                char c;
                fscanf(input, "%c", &c);
                if ( (c+k) >= 'A' && (c+k) <= 'Z')
                {
                    c = c+k;
                }
                printf("%c\n", c);
            }
            printf("\n");
        }
        if (secondchoice == 1)//runs decryption
        {
            printf("Is encryption key known? yes/no (0 or 1): ");
            //note key can only be between 0 and 26
            scanf("%d", &thirdchoice);
            if (thirdchoice == 0)
            {
                int k;
                printf("Enter encryption key [0-26]: ");
                scanf("%d", &k);
                FILE *input;
                input = fopen("input.txt", "r");
                //Will read from the file data.txt
                if(input == NULL) 
                {
                    perror("fopen()");
                    return 0;
                    //This is a safety net incase its reads from the file incorrectly
                }
                while (feof(input) == 0)
                {
                    char c;
                    fscanf(input, "%c", &c);
                    if (c >= 'A' && c <= 'Z')
                    {
                        c = (c-k);
                        if (c < 'A')
                        {
                            c += 26;
                        }
                    }
                    printf("%c", c); 
                }
                printf("\n");
            }    
            if (thirdchoice == 1)
            {
                int d, x; //d is the difference between some letter either
                //'I' or 'A'
                FILE *input;
                input = fopen("input.txt", "r");
                if(input == NULL) 
                {
                    perror("fopen()");
                    return 0;
                }
                    while (feof(input) == 0)
                    {
                        char letter[500]; 
                        char fgets(char *letter, int, FILE *input);
                        char c;
                        fscanf(input, "%c", &c);
                        x = letter[500];
                        c = c - d;
                        if (c < 'A')
                        {
                            c += 26;
                        }
                        printf("%c", c); 
                    }
                printf("\n");
            }
            if (thirdchoice != 0 && thirdchoice != 1)
            {
                printf("Unknown input\n");
            }
        }
        if (secondchoice != 0 && secondchoice != 1)
        {
            printf("Unknown input\n");
        }
    }

    if (firstchoice==1) //This is the Substitution cipher
    {
        printf("Do you want to encrypt of decrypt? Enter (0/1): ");  
        scanf("%d", &secondchoice);
        if (secondchoice == 0) //runs encryption
        {
            
        }
        if (secondchoice == 1) //runs decryption
        {

        }
    }
    
    if (firstchoice != 0 && firstchoice != 1)
    {
        printf("Unknown input\n");
    }
    return 0;
}

